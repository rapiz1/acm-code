#include <cstdio>
#include <cstring>
#include <queue>
#define file(x) "roundtable." #x
#define fore for (int e = hed[u], v; v = st[e].v; e = nxt[e])
const int V = 160 + 310, E = 200*300*2;
struct EDGE{int u, v, c, f;}st[E];
int n, m, hed[V], nxt[E], sz = 1, s, t, lv[V], tot;
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	lv[s] = 1, q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fore if(st[e].c > st[e].f && !lv[v]) q.push(v), lv[v] = lv[u] + 1;
	}
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	fore if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
		flow += f, a-= f;
		st[e].f += f, st[e^1].f -= f;
	}
	return flow;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	s = n + m + 1, t = s + 1;
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x), add(s, i, x);
		tot += x;
		for (int j = 1; j <= m; j++) add(i, n + j, 1);
	}
	for (int i = 1, x; i <= m; i++) scanf("%d", &x), add(n + i, t, x);
	int f = 0;
	while (bfs()) f += dfs(s, 1e5);
	if (f == tot) {
		puts("1");
		for (int i = 1; i <= n; i++, putchar('\n')) {
			for (int e = hed[i], v; v = st[e].v; e = nxt[e]) 
				if (st[e].f == 1) printf("%d ", st[e].v - n);
		}
	}
	else puts("0");
}
