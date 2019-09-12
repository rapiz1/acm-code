#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define file(x) "telecow1." #x
const int V = 110, E = 610 << 3;
int n, m, s, t, hed[V], sz, nxt[E], lv[V];
struct EDGE{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
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
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
		st[e].f += f, st[e^1].f -= f;
		a -= f, flow += f;
		if (!a) return flow;
	}
	return flow;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i++) {
		int u, v;scanf("%d%d", &u, &v);   
		add(v, u, 1);
		add(u, v, 1);
	}
	int f = 0;
	while (bfs()) f += dfs(s, 1e5);
	printf("%d\n", f);
}
