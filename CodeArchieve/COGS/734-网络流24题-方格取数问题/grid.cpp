#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define fore for (int e = hed[u], v; v = st[e].v; e = nxt[e])
#define file(x) "grid." #x
const int V = 910, E = V*5*2;
int n, m, ans, lv[V], sz = 1, hed[V], nxt[E], s, t;
struct EDGE{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
inline int zip(int i, int j) {return (i - 1)*m + j;}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	lv[s] = 1, q.push(s);
	for (int u; !q.empty() && (u = q.front()); q.pop())
			fore if (st[e].c > st[e].f && !lv[v]) q.push(v), lv[v] = lv[u] + 1;
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f ;
	fore if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
		flow += f, a-=f;
		st[e].f += f, st[e^1].f -=f;
	}
	return flow;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	s = n*m + 1, t = s + 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		int x;scanf("%d", &x);
		ans += x;
		if ((i + j)&1) add(s, zip(i, j), x);
		else add(zip(i, j), t, x);
		if ((i + j)&1) for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) 
			if (dx + dy && dx*dy == 0 && i + dx <= n && i + dx >= 1 && j + dy <= m && j + dy >= 1)
				add(zip(i, j), zip(i +dx, j + dy), 1e5);
	}
	while (bfs()) ans -= dfs(s, 1e5);
	printf("%d", ans);
}
