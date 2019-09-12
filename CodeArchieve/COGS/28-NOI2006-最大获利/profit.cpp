#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define file(x) "profit."#x
const int V = 5e3 + 5e4 + 10, E = V*4*2, INF = 1e9;
int n, m, s, t, hed[V], nxt[E], sz = 1, lv[V], now[V], tot;
struct EDGE{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u,v,c,0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v ,int c) {_add(u, v, c), _add(v,u, 0);}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	lv[s] = 1, q.push(s);
	while (!q.empty()) {
		int u = q.front();q.pop();
		for (int e = hed[u], v; v = st[e].v; e=  nxt[e]) if (st[e].c > st[e].f && !lv[v])
			lv[v] = lv[u] + 1, q.push(v);
	}
	for (int i = 1; i <= n + m + 2; i++) now[i] = hed[i];
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	for (int& e = now[u]; e; e = nxt[e]) if(st[e].c > st[e].f) {
		int v = st[e].v;
		if (lv[v] == lv[u] + 1 && (f=dfs(v, std::min(st[e].c - st[e].f, a)))) {
			flow += f, a -= f;
			st[e].f += f, st[e^1].f -= f;
			if (!a) break;
		}
	}
	return flow;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	s = n + m + 1, t = s + 1;
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), add(i, t, x);
	for (int i = 1, x, y, z; i <= m; i++) scanf("%d%d%d", &x, &y, &z), add(s, i + n, z), add(i + n, x, 1e9), add(i + n, y, 1e9), tot += z;
	while (bfs()) tot -= dfs(s, 1e9);
	printf("%d\n", tot);
}
