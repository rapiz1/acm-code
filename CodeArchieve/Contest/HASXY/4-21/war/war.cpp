#include <cstdio>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cstring>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int V = 110, E = V*V*4, INF = 0x3f3f3f3f;
struct Edge{int u, v, c, f;}st[E];
int n, m, hed[V], nxt[E], sz = 1, ans;
void _add(int u, int v, int c) {
	st[++sz] = (Edge){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
void add(int u, int v, int c) {
	_add(u, v, c), _add(v, u, 0);
}
namespace Dinic {
int lv[V], cur[V], s, t;
std::queue<int> q;
bool bfs() {
	memset(lv, 0, sizeof lv);
	q.push(s);
	lv[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fore(u) if (st[e].c > st[e].f && !lv[v]) {
			q.push(v);
			lv[v] = lv[u] + 1;
		}
	}
	for (int i = 1; i <= n; i++) cur[i] = hed[i];
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int v, f, fl = 0;
	for (int& e = cur[u]; (v = st[e].v); e = nxt[e]) if (lv[v] == lv[u] + 1 && st[e].c > st[e].f && (f = dfs(v, std::min(st[e].c - st[e].f, a)))) {
		a -= f, fl += f;
		st[e].f += f, st[e^1].f -= f;
		if (!a) break;
	}
	if (!fl) lv[u] = 0;
	return fl;
}
int solver(int S, int T) {
	for (int i = 1; i <= sz; i++) st[i].f = 0;
	s = S, t = T;
	int f = 0;
	while (bfs()) f += dfs(S, 1e9);
	return f;
}
}
void work() {
	for (int i = 1; i <= n; i++) hed[i] = 0;
	for(;sz;sz--) st[sz] = (Edge){0};
	sz = 1;
	ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, c; i <= m; i++) scanf("%d%d%d", &u, &v, &c), add(u, v, c);
	for (int i = 2; i < n; i++) for (int j = 2; j < n; j++) if (i != j) {
		add(i, j, INF);
		ans = std::max(ans, Dinic::solver(1, n));
		st[sz].c = st[sz - 1].f = 0;
	}
	printf("%d\n", ans);
}
int main() {
	freopen("war.in", "r", stdin);
	freopen("war.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) work();
}
