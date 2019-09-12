#include <bits/stdc++.h>
#define file(x) "dormitory."#x
using namespace std;
const int N = 120;
int n, tot, e[N][N], ip[N], out[N], hv, f[N];
bool vis[N];
bool dfs(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	for (int v = 1; v <= 2*n; v++) if (e[u][v] && !vis[v]) {
		vis[v] = 1;
		if (!f[v] || dfs(f[v])) return (f[f[v] = u] = v);
	}
	return 0;
}
bool solve() {
	scanf("%d", &n);
	tot = n;
	for (int i = 1; i <= n; i++) scanf("%d", ip + i);
	for (int i = 1; i <= n; i++) {
		scanf("%d", out + i);
		if (!ip[i]) out[i] = 0;
	 	tot -= out[i];
	}
	memset(e, 0, sizeof e);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		int x;
		scanf("%d", &x);
		if (!out[i] && ip[j]) e[i][j + n] = x;
	}
	for (int i = 1; i <= n; i++) if (ip[i] && !out[i]) e[i][i + n] = 1;
	memset(f, 0, sizeof f);
	for (int i = 1; i <= n; i++) if (!out[i]) {
		memset(vis, 0, sizeof vis);
		if (!dfs(i)) return 0;
	}
	return 1;
}
int main() {
	//freopen("input", "r", stdin);
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	int T;scanf("%d", &T);
	while (T--) puts(solve() ? "^.^":"T.T");
}
