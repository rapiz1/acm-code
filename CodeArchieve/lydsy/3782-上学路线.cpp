#include <cstdio>
#include <algorithm>
const int S = 1e6 + 3, T = 210;
typedef long long ll;
int t, fsz;
ll n, m, p, f[T];
struct B {
	ll x, y;
	bool operator<(const B& b)const {return x < b.x || (x == b.x && y < b.y);}
}st[T];
struct Number {
	int p, fac[S], rev[S];
	void init(int _p) {
		p = _p;
		fac[1] = rev[1] = fac[0] = rev[0] = 1;
		for (int i = 2; i < p; i++) rev[i] = (p - p/i*(ll)rev[p%i]%p)%p;
		for (int i = 2; i < p; i++) fac[i] = fac[i - 1]*(ll)i%p, rev[i] = (ll)rev[i]*rev[i - 1]%p;
	}
	int comb(ll n, ll m) {
		if (n < m) return 0;
		if (n < p && m < p) return (ll)fac[n]*rev[n - m]*rev[m]%p;
		return (ll)comb(n/p, m/p)*comb(n%p, m%p)%p;
	}
	void pt(int n) {
		printf("%d: \n", p);
		for (int i = 0; i <= n; i++, putchar('\n')) for (int j = 0; j <= i; j++) printf("%d ", comb(i, j));
	}
}fac[5];
int qpow(int x, int r, int p) {
	if (!x) return 0;
	int ret = 1;
	for (x%=p;r;r>>=1, x = (ll)x*x%p) if (r&1) ret = (ll)ret*x%p;
	return ret;
}
int comb(ll n, ll m) {
	int ret = 0;
	for (int i = 0; i < fsz; i++) 
		ret = (ret + (ll)fac[i].comb(n, m)*qpow(p/fac[i].p, fac[i].p - 2, fac[i].p)%p*p/fac[i].p)%p;
	return ret;
}
void pt(int n) {
		printf("%lld: \n", p);
		for (int i = 0; i <= n; i++, putchar('\n')) for (int j = 0; j <= i; j++) printf("%d ", comb(i, j));
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%lld%lld%d%lld", &n, &m, &t, &p);
	{
		ll x = p;
		for (int i = 2; (ll)i*i < x; i++) if (x%i == 0) {
			fac[fsz++].init(i);
			while (x%i == 0) x/=i;
		}
		if (x > 1) fac[fsz++].init(x);
	}
	for (int i = 1; i <= t; i++) scanf("%lld%lld", &st[i].x, &st[i].y);
	//for (int i = 0; i < fsz; i++) fac[i].pt(10);
	//pt(10);
	std::sort(st + 1, st + 1 + t);
	st[++t] = (B){n, m};
	for (int i = 1; i <= t; i++) {
		f[i] = comb(st[i].x + st[i].y, st[i].x);
		for (int j = 1; j < i; j++) f[i] = (f[i] - (ll)comb(st[i].x + st[i].y - st[j].x - st[j].y, st[i].x - st[j].x)*f[j]%p + p)%p;
	}
	printf("%lld\n", f[t]);
}
