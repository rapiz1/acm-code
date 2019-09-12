#include <cstdio>
typedef long long ll;
const int N  = 1010;
int n;
ll m, r, nr, nm;
void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a%b, d, y, x), y -= x*(a/b);
}
ll mod(ll x, ll y) {
	if (x > 0) return x%y;
	else return x + (-x + y - 1)/y*y;
}
void solve() {
	scanf("%lld%lld", &nm, &nr);
	bool flag = 0;
	for (int i = 2; i <= n; i++) {
		scanf("%lld%lld", &m, &r);
		ll d, x, y;
		exgcd(nm, m, d, x, y);
		if ((r - nr)%d) flag = 1;
		x = mod((r - nr)/d*x, m/d);
		nr += x*nm;
		nm = nm/d*m;
		nr = mod(nr, nm);
//		nr %= nm;
//		printf("%lld %lld\n", nr, nm);
	}
	printf("%lld\n", flag ? - 1: nr);
}
int main() {
//	freopen("input", "r", stdin);
	while (scanf("%d", &n) != EOF) solve();
}
