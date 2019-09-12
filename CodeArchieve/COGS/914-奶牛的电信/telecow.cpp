#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define file(x) "telecow."#x
const int V = 240, E = (610*4 + V) << 1;
struct EDGE{int u, v, c, f;}st[E];
int n, m, s, t, sz = 1, hed[V], nxt[E], lv[V];
inline void _add(int u, int v, int c) {
	st[++sz] =(EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	lv[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u =q.front();
		q.pop();
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && !lv[v])
			lv[v] = lv[u] + 1, q.push(v);
	}
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0 , f;
	for (int e = hed[u], v; v = st[e].v; e = nxt[e]) 
		if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
			flow += f, a -= f;
			st[e].f += f, st[e^1].f -= f;
			if (!a) break;
		}
	return flow;
}
int main() {
	//freopen(file(in), "r", stdin);
	scanf("%d%d%d%d", &n, &m, &s, &t);
	s += n;
	for (int i = 1; i <= n; i++) add(i, i + n, 1);
	for (int i = 1; i <= m; i++) {
		int u, v;scanf("%d%d", &u, &v);
		add(u + n, v, 1e5);
		add(v + n, u, 1e5);
	}
	int f = 0;
	while (bfs()) 
		f += dfs(s, 1e5);
	printf("%d\n", f);
}
