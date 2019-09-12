#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
const int V = 410, E = (110*210 + 110)*2;
struct EDGE{int u, v, c, f;}st[E];
int n, a, b, sz = 1, hed[V], nxt[E], s, t, lv[V];
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	lv[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && !lv[v])
			lv[v] = lv[u] + 1, q.push(v);
	}
	return lv[t];
}
int dfs(int u, int a ){
	if (u == t) return a;
	int flow = 0, f;
	for (int e = hed[u], v; v = st[e].v ; e = nxt[e]) if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(st[e].c - st[e].f, a)))) {
		flow += f, a -= f;
		st[e].f += f, st[e^1].f -= f;
		if (!a) break;
	}
	return flow;
}
int main() {
	scanf("%d%d%d", &n, &a, &b);
	s = a + b + 2*n + 1;
	t = s + 1;
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		for (int k = 1, j; k <= x; k++) scanf("%d", &j), add(j, a + i, 1);
		for (int k = 1, j; k <= y; k++) scanf("%d", &j), add(a + n + i, a + 2*n + j, 1);
	}
	for (int i = 1; i <= n; i++) add(a + i, a + n + i, 1);
	for (int i = 1; i <= a; i++) add(s, i, 1);
	for (int i = 1; i <= b; i++) add(a + 2*n + i, t, 1);
	int ans = 0;
	while (bfs()) 
		ans += dfs(s, 1e5);
	printf("%d\n", ans);
}
