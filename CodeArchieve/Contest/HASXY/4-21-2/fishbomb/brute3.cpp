#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#define lch (o << 1)
#define rch ((o<<1)|1)
//#define DBG
typedef long long ll;
const int N = 100010;
int n, k, h[N], c[N];
const int V = N << 2;
int sk[N], sz, range[N][2];
ll ad[V], mx[V];
void mkad(int o, ll v) {if (o) mx[o] += v, ad[o] += v;}
void down(int o) {if (o) mkad(lch, ad[o]), mkad(rch, ad[o]), ad[o] = 0;}
void add(int o, int l, int r, int q1, int q2, ll q3) {
	if (q1 <= l && r <= q2) mkad(o, q3);
	else {
		down(o);
		int mid = (l + r)>>1;
		if (q1 <= mid) add(lch, l, mid, q1, q2, q3);
		if (mid < q2) add(rch, mid + 1, r, q1, q2, q3);
		mx[o] = std::max(mx[lch], mx[rch]);
	}
}
ll query(int o, int l, int r, int q1, int q2) {
	if (q1 <= l && r <= q2) return mx[o];
	else {
		down(o);
		int mid = (l + r)>>1;
		ll ret = 0;
		if (q1 <= mid) ret = std::max(ret, query(lch, l, mid, q1, q2));
		if (mid < q2) ret = std::max(ret, query(rch, mid + 1, r, q1, q2));
		return ret;
	}
}
namespace Kone {
ll solver() {
	for (int i = 1; i <= n; i++) add(1, 1, n, range[i][0], range[i][1], c[i]);
	ll ans = mx[1];
	for (int i = 1; i <= n; i++) {
		add(1, 1, n, range[i][0], range[i][1], -c[i]);
		ans = std::min(ans, mx[1]);
		add(1, 1, n, range[i][0], range[i][1], c[i]);
	}
	return ans;
}
}
namespace Brute {
ll ans;
bool del[N];
void dfs(int al) {
	if (clock()*10/CLOCKS_PER_SEC > 9) {
		printf("%lld\n", ans);
		exit(0);
	}
	if (al > k) return;
	ans = std::min(ans, mx[1]);
	for (int i = 1; i <= n; i++) if (!del[i] && query(1, 1, n, range[i][0], range[i][1]) == mx[1]) {
		del[i] = 1;
		add(1, 1, n, range[i][0], range[i][1], -c[i]);
		dfs(al + 1);
		add(1, 1, n, range[i][0], range[i][1], c[i]);
		del[i] = 0;
	}
}
ll solver() {
	ans = Kone::solver();
	dfs(0);
	return ans;
}
}

int main() {
	freopen("fishbomb.in", "r", stdin);
	freopen("fishbomb.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d%d", h + i, c + i);
	for (int i = 1; i <= n; i++) {
		while (sz && h[sk[sz]] < h[i]) sz--;
		if (sz && h[sk[sz]] == h[i]) sz--;
		range[i][0] = sz ? sk[sz] + 1 : 1;
		sk[++sz] = i;
	}
	sz = 0;
	for (int i = n; i; i--) {
		while (sz && h[sk[sz]] < h[i]) sz--;
		if (sz && h[sk[sz]] == h[i]) sz--;
		range[i][1] = sz ? sk[sz] - 1 : n;
		sk[++sz] = i;
	}
	printf("%lld\n", k == 1 ? Kone::solver() : Brute::solver());
}
