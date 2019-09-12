#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
const int N = 15, K = 2520;
typedef long long ll;
const ll INF = 0xc0c0c0c0c0c0c0c0;
int n, a[N][N], p[N];
bool to[N][N];
ll t;
namespace Brute {
ll f[2][N];
ll solve(ll t, int S, int one) {//0 for all
	memset(f, 0xc0, sizeof f);
	if (S) f[0][S] = 0;
	else for (int i = 1; i < n; i++) f[0][i] = 0;
	memset(to, 0, sizeof to);
	for (int i = 1; i < n; i++) for (int j = std::max(1, i - 1); j <= std::min(i + 1, n - 1); j++) to[i][j] = 1;
	for (int i = 1; i <= n; i++) to[i][n] = 1;
	for (ll i = 1; i <= t; i++) {
		int k = i&1;
		for (int j = 1; j <= n; j++) {
			f[k][j] = INF;
			for (int o = 1; o <= n; o++) if (to[o][j] && f[k^1][o] != INF) 
				f[k][j] = std::max(f[k][j], f[k^1][o] + a[j][(i - 1)%p[j]]);
//			printf("%d %d : %lld\n", i, j, f[k][i]);
		}
		if (one && i == 1) f[i][n] = INF;
	}
	ll ans = f[t&1][n];
	for (int i = 1; i <= n; i++) ans = std::max(ans, f[t&1][i]);
	return ans;
}
}
namespace Divide {
ll f[N][N], r[N][N], tmp[N][N];
void merge(ll a[N][N], ll b[N][N]) {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) tmp[i][j] = INF;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) //if (!(i == n && j == n))
		 	for (int k = 1; k <= n; k++)
				if (a[i][k] != INF && b[k][j] != INF)
				 	tmp[i][j] = std::max(tmp[i][j], a[i][k] + b[k][j]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = tmp[i][j];
}
void build(ll t, int one) {
	memset(f, 0xc0, sizeof f);
	for (int i = 1; i < n; i++) {
		Brute::solve(t, i, one);
		for (int j = 1; j <= n; j++) f[i][j] = Brute::f[t&1][j];
	}
	f[n][n] = 0;
}
ll solve() {
	//multi test case
	ll x = t/K;
	if (x == 0) return Brute::solve(t, 0, 1);
	build(K, 1);
	memcpy(r, f, sizeof f);
	build(K, 0);
	r[n][n] = INF;
	x--;
	while (x) {
		if (x&1) merge(r, f);
		x>>=1;
		merge(f, f);
	}
	x = t%K;
	if (x) {
		build(x, 0);
		merge(r, f);
	}
	ll ans = r[1][1];
//	printf("%lld %lld ", t/K, t%K);
	for (int i = 1; i < n; i++) for (int j = 1; j <= n; j++) ans = std::max(ans, r[i][j]);
	return ans;
}
}
int main() {
	freopen("dance.in", "r", stdin);
	freopen("dance.out", "w", stdout);
//	freopen("input", "r", stdin);
	int c; scanf("%d", &c);
	while (c--) {
		scanf("%d%lld", &n, &t);
		for (int i = 1; i <= n; i++) {
			scanf("%d", p + i);
			for (int j = 0; j < p[i]; j++) scanf("%d", &a[i][j]);
		}
		a[++n][0] = 0;
		p[n] = 1;
		printf("%lld\n", Divide::solve());
//		printf("%lld\n", Brute::solve(t, 0, 1));
	}
}
