#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
typedef long long ll;
const int V = 1e5 + 10, K = 20, E = V << 1;
int n, m, hed[V], nxt[E], sz, dep[V], dfn[V], clk, anc[V][K];
bool in[V];
ll ans, dis[V];
struct Edge {int u, v, w;}st[E];
inline void add(int u, int v, int w) {
	st[++sz] = (Edge){u,v,w};
	nxt[sz] = hed[u], hed[u] = sz;
}
void dfs(int u) {
	dfn[u] = ++clk;
	for (int i = 1; i<K; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	fore if (v != anc[u][0]) {
		dis[v] = dis[u] + st[e].w, dep[v] = dep[u] + 1;
		anc[v][0] = u;
		dfs(v);
	}
}
inline int lca(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u,v);
	for (int x = dep[u] - dep[v], i = 0; x; x>>=1, i++) if (x&1) u = anc[u][i];
	for (int i = K - 1; ~i; i--) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	return u == v ? u : anc[u][0];
}
inline ll gdis(int u, int v) {return dis[u] + dis[v] - 2*dis[lca(u,v)];}
struct comp {
	bool operator()(int a, int b)const {return dfn[a] < dfn[b];}
};
typedef std::set<int, comp> bt;
bt tree;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1, u,v,w; i < n; i++) scanf("%d%d%d", &u, &v, &w), add(u,v , w), add(v, u, w);
	dfs(1);
	while (m--) {
		int u; scanf("%d", &u);
		in[u]^=1;
		int f = in[u] == 1 ? 1: -1;
		bt::iterator prev = tree.lower_bound(u), succ = tree.upper_bound(u);
		if (prev != tree.begin()) {
			prev--;
			ans += f*gdis(u, *prev);
		}
		else prev = tree.end();
		if (succ != tree.end()) {
			ans += f*gdis(u, *succ);
		}
		if (prev != tree.end() && succ != tree.end()) ans -= f*gdis(*prev, *succ);
		if (tree.begin() != tree.end()) {
			prev = tree.begin(), succ = tree.end();
			succ--;
			ans -= gdis(*prev, *succ);
		}
		if (in[u]) tree.insert(u);
		else tree.erase(tree.find(u));
		if (tree.begin() != tree.end()) {
			prev = tree.begin(), succ = tree.end();
			succ--;
			ans += gdis(*prev, *succ);
		}
		printf("%lld\n", ans);
	}
}
