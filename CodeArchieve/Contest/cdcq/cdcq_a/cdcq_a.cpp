#include <cstdio>
#include <cstring>
#include <cctype>
#define mid ((l + r)>>1)
#define file(x) "cdcq_a."#x
typedef long long ll;
const int N = 50010, V = N << 2;
int n, m, out;
ll ans[V];
char buf[2];
namespace Bit {
	ll a[V], b[V];
	inline int lowbit(int x) {return x&-x;}
	inline void add(int idx, ll v) {
		for (int p = idx; p <= n; p+=lowbit(p)) a[p] += v, b[p] += v*idx;
	}
	inline void add(int l, int r, ll v) {add(l, v), add(r + 1, -v);}
	inline ll query(int idx) {
		ll ret = 0;
		for (int p = idx;p;p-=lowbit(p)) ret += a[p]*(idx + 1) - b[p];
		return ret;
	}
	inline ll query(int l, int r) {return query(r) - query(l - 1);}
}
using Bit::add;
using Bit::query;
struct cmd {
	int x, t, l1, r1, v1, l2, r2, v2, id;
	inline void rd() {
		scanf("%s", buf);
		if (buf[0] == 'M') scanf("%d%d%d%d%d%d", &l1, &r1, &v1, &l2, &r2, &v2);
		else scanf("%d%d", &l1, &r1), id = ++out;
		scanf("%d", &t);
		x = buf[0] == 'M';
	}
	inline void aply(int rev = 0) {
		rev = rev ? -1 : 1;
		if (x == 1) add(l1, r1, rev*-v1), add(l2, r2, rev*v2);
		else ans[id] += query(l1, r1);
	}
}op[N<<1], tmp[N<<1];
void solve(int l, int r) {
	if (l == r) return;
	solve(l, mid), solve(mid + 1, r);
	for (int i = l, ll = l, rr = mid + 1; ll <= mid || rr <= r; i++) {
		if (ll > mid || (rr <= r && op[rr].t < op[ll].t)) {
			if (op[rr].x == 0) op[rr].aply();
		 	tmp[i] = op[rr++];
		}
		else {
			if (op[ll].x == 1) op[ll].aply();
			tmp[i] = op[ll++];
		}
	}
	for (int i = l; i <= mid; i++) if (op[i].x == 1) op[i].aply(1);
	for (int i = l; i <= r; i++) op[i] = tmp[i];
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		op[i].x = 1, op[i].l2 = op[i].r2 = i, op[i].v2 = x;
		op[i].t = -1;
		op[i].l1 = op[i].r1 = 1;
	}
	for (int i = 1; i <= m; i++) op[n + i].rd();
	solve(1, n + m);
	for (int i = 1; i <= out; i++) printf("%lld\n", ans[i]);
}
