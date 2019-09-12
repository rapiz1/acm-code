#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#define file(x) "home." #x
const int V = 22*52*15 + 10, E = (23*23*52 + 23*23*52)*2;
int n, m, k, lv[V], s, t, tot, sz = 1, h[30], sh[30][30], hed[V], nxt[E], now[V];
struct EDGE{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
inline bool bfs() {
	static std::queue<int> q;
	memset(lv, 0, sizeof(lv));
	lv[s] = 1;q.push(s);
	while (!q.empty()) {
		int u = q.front();q.pop();
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && !lv[v])
			q.push(v), lv[v] = lv[u] + 1;
	}
	for (int i = 1; i <= tot; i++) now[i] = hed[i];
	now[s] = hed[s], now[t] = hed[t];
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int fl = 0, f;
	for (int& e = now[u]; e; e = nxt[e]) {
		int v = st[e].v;
		if (lv[v] == lv[u] + 1 && st[e].c > st[e].f && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
			fl += f, a -= f;
			st[e].f += f, st[e^1].f -= f;
			if (!a) break;
		}
	}
	return fl;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", h + i, &sh[i][0]);
		for (int j = 1; j <= sh[i][0]; j++) {
			scanf("%d", &sh[i][j]);
			if (sh[i][j] == 0) sh[i][j] = n + 1;
			else if (sh[i][j] == -1) sh[i][j] = n + 2;
		}
	}
	n += 2;
	s = V - 2, t = V - 1;
	add(s, n - 1, k);
	for (int day = 0, flow = 0; day <= (n + 1)*(k + 1); day++) {
		add(tot = n + day*n, t, 1e5);
		while (bfs())
		 	flow += dfs(s, 1e5);
		if (flow == k) {
			printf("%d\n", day);
			return 0;
		}
		for (int i = 1; i <= n; i++) add(i + day*n, i + (day + 1)*n, 1e5);
		for (int i = 1; i <= m; i++) {
				int start = day%sh[i][0], end = (start + 1)%sh[i][0];
				start = sh[i][start + 1], end = sh[i][end + 1];
				add(start + day*n, end + (day + 1)*n, h[i]);
		}
	}
	puts("0");
}
