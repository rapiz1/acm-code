#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int n, m, k, phi[N], fac[N], sz;
ll ans = 0;
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
inline int lcm(int a, int b) {return a*1ll*b/gcd(a, b);}
int cnt;
void dfs(int lcc, int p) {
	if (p > sz) {
		ans += (cnt&1?-1:1)*m/lcc;
		return;
	}
	if (lcc > m) return;
	cnt++, dfs(lcm(lcc, fac[p]), p + 1), cnt--;
	dfs(lcc, p + 1);
}
inline void solve(int x) {
	sz = 0;
	int a, i;
	for (a = x, i = 2; (ll)i*i <= x; i++) if (a%i == 0)
		for(fac[++sz] = i;a%i == 0; a/=i);
	if (a != 1) fac[++sz] = a;	
	dfs(1, 1);
}
int main() {
//	freopen("input" ,"r", stdin);
	int t; cin >> t;
	phi[1] = 1;
	for (int i = 2; i < N; i++) if (!phi[i]) {
		phi[i] = i - 1;
		for (int j = i + i; j < N; j += i) {
			if (!phi[j]) phi[j] = j;
			phi[j] = phi[j]/i*(i - 1);
		}
	}
	for (int ks = 1; ks <= t; ks++) {
		int a, b;
		ans = 0;
		cin >> a >> n >> b >> m >> k;
		if (k) {
			n/=k, m/=k;
			if (n < m) swap(n, m);
			for (int i = 1; i <= n; i++) {
				if (i <= m) ans += phi[i];
				else solve(i);
			}
		}
		printf("Case %d: %lld\n", ks, ans);
	}
}
