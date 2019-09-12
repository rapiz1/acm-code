#include <cstdio>
#include <algorithm>
#include <cmath>
const int N = 5e4 + 10;
typedef long long ll;
int n, m, c[N], bk, a[N];
struct Q {
	int l, r, id;
	bool operator<(const Q& rhs)const {
		return l/bk < rhs.l/bk || (l/bk == rhs.l/bk && r < rhs.r);
	}
}qu[N], ans[N];
inline ll comb(ll x) {return x*(x-1)/2;}
ll s = 0;
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
inline void upd(int l, int j) {
	s -= comb(c[a[l]]), c[a[l]]+=j, s += comb(c[a[l]]);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	bk = sqrt(n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= m; i++) scanf("%d%d", &qu[i].l, &qu[i].r), qu[i].id = i;
	std::sort(qu + 1, qu + 1 + m);
	int ll = 1, rr = 1;
 	c[a[1]]++;
	for (int i = 1; i <= m; i++) {
		int l = qu[i].l, r = qu[i].r;
		while (ll < l) upd(ll++, -1);
		while (ll > l) upd(--ll, 1);
		while (rr < r) upd(++rr, 1);
		while (rr > r) upd(rr--, -1);
		ans[qu[i].id].l = s;
		ans[qu[i].id].r = comb(qu[i].r - qu[i].l + 1);
	}
	for (int i = 1; i <= m; i++) {
		long long d = gcd(ans[i].l, ans[i].r);
		printf("%lld/%lld\n", ans[i].l/d, ans[i].r/d);
	}
}
