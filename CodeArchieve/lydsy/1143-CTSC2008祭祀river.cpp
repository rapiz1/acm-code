#include <cstdio>
#include <cstring>
const int N = 110;
int n, m, f[N], vis[N];
bool a[N][N];
bool find(int u) {
	for (int v = 1; v <= n; v++) if (a[u][v] && !vis[v]) {
		vis[v] = 1;
		if (!f[v] || find(f[v])) return (f[v] = u);
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		a[u][v] = 1;
	}
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		a[i][j] |= a[i][k] && a[k][j];
	int ans = n;
	for (int i = 1; i <= n; i++) memset(vis, 0, sizeof vis), ans -= find(i);
	printf("%d\n", ans);
}
