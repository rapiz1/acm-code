#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
typedef long long ll;
const int V = 20010, E = (2e5 + 10)*2;
int n, m, sz = 1, hed[V], nxt[E], lv[V], now[V], s, t, ans;
struct EDGE{int u, v, c, f;}st[E], edge[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
inline void biadd(int u, int v, int c) {_add(u, v, c), _add(v, u, c);}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	q.push(s);
	lv[s] = 1;
	while (!q.empty()) {
		int u = q.front();q.pop();
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && !lv[v])
			lv[v] = lv[u] + 1, q.push(v);
	}
	for (int i = 1; i <= n; i++) now[i] = hed[i];
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	for (int& e = now[u]; e; e = nxt[e]) if (st[e].c > st[e].f) {
		int v = st[e].v;
		if (lv[v] == lv[u] + 1 && (f =dfs(v, std::min(a, st[e].c - st[e].f)))) {
			flow += f, a -= f;
			st[e].f += f, st[e^1].f -= f;
			if (!a) break;
		}
	}
	return flow;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].c);
	int w;
	scanf("%d%d%d", &s, &t, &w);
	for (int i = 1; i <= m; i++) if (edge[i].c < w) biadd(edge[i].u, edge[i].v, 1);
	while (bfs()) ans += dfs(s, 1e9);
	sz = 1;
	memset(hed, 0, sizeof(hed)), memset(nxt, 0, sizeof(nxt));
	for (int i = 1; i <= m; i++) if (edge[i].c > w) biadd(edge[i].u, edge[i].v, 1);
	while (bfs()) ans += dfs(s, 1e9);
	printf("%d\n", ans);
}
