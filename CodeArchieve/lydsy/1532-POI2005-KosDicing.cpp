#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
typedef long long ll;
const int V = 20010, E = (30010 + 10010)*2;
int n, m, a[V], sz = 1, hed[V], nxt[E], lv[V], now[V], s, t;
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
		int u = q.front();q.pop();
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && !lv[v])
			lv[v] = lv[u] + 1, q.push(v);
	}
	for (int i = 1; i <= n + m + 2; i++) now[i] = hed[i];
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
inline bool check(int cap) {
	for (int i = 1; i <= sz; i++) st[i].f = 0;
	for (int i = 2; i <= 2*n; i += 2) st[i].c = cap;
	int flow = 0;
	while (bfs()) flow += dfs(s, 1e9);
	return flow == m;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	if (n == 1 || m == 0) {
		puts("0");
		return 0;
	}
	s = n + m + 1, t = n + m + 2;
	for (int i = 1; i <= n; i++) add(i, t, 1);
	for (int i = 1, x, y; i <= m; i++) add(s, i + n, 1), scanf("%d%d", &x, &y), add(i + n, x, 1), add(i + n, y, 1);
	int l = 0, r = m;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
