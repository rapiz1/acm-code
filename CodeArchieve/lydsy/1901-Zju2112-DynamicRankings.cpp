#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
const int N = 2e5 + 10;
int n, m, ans[N], out, a[N], tot;
char buf[3];
struct Cmd{
	int id, type, x, y, z;
}op[N], t1[N], t2[N];
namespace Bit {
	int sz, st[N << 1], a[N];
	inline int lowbit(int p) {return p&-p;}
	void add(int p, int v) {
		st[++sz] = p;
		for(;p <= n;p+=lowbit(p)) a[p] += v;
	}
	inline int sum(int p) {
		int ret = 0;
		for (;p;p -= lowbit(p)) ret += a[p];
		return ret;
	}
	inline int sum(int l, int r) {return sum(r) - sum(l - 1);}
	inline void clear() {
		for (;sz;sz--)
			for (int p = st[sz]; p <= n; p += lowbit(p)) a[p] = 0;
	}
}
void solve(int l, int r, int ll, int rr) {
	if (l > r) return;
	if (ll == rr) {
		for (;l<=r;l++) if (!op[l].type) ans[op[l].id] = ll;
		return;
	}
	int i = 0, j = 0, mid = (ll + rr) >> 1;
	for (int k = l; k <= r; k++) 
		if (op[k].type == 1 || op[k].type == 2) {
			int f = op[k].type == 1 ? 1 : -1;
			if (op[k].y <= mid) t1[i++] = op[k], Bit::add(op[k].x, f*(op[k].y <= mid));
			else t2[j++] = op[k];
		}
		else {
			int ret;
			if ((ret = Bit::sum(op[k].x, op[k].y)) < op[k].z) op[k].z -= ret, t2[j++] = op[k];
			else t1[i++] = op[k];
		}
	memcpy(op + l, t1, i*sizeof(Cmd));
	memcpy(op + l + i, t2, j*sizeof(Cmd));
	Bit::clear();
	solve(l, l + i - 1, ll, mid), solve(l + i, r, mid + 1, rr);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	int mxv = 0;
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), op[i] = (Cmd){0, 1, i, x, 0}, mxv = std::max(mxv, x), a[i] = x;
	tot = n;
	for (int i = 1; i <= m; i++) {
		int x, y, z = 0;
		scanf("%s%d%d", buf, &x, &y);
		if (buf[0] == 'Q') scanf("%d", &z), ++out;
		else {
			op[++tot] = (Cmd){out, 2, x, a[x], 0};
			mxv = std::max(mxv, y);
			a[x] = y;
		}
		op[++tot] = (Cmd){out, buf[0] == 'C', x, y, z};
	}
	solve(1, tot, 0, mxv);
	for (int i = 1; i <= out; i++) printf("%d\n", ans[i]);
}

