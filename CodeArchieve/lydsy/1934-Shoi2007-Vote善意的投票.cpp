#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
const int V = 310, E = (V*V + 2*V)*2;
int n, m, s, t, hed[V], nxt[E], sz = 1, now[V], will[V], ans, lv[V];
struct EDGE{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u,v,c,0};
	nxt[sz] = hed[u], hed[u] = sz; 
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	lv[s] = 1, q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int e = hed[u],v;v=st[e].v; e=nxt[e]) if (st[e].c > st[e].f && !lv[v]) {
			lv[v] = lv[u] + 1;
			q.push(v);
		}
	}
	for (int i = 1; i <= n + 2; i++) now[i] = hed[i];
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	for (int& e = now[u]; e;e = nxt[e]) if (st[e].c > st[e].f) {
		int v = st[e].v;
		if (lv[v] == lv[u] + 1 && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
			flow += f, a-= f;
			st[e].f += f, st[e^1].f -= f;
			if (!a) break;
		}
	}
	return flow;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	s = n + 1, t = s + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", will + i);
		if (will[i]) add(s, i, 1);
		else add(i, t, 1);
	}
	while (m--) {
		int u, v;scanf("%d%d", &u, &v);
		if (will[u] == will[v]) continue;
		else if (will[u] != 1) std::swap(u, v);
		add(u, v, 1e9);
	}
	while (bfs()) ans += dfs(s, 1e9);
	printf("%d\n", ans);
}
