#include <cstdio>
#include <vector>
const int V = 500010;
int n, m, s, p, w[V], sk[V], top, scnt, dfn[V], clk, scid[V], f[V], ww[V];
std::vector<int> to[V], to2[V], scc[V];
bool vis[V], end[V], ee[V];
int tarjan(int u) {
	int lowu = dfn[u] = ++clk;
	sk[top++] = u;
	for (int i = 0, v; i < (int)to[u].size(); i++) {
		v = to[u][i];
		if (!dfn[v]) lowu = std::min(lowu, tarjan(v));
		else if (!scid[v]) lowu = std::min(lowu, dfn[v]);
	}
	if (dfn[u] == lowu) {
		int x;
		++scnt;
		do {
			x = sk[--top];
			scid[x] = scnt;
			ww[scnt] += w[x];
			scc[scnt].push_back(x);
			ee[scnt] |= end[x];
		}while (u != x);
	}
	return lowu;
}
int dfs(int u) {
	if (f[u] != -1) return f[u];
	if (ee[u]) f[u] = ww[u];
	else f[u] = -2e9;
	for (int i = 0; i < (int)to2[u].size(); i++) f[u] = std::max(dfs(to2[u][i]) + ww[u], f[u]);
	return f[u];
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), to[u].push_back(v);
	for (int i = 1; i <= n; i++) scanf("%d", w + i), f[i] = -1;
	scanf("%d%d", &s, &p);
	for (int i = 1, x; i <= p; i++) scanf("%d", &x), end[x] = 1;
	for (int i = 1; i <= n; i++) if (!scid[i]) tarjan(i);
	for (int i = 1; i <= scnt; i++) {
		for (int j = 0; j < (int)scc[i].size(); j++) {
			int u = scc[i][j];
			for (int k = 0; k < (int)to[u].size(); k++) {
				int v = to[u][k];
				if (scid[u] != scid[v] && !vis[scid[v]]) to2[scid[u]].push_back(scid[v]), vis[sk[top++] = scid[v]] = 1;
			}
			while(top) vis[sk[--top]] = 0;
		}
	}
	printf("%d\n", dfs(scid[s]));
}
