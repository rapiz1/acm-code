#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 2e5 + 10;
int n, u, dep[N], fa[N], ans, dd[N];
std::vector<int> to[N];
void dfs(int u) {
	dd[u] = dep[u];
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (v == fa[u]) continue;
		dep[v] = dep[u] + 1;
		fa[v] = u;
		dfs(v);
		dd[u] = std::max(dd[u], dd[v]);
	}
}
int main() {
	scanf("%d%d", &n, &u);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), to[u].push_back(v), to[v].push_back(u); 
	dfs(1);
	for (int i = 0; i < dep[u]; i++) {
		ans = std::max(ans, std::max((i + dd[u] - dep[u]) , dd[u])*2);
		u = fa[u];
	}
	ans = std::max(ans, 2*dep[u]);
	printf("%d\n", ans);
}
