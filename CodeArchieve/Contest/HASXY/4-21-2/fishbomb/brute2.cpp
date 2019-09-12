#include <cstdio>
#include <algorithm>
#include <vector>
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
/*
int ID;
void gid(int o, int l, int r) {
	if (l == r) if (mx[o] == mx[1]) ID = o;else;
	else {
		int mid = (l + r)/2;
		gid(lch, l, mid), gid(rch, mid + 1, r);
	}
}
*/
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
ll s[N], mid, l, r;
bool dfs(int p, int al) {
	if (al > k) return 0;
	if (p > n) return mx[1] <= mid;
	if (mx[1] <= mid) return 1;
	int ret;
	if (query(1, 1, n, range[p][0], range[p][1]) > mid) {
		add(1, 1, n, range[p][0], range[p][1], -c[p]);
		ret = dfs(p + 1, al + 1);
		add(1, 1, n, range[p][0], range[p][1], c[p]);
		if (ret) return 1;
	}
	ret = dfs(p + 1, al);
	if (ret) return 1;
	return 0;
}
ll solver() {
	r = Kone::solver();
	while (l < r) {
		mid = (l + r)/2;
		printf("%lld\n", mid);
		if (dfs(1, 0)) r = mid;
		else l = mid + 1;
	}
	return l;
}
}

int main() {
	freopen("fishbomb.in", "r", stdin);
//	freopen("fishbomb.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d%d", h + i, c + i);
	for (int i = 1; i <= n; i++) {
		int x = i;
		while (sz && h[sk[sz]] < h[i]) x = sk[sz--];
		if (sz && h[sk[sz]] == h[i]) x = sk[sz--];
		sk[++sz] = i;
		range[i][0] = x;
	}
	sz = 0;
	for (int i = n; i; i--) {
		int x = i;
		while (sz && h[sk[sz]] < h[i]) x = sk[sz--];
		if (sz && h[sk[sz]] == h[i]) x = sk[sz--];
		sk[++sz] = i;
		range[i][1] = x;
	}
	printf("%lld\n", k == 1 ? Kone::solver() : Brute::solver());
}
