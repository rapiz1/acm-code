#include <cstdio>
#include <algorithm>
#include <cmath>
typedef long long ll;
ll n, ans;
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
void check(ll x) {
	for (ll u = 1; u*u <= x; u++) {
		ll v = sqrt(x - u*u);
		if (u >= v) break;
		if (v*v + u*u != x) continue;
		if (gcd(u, v) == 1)
			ans++;
	}
}
int main() {
//	freopen("cir.in", "r", stdin);
//	freopen("cir.out" ,"w" ,stdout);
	scanf("%lld", &n);
	ll ub = sqrt(2*n) + 0.5;
	for (ll i = 1; i <= ub; i++) if (2*n%i == 0) {
		check(i);
		if (i != 2*n/i) check(2*n/i);
	}
	ans = ans*4 + 4;
	printf("%lld\n", ans);
}
