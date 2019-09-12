#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define file(x) "alis."#x
#define fore for (int e = hed[u], v; v = st[e].v; e = nxt[e])
const int V = 1100, E = V*V << 1, INF = 1e5;
int n, a[600], f[600], hed[V], nxt[E], sz = 1, lv[V], s, t, len;
struct EDGE{int u, v, c, f;}st[E];
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
		int u = q.front();q.pop();
		fore if (st[e].c > st[e].f && !lv[v]) lv[v] = lv[u] + 1, q.push(v);
	}
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f ;
	fore if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
		flow += f, a -= f;
		st[e].f += f, st[e^1].f -= f;
		if (!a) break;
	}
	return flow;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	s = 2*n + 1, t = s + 1;
	for (int i = 1; i <= n; i++) {
		add(i, i + n, 1);
		scanf("%d", a + i);
		f[i] = 1;
		for (int j = 1; j < i; j++) if (a[j] <= a[i]) f[i] = std::max(f[i], f[j] + 1);
		len = std::max(len, f[i]);
		for (int j = 1; j < i; j++) if (a[j] <= a[i] && f[i] == f[j] + 1) add(j + n, i, 1);
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == len) add(i + n, t, 1); 
		if (f[i] == 1) add(s, i, 1);
	}
	printf("%d\n", len);
	int ans = 0;
	while (bfs()) ans += dfs(s, INF);
	printf("%d\n", ans);
	for (int e = hed[s], v; v = st[e].v; e = nxt[e]) if (v == 1) st[e].c = INF;
	for (int e = hed[1], v; v = st[e].v; e = nxt[e]) if (v == 1 + n) st[e].c = INF;
	for (int e = hed[n], v; v = st[e].v; e = nxt[e]) if (v == n + n) st[e].c = INF;
	for (int e = hed[n + n], v; v = st[e].v; e = nxt[e]) if (v == t) st[e].c = INF;
	while (bfs()) ans += dfs(s, INF);
	printf("%d\n", ans);
}
