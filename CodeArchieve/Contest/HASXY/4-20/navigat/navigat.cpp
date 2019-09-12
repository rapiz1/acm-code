#include <cstdio>
#include <algorithm>
#include <utility>
typedef std::pair<int, int> edge;
const int E = 5e5 + 10, V = 1e4 + 10;
int n, m, k, f[V], g[V], a[V], b[V];
edge st[E];
int main() {
	freopen("navigat.in", "r", stdin);
	freopen("navigat.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), f[i] = a[i];
	for (int i = 1; i <= m; i++) scanf("%d", b + i), g[i] = b[i];
	for (int i = 1, u, v; i <= k; i++) scanf("%d%d", &u, &v), st[i] = std::make_pair(u, v);
	std::sort(st + 1, st + 1 + k);
	for (int i = 1; i <= k; i++) {
		int u = st[i].first, v = st[i].second, ff = f[u], gg = g[v];
		f[u] = std::max(f[u], gg + a[u]);
		g[v] = std::max(g[v], ff + b[v]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = std::max(ans, f[i]);
	for (int i = 1; i <= m; i++) ans = std::max(ans, g[i]);
	printf("%d\n", ans);
}
