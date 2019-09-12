#include <cstdio>
#define mid ((l + r) >> 1)
#define lch (o << 1)
#define rch ((o << 1) | 1)
typedef long long ll;
const int N = (int)1e5 << 2;
int n, m;
ll p, ad[N], mu[N], a[N], s[N];
int q1, q2;
ll q3;
inline void up(int o) {
	s[o] = (s[lch] + s[rch])%p;
}
inline void mkmu(int o, ll x) {
	if (!o) return;
	mu[o] = mu[o]*x%p;
	ad[o] = ad[o]*x%p;
	s[o] = s[o]*x%p;
}
inline void mkad(int o, int l, int r, ll x) {
	if (!o) return;	
	s[o] = (s[o] + (r - l + 1)*x%p)%p;
	ad[o] = (ad[o] + x)%p;	
}
inline void down(int o, int l, int r) {
	if (mu[o] != 1) mkmu(lch, mu[o]), mkmu(rch, mu[o]), mu[o] = 1;
	if (ad[o]) mkad(lch, l, mid, ad[o]), mkad(rch, mid + 1, r, ad[o]), ad[o] = 0;
}
ll build(int o, int l, int r) {
	mu[o] = 1;
	if (l == r) return s[o] = a[l]%p;
	return s[o] = (build(lch, l, mid) + build(rch, mid + 1, r))%p;
}
void mult(int o, int l, int r) {
	if (q1 <= l && r <= q2) mkmu(o, q3);
	else {
		down(o, l, r);
		if (q1 <= mid) mult(lch, l, mid);
		if (q2 > mid) mult(rch, mid + 1, r);
		up(o);
	}
}
void add(int o, int l, int r) {
	if (q1 <= l && r <= q2) mkad(o, l, r, q3);
	else {
		down(o, l, r);
		if (q1 <= mid) add(lch, l, mid);
		if (mid < q2) add(rch, mid + 1, r);
		up(o);
	}
}
ll query(int o, int l, int r) {
	if (q1 <= l && r <= q2) return s[o];
	else {
		down(o, l, r);
		ll s = 0;
		if (q1 <= mid) s = (s + query(lch, l, mid))%p;
		if (mid < q2) s = (s + query(rch, mid + 1, r))%p;
		return s;
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%lld", &n ,&p);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	build(1, 1, n);
	scanf("%d", &m);
	while (m--) {
		int t;
		scanf("%d%d%d", &t, &q1, &q2);
		if (t == 1) {
			scanf("%lld", &q3);
			mult(1, 1, n);
		}
		else if (t == 2) {
			scanf("%lld", &q3);
			add(1, 1, n);
		}
		else if (t == 3) {
			printf("%lld\n", query(1, 1, n));
		}
	}
}
