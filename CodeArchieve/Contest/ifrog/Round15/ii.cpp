#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
const int N = 510, V = N << 1, E = (N*N + V)*2;
int n, m, k, a[N], c[N], f[N];
bool e[N][N], vis[N];
bool find(int u) {
	for (int v = 1; v <= n; v++) if (e[u][v] && !vis[v]) {
		vis[v] = 1;
		if (!f[v] || find(f[v])) return (f[v] = u);
	}
	return 0;
}
void solve() {
	memset(e, 0, sizeof e);
	memset(f, 0, sizeof f);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), e[u][v] = 1;
	for (int i = 1; i <= k; i++) scanf("%d%d", a + i, c + i);
	for (int i = 1; i <= n; i++) e[i][i] = 1;
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		e[i][j] = e[i][j] || (e[i][k] && e[k][j]);
	int tt = 0;
	for (int i = 1; i <= n; i++) e[i][i] = 0;
	for (int i = 1; i <= n; i++) memset(vis, 0, sizeof vis), tt += find(i);
	tt = n - tt;
	memset(f, 0, sizeof f);
	for (int i = 1; i <= n; i++) for (int j = m; j; j--) if (j >= a[i])
		f[j] = std::max(f[j], f[j - a[i]] + c[i]);
	int ans = -1;
	for (int j = 1; j <= m; j++) if (f[j] >= tt) {ans = j;break;}
	printf("%d\n", ans);
}
int main(){
//	freopen("input", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}
