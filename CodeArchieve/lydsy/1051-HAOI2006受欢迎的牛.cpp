#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int V = 1e4 + 10, E = 5e4 + 10;
int n, m, hed[V], nxt[E], sz, dfn[V], clk, sk[V], top, scc[V], cnt;
struct Edge{int u, v;}st[E];
std::vector<int> scom[V];
void add(int u, int v) {
	st[++sz] = (Edge){u, v};
	nxt[sz] = hed[u], hed[u] = sz;
}
int dfs(int u) {
	int lowu = dfn[u] = ++clk;
	sk[top++] = u;
	fore(u) if (!dfn[v]) lowu = std::min(lowu, dfs(v));
	else if (!scc[v]) lowu = std::min(lowu, dfn[v]);
	if (lowu == dfn[u]) {
		cnt++;
		int x;
		do {
			scc[x = sk[--top]] = cnt;
			scom[cnt].push_back(x);
		}while(x != u);
	}
	return lowu;
}
int main() {
//	freopen("cow.in", "r", stdin);
//	freopen("cow.out", "w", stdout);
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), add(u, v);
	for (int i = 1; i <= n; i++) if (!dfn[i]) dfs(i);
	int acc = 0, ans;
	for (int i = 1; i <= cnt; i++) {
		int chu = 0;
		for (int j = 0; j < (int)scom[i].size(); j++) {
			int u = scom[i][j];
			fore(u) if (scc[u] != scc[v]) chu = 1;
		}
		if (!chu) acc++, ans = scom[i].size();
	}
	printf("%d\n", acc == 1 ? ans : 0);
}
