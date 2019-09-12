#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define file(x) "gro." #x
const int N = 210, V = N*N, E = V << 4, INF = 1e5;
int n, hed[V], nxt[E], cur[V], sz = 1, s = 1, t, lv[V], tot;
struct EDGE{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {
	_add(u, v, c), _add(v, u, 0);
}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));	
	lv[s] = 1;
	q.push(s);
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
	for(int& e = cur[u], v; v = st[e].v; e = nxt[e]) if (lv[v] == lv[u] + 1 && st[e].c > st[e].f && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
		flow += f, a -= f;
		st[e].f += f, st[e^1].f -= f;
		if (!a) break;
	}
	return flow;
}
int main() {
//	freopen(file(in), "r", stdin);
//	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	tot = t = n;
	for (int i = 1; i < n; i++) {
		int m;
		scanf("%d", &m);
		while(m--) {
			int v;
			scanf("%d", &v);
			if (i == 1 || v == n) add(i, ++tot, INF), add(tot, v, 1);
			else add(i, v, INF);
		}
	}
	int flow = 0;
	while (bfs()) {
		for (int i = 1; i <= tot; i++) cur[i] = hed[i];
		flow += dfs(s, INF);
	}
	printf("%d", flow);
}
