#include <cstdio>
typedef long long ll;
inline ll mul(ll x, ll y, ll z) {
	ll a = x*y - z*(ll)((long double)x*y/z + 0.5);
	return (a%z+z)%z;
}
ll qpow(ll x, ll r, ll p) {
	//x%=p;
	//if (!x) return 0;
	ll y = 1;
	for(;r;r>>=1,x=mul(x, x, p)) if (r&1) y = mul(y, x, p);
	return y;
}
void solve() {
	ll n, k, p, ans = 0;
	scanf("%lld%lld%lld", &n, &k, &p);
	for(ll i = (p <= 100 ? 1 : p + 1); i <= n; i++) ans = (ans + qpow(i, k, p))%p;
	printf("%lld\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
