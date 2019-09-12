#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define fore for (int e = hed[u], v; v = st[e].v; e = nxt[e])
const int V = 210, E = (200 + 2500 + 10)*2;
int n, k, hed[V], nxt[E], sz = 1, lv[V], s, t;
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
inline bool check(int mid) {
	for (int i = 2; i <= sz; i++) {
		st[i].f = 0;
		if (st[i].u == s) st[i].c = mid;
		else if (st[i].v == t) st[i].c = mid;
	}
	int f = 0;
	while (bfs()) f += dfs(s, 1e9);
	return f == mid*n;
}
char cmd[100];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	s = 4*n + 1, t = s + 1;
	for (int i = 1; i <= n; i++) {
		add(s, i, 1);
		add(n + i, t, 1);
		add(i, 2*n + i, k);
		add(3*n + i, n + i, k);
		scanf("%s", cmd + 1);
		for (int j = 1; j <= n; j++) if (cmd[j] == 'Y') add(i, n + j, 1); else add(2*n + i, 3*n + j, 1);
	}
	int l = 0, r = n;
	while (l < r) {
		int mid = l + r + 1>> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
}
