#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int fsz = 4, factors[fsz] = {2, 3, 4679, 35617}, S = 1e5;
const ll M = 999911659;
ll n, g, idx;
struct Number {
	int p, rev[S], fac[S];
	inline void init(int n) {
		p = n;
		rev[0] = fac[0] = rev[1] = fac[1] = 1;	
		for (int i = 2; i < p; i++) rev[i] = (p - p/i*(ll)rev[p%i]%p)%p;
		for (int i = 2; i < p; i++) rev[i] = (ll)rev[i]*rev[i - 1]%p, fac[i] = fac[i - 1]*(ll)i%p;
	}
	int comb(ll n, ll m) {
		if (n < m) return 0;
		if (n < p && m < p) return (ll)fac[n]*rev[m]*rev[n - m]%p;
		return (ll)comb(n/p, m/p)*comb(n%p, m%p)%p;
	}
	void pt(int n) {
		printf("%d\n", p);
		for (int i = 0; i < n; i++, putchar('\n')) for (int j = 0; j <= i; j++) printf("%d ",  comb(i ,j));
	}
}fac[fsz];
ll qpow(ll x, ll r, ll m) {
	x%=m;
	if (!x) return 0;
	ll ret = 1;
	for (;r; r>>=1, x = x*x%m) if (r&1) ret = ret*x%m;
	return ret;
}
ll comb(ll n, ll m) {
	ll ret = 0;
	int M = ::M - 1;
	for (int i = 0; i < fsz; i++) ret = (ret + fac[i].comb(n, m)*qpow(M/fac[i].p, fac[i].p - 2, fac[i].p)%M*M/fac[i].p)%M;
	return ret;
}
void pt(int n) {
	for (int i = 0; i < n; i++, putchar('\n')) for (int j = 0; j <= i; j++) printf("%lld ",  comb(i ,j));
}
int main() {
//	freopen("input", "r", stdin);
	for (int i = 0; i < fsz; i++) fac[i].init(factors[i]);
//	pt(10);
	cin >> n >> g;
	for (int i = 1; (ll)i*i <= n; i++) if (n%i == 0) {
		if (i != n/i) idx = (idx  + comb(n, i))%(M - 1);
		idx = (idx + comb(n, n/i))%(M - 1);
	}
	cout << qpow(g, idx, M);
}
