#include <cstdio>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
typedef long long ll;
int n;
ll qpow(ll x, ll r, ll m) {
	if (!x) return 0;
	ll ret = 1;
	for (x%=m;r;r>>=1, x = x*x%m) if (r&1) ret = ret*x%m;
	return ret;
}
ll mod(ll x, ll y) {return x > 0 ? x%y : x + (-x + y - 1)/y*y;}
void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a%b, d, y, x), y -= a/b*x;
}
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
struct HT{
	static const int M = 1e5 + 3;
	int hed[M], sz, nxt[M];
	struct ND{int k, v;}st[M];
	void clear() {
		memset(hed, 0, sizeof hed);
		memset(nxt, 0, sizeof nxt);
		sz = 0;
	}
	void insert(int k, int v) {
		st[++sz]  = (ND){k, v};
		k%=M;
		nxt[sz] = hed[k], hed[k] = sz;
	}
	int find(int k) {
		for (int p = hed[k%M]; p; p = nxt[p]) if (st[p].k == k) return st[p].v;
		return -1;
	}
}revn;
int ord(ll a, ll b, ll m) {
	a%=m, b%=m;
	if (!a && b) return -1;
	revn.clear();
	int sq = ceil(sqrt(m));
	ll g = b;
	for (int i = 0; i <= sq; i++, g = g*a%m) revn.insert(g, i);
	ll gg = g = qpow(a, sq, m);
	for (int i = 1; i <= sq; i++, gg=gg*g%m) if (revn.find(gg) != -1) return i*sq - revn.find(gg);
	return -1;
}
int main() {
//	freopen("input", "r", stdin);
	int t, k;scanf("%d%d", &t, &k);
	while (t--) {
		int a, b, p;scanf("%d%d%d", &a, &b, &p);
		if (k == 1) printf("%d\n", (int)qpow(a, b, p));
		else if (k == 2) {
			a%=p, b%=p;
			ll x, y, d;
			exgcd(a, p, d, x, y);
			if (b%d) puts("Orz, I cannot find x!");
			else printf("%lld\n", mod(b/d*x, p/d));
		}
		else if (k == 3) {
			int ans = ord(a, b, p);
			if (ans == -1) puts("Orz, I cannot find x!");
			else printf("%d\n", ans);
		}
	}
}
