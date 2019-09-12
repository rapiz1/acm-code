#include <bits/stdc++.h>
typedef long long ll;
//typedef int ll;
using namespace std;
ll mod(ll x, ll y) {return x > 0 ? x%y : x + (-x + y - 1)/y*y;}
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
int qpow(ll x, ll r, int m) {
	if (!x) return 0;
	ll ret = 1;
	while (r) {
		if (r&1) ret = ret*x%m;
		x=x*x%m, r>>=1;
	}
	return ret;
}
int solve(ll a, ll b, ll p) {
	a%=p, b%=p;
	int cc = 0;
	ll t = 1;
	for (int g = gcd(a, p); g != 1; g = gcd(a, p)) {
		if (b%g) return -1;
		b/=g, p/=g, t = a/g*t%p;
		cc++;
		if (b == t) return cc;
	}
	map<int, int> revn;
	int sq = int(sqrt(p) + 1);
	ll g = 1;
	for (int i = 0; i <= sq; i++, g = g*a%p) 
		revn[g*b%p] = i;
	g = qpow(a, sq, p);
	for (ll i = 1, gg = g*t%p; i <= sq; i++, gg = g*gg%p)
		if (revn.count(gg)) return cc - revn[gg] + i*sq;
	return -1;
}
int main() {
//	freopen("input", "r", stdin);
	int a, p, b;
	while (scanf("%d%d%d", &a, &p, &b), (a + p + b != 0)) {
		int ans = solve(a, b, p);
		if (ans == -1) puts("No Solution");
		else printf("%d\n", ans);
	}
}
