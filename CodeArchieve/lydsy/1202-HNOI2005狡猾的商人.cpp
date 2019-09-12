#include <cstdio>
#include <algorithm>
#include <cstring>
const int V = 110, E = 2e3 + 10;
int n, m, nxt[E], hed[V], val[V], sz, vis[V];
struct Edge {int u, v, w;}st[E];
inline void add(int u, int v, int w) {
	st[++sz] = (Edge){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
int now;
bool dfs(int u) {
	vis[u] = now;
	for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) {
		if (vis[v] == now && val[v] != val[u] + st[e].w) return 0;
		if (!vis[v]) {
			val[v] = val[u] + st[e].w;
			if (!dfs(v)) return 0;
		}
	}
	return 1;
}
int main() {
//	freopen("input", "r", stdin);
	int T;scanf("%d", &T);
	while (T--) {
		memset(val, 0, sizeof val);
		memset(vis, 0, sizeof vis);
		sz = 0;memset(hed, 0, sizeof hed);
		memset(st, 0, sizeof st);
		n++;
		scanf("%d%d",&n,&m);
		for (int i = 1, s, t, v; i <= m; i++)
			scanf("%d%d%d", &s, &t, &v), t++,
		 	add(s, t, v), add(t, s, -v);
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			now = i;
			if (!vis[i] && !dfs(i)) {flag = 0;break;}
		}
		puts(flag?"true":"false");
	}
}
