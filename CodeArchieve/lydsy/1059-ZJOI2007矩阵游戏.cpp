#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 210;
int n, a[N][N], f[N];
bool vis[N];
bool find (int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	for (int v = 1; v <= n; v++) if (a[u][v]) {
		if (!f[v] || find(f[v])) return f[v] = u;
	}
	return 0;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
	int cnt = 0;
	memset(f, 0, sizeof f);
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		cnt += find(i);
	}
	puts(cnt == n ? "Yes" : "No");
}
int main() {
//	freopen("input", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) solve();
}
