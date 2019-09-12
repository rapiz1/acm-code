#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1e5 + 10;
typedef long long ll;
const ll MOD = 1e9 + 7;
int n, k; 
ll f[N], g[N], h[N];
void mul(ll* f, ll* g) {
	static ll h[N];
	for (int i = 1; i <= n; i++) h[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i, k = 1; j <= n; j+=i, k++) 
			h[j] = (h[j] + f[i]*g[k])%MOD;
	for (int i = 1; i <= n; i++) f[i] = h[i];
}
int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%lld", f + i), g[i] = i == 1, h[i] = 1;
		while (k) {
			if (k&1) mul(g, h);
			k>>=1, mul(h, h);
		}
		mul(g, f);
		for (int i = 1; i <= n; i++) printf("%lld%c", g[i], " \n"[i == n]); 
	}
}
