#include <cstdio>
typedef long long ll;
const int N = 2010;
const ll M = 1000000007;
int n, m, a[N];
ll c[N][N], f[N], ans = 1;
int main() {
	c[0][0] = 1;
	for (int i = 1; i < N; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j])%M;
	}
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d", a + i);
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		f[i] = c[n][i];
		for (int j = 1; j <= m; j++)
			f[i] = f[i]*c[a[j] + n - i - 1][n - i - 1]%M;
		ans = (ans + (i&1?-1:1)*f[i] + M)%M;
	}
	printf("%lld\n", ans);
}
