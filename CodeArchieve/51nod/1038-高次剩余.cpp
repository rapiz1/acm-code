#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p, a, b;
vector<ll> ans;
void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a%b, d, y, x), y -= a/b*x;
}
ll mod(ll x, ll y) {return x > 0 ? x%y : x + (-x + y - 1)/y*y;}
ll qpow(ll x, ll r, ll m) {
	if (!x) return 0;
	ll ret = 1;
	for (x%=m;r;r>>=1, x=x*x%m) if (r&1) ret = ret*x%m;
	return ret;
}
bool check(int a) {
	ll i, x = p - 1, phi = p - 1;
	for (i = 2; i*i <= x; i++) if (x%i == 0) {
		if (qpow(a, phi/i, p) == 1) return 0; 
		for (;x%i==0; x/=i);
	} 	
	if (x > 1 && qpow(a, phi/x, p) == 1) return 0; 
	return 1;
}
struct HT{
	static const int M = 1e4 + 3, N = 1e6;
	int hed[M], nxt[N], sz;
	struct ND{int k, v;}st[N];
	inline void clear() {
		memset(hed, 0, sizeof hed);
		sz = 0;
	}
	void insert(int k, int v) {
		st[++sz] = (ND){k, v};
		k%=M;
		nxt[sz] = hed[k], hed[k] = sz;
	}
	int find(int k) {
		for (int p = hed[k%M];p; p = nxt[p]) if (st[p].k == k) return st[p].v;
		return -1;
	}
}revn;
int ord(ll a, ll b, ll p) {
	revn.clear();
	int sq = ceil(sqrt(p));
	ll i, g, gg;
	for (i = 0, g = b; i <= sq; i++, g = g*a%p) revn.insert(g, i);
	g = qpow(a, sq, p);
	for (i = 1, gg = g; i <= sq; i++, gg=gg*g%p) 
		if (revn.find(gg) != -1) return i*sq - revn.find(gg);
	puts("!!!!ord not found");
	return 0;
}
int main() {
//	freopen("input", "r", stdin);
	int ks; cin >> ks;
	while (ks--) {
		cin >> p >> a >> b;
		ll e;
		for (int i = 2; i < p; i++) if (check(i)) {
			e = i;
			break;
		}
		int bb = ord(e, b, p);
//		printf("prime root %lld\n", e);
//		printf("assert %lld == %lld\n", b, qpow(e, bb, p));
		ll x, y, d;
		exgcd(a, p - 1, d, x, y);
		if (bb%d) puts("No Solution");
		else {
			x = mod(x*bb/d, (p - 1)/d);
			ans.clear();
			for (;x< p - 1; x += (p - 1)/d)
				ans.push_back(qpow(e, x, p));
			sort(ans.begin(), ans.end());
			for (int i = 0; i < (int)ans.size(); i++) printf("%lld ", ans[i]);
			putchar('\n');
		}
	}
}
