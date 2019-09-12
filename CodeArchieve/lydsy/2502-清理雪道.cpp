#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define fore for (int e = hed[u], v; v = st[e].v; e = nxt[e])
const int V = 110, E = V*V*2*2;
int n, hed[V], nxt[E], sz = 1, ans, lv[V], s, t;
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
		int u = q.front(); q.pop();
		fore if (st[e].c > st[e].f && !lv[v])
			q.push(v), lv[v] = lv[u] + 1;
	}
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	fore if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(st[e].c - st[e].f, a)))) {
		flow += f, a -= f; 
		st[e].f += f, st[e^1].f -= f;
		if (!a) break;
	}
	return flow;
}
inline bool check(int u) {
	fore if (st[e].c != st[e].f) return 0;
	return 1;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	int s = n + 1, t = s + 1, S = t + 1, T = S + 1;
	::s = S, ::t = T;
	for (int i = 1; i <= n; i++) {
		add(s, i, 1e9);
		add(i, t, 1e9);
		int x;scanf("%d", &x);
		for (int j = 1; j <= x; j++) {
			int y; scanf("%d", &y);
			add(i, y, 1e9);
			add(S, y, 1);
			add(i, T, 1);
		}
	}
	add(t, s, 1e9);
	while (bfs()) dfs(S, 1e9);
	ans = st[hed[t]].f;
	hed[t] = nxt[hed[t]];
	hed[s] = nxt[hed[s]];
	::s = t, ::t = s;
	while (bfs()) ans -= dfs(t, 1e9);
	printf("%d\n", ans);
}
