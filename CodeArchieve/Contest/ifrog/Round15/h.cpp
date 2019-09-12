#include <cstdio>
#include <algorithm>
#include <cstring>
#define lch (o<<1)
#define rch ((o<<1)|1)
#define mid ((l + r)>>1)
const int N = 1e5 + 10, V = 4e5 + 10;
typedef long long ll;
int n, a[N];
ll mx[V], ad[V];
int q1, q2, q3;
inline void mkad(int o, ll v) {
	if (o) mx[o] += v, ad[o] += v;
}
inline void up(int o) {mx[o] = std::max(mx[lch], mx[rch]);}
inline void down(int o) {
	if (ad[o]) mkad(lch, ad[o]), mkad(rch, ad[o]), ad[o] = 0;
}
int build(int o, int l, int r) {
	if (l == r) return mx[o] = a[l];
	else return mx[o] = std::max(build(lch, l, mid), build(rch, mid + 1, r));
}
void add(int o, int l, int r) {
	if (q1 <= l && r <= q2) {
		mkad(o, q3);
		return;
	}
	down(o);
	if (q1 <= mid) add(lch, l, mid);
	if (mid < q2) add(rch, mid + 1, r);
	up(o);
}
/*
ll query(int o, int l, int r) {
	if (q1 <= l && r <= q2) return mx[o];
	down(o);
	ll ret = 0;
	if (q1 <= mid) ret = std::max(ret, query(lch, l, mid));
	if (mid < q2) ret = std::max(ret, query(rch, mid + 1, r));
	return ret;
}
int find(int x, int y) {
	int l = x, r = y;
	while (l < r) {
		q1 = x, q2 = mid;
		if (query(1, 1, n) >= q3) r = mid;
		else l = mid + 1;
	}
	q1 = x, q2 = l;
	ll ss = query(1, 1, n);
	return ss >= q3 ? l : -1;
}
*/
int find(int o, int l, int r) {
	if (mx[o] < q3) return -1;
	if (l == r) return l;
	down(o);
	int ret = -1;
	if (q1 <= mid) ret = find(lch, l, mid);
	if (ret == -1 && mid < q2) ret = find(rch, mid + 1, r);
	return ret;
}
inline void solve() {
	memset(mx, 0, sizeof mx);
	memset(ad, 0, sizeof ad);
	int q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	build(1, 1, n);
	while (q--) {
		int opt;
		scanf("%d%d%d%d", &opt, &q1, &q2, &q3);
		if (opt == 1) printf("%d\n", find(1, 1, n));
		else add(1, 1, n);
	}
}
int main() {
//	freopen("input", "r", stdin);
	int t; scanf("%d", &t);
	while (t--) solve();
}
