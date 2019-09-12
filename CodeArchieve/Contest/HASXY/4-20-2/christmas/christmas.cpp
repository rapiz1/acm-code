#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int INF = 0x3f3f3f3f, V = 1010, E = 510*510*2;
int n, w[V][V], x[V], y[V], mid, sz, hed[V], nxt[E], lv[V], s, t;
int sq(int r) {return r*r;}
struct Edge{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (Edge){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
std::queue<int> q;
bool bfs() {
	memset(lv, 0, sizeof lv);
	q.push(s);
	lv[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		fore(u) if (!lv[v] && st[e].c > st[e].f) lv[v] = lv[u] + 1, q.push(v);
	}
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int f, fl = 0;
	fore(u) if (lv[v] == lv[u] + 1 && st[e].c > st[e].f && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
		fl += f, a -= f;
		st[e].f += f, st[e^1].f -= f;
		if (!a) break;
	}
	if (!fl) lv[u] = 0;
	return fl;
}
inline bool check() {
	for(;sz;sz--) st[sz] = (Edge){0};
	sz = 1;
	s = 2*n + 1, t = s + 1;
	for (int i = 1; i <= t; i++) hed[i] = 0;
	for (int i = 1; i <= n; i++) {
		add(s, i, 1);
		for (int j = n + 1; j <= 2*n; j++) if (w[i][j] <= mid) add(i, j, 1);
		add(i + n, t, 1);
	}
	int f = 0;
	while (bfs()) f += dfs(s, INF);
	return f == n;
}
int main() {
	freopen("christmas.in", "r", stdin);
	freopen("christmas.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= 2*n; i++) scanf("%d%d", x + i, y + i);
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++) for (int j = n + 1; j <= 2*n; j++) w[i][j] = sq(x[i] - x[j]) + sq(y[i] - y[j]), r = std::max(r, w[i][j]);
	while (l < r) {
		mid = (l + r) >> 1;
		if (check()) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
