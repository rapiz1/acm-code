#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int N = 110, V = 1110, INF = 0x3f3f3f3f, D = 1e4, E = (3010 + V)*2;
int n, m, sz = 1, hed[V], nxt[E], lv[V], S, T;
struct Edge{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (Edge){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
std::queue<int> q;
bool bfs() {
	memset(lv, 0, sizeof lv);
	q.push(S);
	lv[S] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fore(u) if (!lv[v] && st[e].c > st[e].f) {
			lv[v] = lv[u] + 1;
			q.push(v);
		}
	}
	return lv[T];
}
int dfs(int u, int a) {
	if (u == T) return a;
	int f, re = 0;
	fore(u) if (lv[v] == lv[u] + 1 && st[e].c > st[e].f && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
		re += f;
		st[e].f += f;
		st[e^1].f -= f;
		a -= f;
		if (!a) break;
	}
	if (!a) lv[u] = 0;
	return re;
}
bool check(int now) {
	for (int i = 1; i <= sz; i++) st[i].f = 0;	
	fore(S) if (v <= n) st[e].c = now;
	int f = 0;
	while (bfs()) f += dfs(S, INF);
	return m*D - f > 0;
}
int main() {
	freopen("hardlife.in", "r", stdin);
	freopen("hardlife.out", "w", stdout);
	scanf("%d%d", &n, &m);
	S = n + m + 1, T = S + 1;
	for (int i = 1, x, y; i <= m; i++) 
		scanf("%d%d", &x, &y),
		add(n + i, T, D),
	 	add(x, n + i, INF),
		add(y, n + i, INF);
	for (int i = 1; i <= n; i++) add(S, i, 1);
	int l = 0, r = n*D/2;
	while (l < r){ 
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	std::vector<int> ans;
	if (m) {
		int tot = 0;
		check(l);
		bfs();
		for (int i = 1; i <= n; i++) tot += (bool)lv[i];
		printf("%d\n", n - tot);
		for (int i = 1; i <= n; i++) if (!lv[i]) printf("%d\n", i);
	}
	else puts("1\n1");
}
