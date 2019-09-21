#include <cstdio>
#include <vector>
#include <algorithm>
using std::swap;
const int N = 5e5 + 10, K = 21;
struct EDGE{int u, v;}st[N << 1];
int n, m, s, anc[N][K], dep[N], hed[N], nxt[N << 1];
inline void _add(int u, int v) {
	static int sz = 0;
	st[++sz] = (EDGE){u, v};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v) {
	_add(u, v), _add(v, u);
}
void dfs(int u, int fa) {
	anc[u][0] = fa;
	for (int i = 1; i < K; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for (int e = hed[u]; e; e = nxt[e]) {
		int v = st[e].v; 
		if (v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	} 
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);	
	for (int d = dep[u] - dep[v], k = 0; d; d >>= 1, k++) 
		if (d&1) u = anc[u][k];
	if (u == v) return u;
	for (int k = K - 1; k >= 0; k--) if (anc[u][k] != anc[v][k])
		u = anc[u][k], v = anc[v][k];
	return anc[u][0];
}
int main() {
	scanf("%d%d%d", &n ,&m, &s);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	dfs(s, 0);
	while (m--) {
		int x, y;scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
}
