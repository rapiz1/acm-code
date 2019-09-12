#include <cstdio>
#include <cstring>
#include <queue>
#include <cassert>
#define file(x) "shuttle." #x
const int V = 310, INF = 1e5, E = (V*V + 2*V) << 1;
int n, m, hed[V], nxt[E], sz = 1, s, t, lv[V], ans;
struct EDGE{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c ){
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
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (!lv[v] && st[e].c > st[e].f)
			q.push(v), lv[v] = lv[u] + 1;
	}
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (lv[v] == lv[u] + 1 && (f = dfs(v, std::min(st[e].c - st[e].f, a)))) {
		flow += f, a -= f;
		st[e].f += f, st[e^1].f -= f;
		if (!a) break;
	}
	return flow;
}
char buf[1 << 15|1];
int Main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	s = n + m + 1, t = s + 1;
	for (int i = 1; i <= n; i++) {
		int w;scanf("%d", &w);
		ans += w;
		add(s, i, w);
		fgets(buf,1 << 15|1, stdin);
		for (int p = 0, x = 0, val; buf[p] && buf[p] != '\n' && buf[p] != '\r'; p += x)
		 	sscanf(buf + p, "%d%n", &val, &x), add(i, n + val, INF);
	}
	for (int i = 1, w; i <= m; i++) scanf("%d", &w), add(n + i, t, w);
	while (bfs()) ans -= dfs(s, INF);
	for (int i = 1; i <= n; i++) if (lv[i]) printf("%d ", i);
	putchar('\n');
	for (int i = 1; i <= m; i++) if (lv[i + n]) printf("%d ", i);
	printf("\n%d\n", ans);
}
int enter = Main();
int main() {;}
