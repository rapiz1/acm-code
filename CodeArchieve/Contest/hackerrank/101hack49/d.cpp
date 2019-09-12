#include <cstdio>
#include <utility>
#define lch (o<<1)
#define rch (o<<1|1)
#define mid ((l + r)>>1)
typedef long long ll;
typedef std::pair<int, int> pa;
const int N = 1e5 + 10, V = N << 2, MOD = 1e9 + 7;
int qpow(int x, int r) {
	x %= MOD;
	if (!x) return 0;
	int ret = 1;
	while (r) {
		if (r&1) ret = (ll)ret*x%MOD;
		x = (ll)x*x%MOD, r >>= 1;
	}
	return ret;
}
int n, q, be[V], a[N];
pa prod[V];
pa merge(pa a, pa b) {
	pa c;
	c.first = (ll)a.first*b.first%MOD;
	c.second = (ll)a.second*b.second%MOD;
	return c;
}
inline void up(int o) {prod[o] = merge(prod[lch], prod[rch]);}
inline void mkbe(int o, int l, int r, int x) {
	prod[o].first = qpow(x, r - l + 1);
	prod[o].second = qpow(x - 1, r - l + 1);
	be[o] = x;
}
inline void down(int o, int l, int r) {
	if (be[o]) mkbe(lch, l, mid, be[o]), mkbe(rch, mid + 1, r, be[o]), be[o] = 0;
}
void build(int o, int l, int r) {
	if (l == r) prod[o].first = a[l], prod[o].second = a[l] - 1;
	else {
		build(lch, l, mid);
		build(rch, mid + 1, r);
		up(o);
	}
	//printf("(%d)[%d, %d]: %d %d\n", o, l, r, prod[o].first, prod[o].second);
}
void change(int o, int l, int r, int q1, int q2, int q3) {
	if (q1 <= l && r <= q2) {mkbe(o, l, r, q3);return;}
	down(o, l, r);
	if (q1 <= mid) change(lch, l, mid, q1, q2, q3);
	if (mid < q2) change(rch, mid + 1, r, q1, q2, q3);
	up(o);
}
pa query(int o, int l, int r, int q1, int q2) {
	if (q1 <= l && r <= q2) return prod[o];
	down(o, l, r);
	pa ret = std::make_pair(1, 1);
	if (q1 <= mid) ret = merge(query(lch, l, mid, q1, q2), ret);
	if (mid < q2) ret = merge(query(rch, mid + 1, r, q1, q2), ret);
	//printf("[%d, %d]: %d %d\n", l, r, ret.first, ret.second);
	return ret;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	build(1, 1, n);
	while (q--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			change(1, 1, n, l, r, x);
		}
		else {
			pa ret = query(1, 1, n, l, r);
			printf("%d\n", (ret.first - ret.second + MOD)%MOD);
		}
	}
}
