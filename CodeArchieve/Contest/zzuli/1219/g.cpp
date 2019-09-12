#include <cstdio>
#include <cstring>
#include <algorithm>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int V = 5e5 + 10, E = V << 1, INF = 0x3f3f3f3f, K = 20;
int n, m, hed[V], nxt[E], dep[V], fa[V], esz, arr[V], faw[V];
struct Edge{int u, v, w;}st[E];
void _add(int u, int v, int w) {
	st[++esz] = (Edge){u, v, w};
	nxt[esz] = hed[u], hed[u] = esz;
}
void add(int u, int v, int w) {_add(u, v, w), _add(v, u, w);}
void dfs(int u) {
	fore(u) if (v != fa[u]) fa[v] = u, dep[v] = dep[u] + 1, faw[v] = st[e].w, dfs(v);
}
void solve() {
	memset(hed, 0, sizeof hed);
	while (esz) st[esz--] = (Edge){0};
	scanf("%d", &n);
	for (int i = 1, u, v, w; i < n; i++) scanf("%d%d%d", &u, &v, &w), add(u, v, w);
	dfs(1);
	scanf("%d", &m);
	while (m--) {
		int u, v, sz = 0; scanf("%d%d", &u, &v);
		while (u != v) {
			if (dep[u] < dep[v]) std::swap(u, v);
			arr[sz++] = faw[u];
			u = fa[u];
		}
		std::sort(arr, arr + sz);
		bool flag = 0;
		for (int i = 2; i < sz; i++) if (arr[i - 2] + arr[i - 1] > arr[i]) {flag = 1;break;}
		puts(flag?"Yes":"No");
	}
}
int main() {
//	freopen("input", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
