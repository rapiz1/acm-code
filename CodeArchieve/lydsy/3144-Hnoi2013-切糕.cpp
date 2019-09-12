#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
const int V = 50*50*50, E = V*4*2;
int p, q, r, d, hed[V], lv[V], nxt[E], sz = 1, now[V], s, t, ans;
struct EDGE{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
inline bool check(int i, int j) {return 1 <= i && i <= p && 1 <= j && j <= q;}
inline int zip(int i, int j, int k) {return k*p*q + (i - 1)*q + j;}
inline bool bfs() {
	static std::queue<int> q;
	memset(lv, 0, sizeof(lv));
	q.push(s);
	lv[s] = 1;
	while (!q.empty()) {
		int u = q.front();q.pop();
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && !lv[v])
			lv[v] = lv[u] + 1, q.push(v);
	}
	for (int i = 1; i <= p*::q*(r + 1) + 2; i++) now[i] = hed[i];
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	for (int& e = now[u]; e; e = nxt[e]) if (st[e].c > st[e].f) {
		int v = st[e].v;
		if (lv[v] == lv[u] + 1 && (f =dfs(v, std::min(a, st[e].c - st[e].f)))) {
			flow += f, a -= f;
			st[e].f += f, st[e^1].f -= f;
			if (!a) break;
		}
	}
	return flow;
}
int main() {
	scanf("%d%d%d%d", &p, &q, &r, &d);
	s = p*q*(r + 1) + 1, t = s + 1;
	for (int i = 1; i <= r; i++) for (int j = 1; j <= p; j++) for (int k = 1, x; k <= q; k++)
		scanf("%d", &x), add(zip(j, k, i - 1), zip(j, k, i), x);
	for (int i = 1; i <= p; i++) for (int j = 1; j <= q; j++) add(s, zip(i, j, 0), 1e9), add(zip(i, j, r), t, 1e9);
	for (int i = 1; i <= r; i++) for (int j = 1; j <= p; j++) for (int k = 1; k <= q; k++) {
		int pos = std::max(0, i - d - 1), now = zip(j, k, i);
		for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) if (dx + dy && !(dx*dy) && check(j + dx, k + dy))
			add(now, zip(j + dx, k + dy, pos), 1e9);
		pos = std::min(r, i + d);
		for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) if (dx + dy && !(dx*dy) && check(j + dx, k + dy))
			add(zip(j + dx, k + dy, pos), now, 1e9);
	}
	while (bfs())
	 	ans += dfs(s, 1e9);
	printf("%d\n", ans);
}
