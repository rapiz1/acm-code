#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
const int N = 1e4, M = 110;
int n, m, w[N], f[N][M], fa[N];
std::vector<int> to[N];
int h(int x) {
	if (x == 1) return 1;
	else if (x&1) return x*3 + 1;
	else return x/2;
}
void dfs(int u) {
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		dfs(v);
		for (int j = m; ~j; j--) {
			for (int k = 0; k < j; k++) f[u][j] = std::max(f[u][j], f[u][k] + f[v][j - k]);
		}
	}
	f[u][1] = std::max(f[u][1], w[u]);
}
void solve() {
	memset(f, 0, sizeof f);
	memset(w, 0, sizeof w);
	scanf("%d%d", &n, &m);
	m = std::min(m, n);
	for (int i = 1; i <= n; i++) scanf("%d", w + i);
	dfs(1);
	int ans = 0;
	for (int i = 1; i <= m; i++) ans = std::max(ans, f[1][i]);
	printf("%d\n", ans);
}
int main() {
	freopen("collatz.in", "r", stdin);
	freopen("collatz.out", "w", stdout);
	for (int i = 1; i <= 100; i++)
		for (int x = i; x != 1; x = h(x)) fa[x] = h(x);
	for (int i = 1; i < N; i++) to[fa[i]].push_back(i);
	int c; scanf("%d", &c);
	while (c--) solve();
}
