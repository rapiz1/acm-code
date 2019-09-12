#include<cstdio>
#include<queue>
#include<cstring>
#include <algorithm>
#define file(x) "maxflowb."#x
#define fore for (int e = hed[u], v; v = st[e].v; e = nxt[e])
const int V = 110, E = (V*V*4 + 2)*2*2;
int n, s, t, hed[V], nxt[E], sz = 1, ans, lv[V];
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
	int flow = 0, f;
	fore if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(st[e].c - st[e].f, a)))) {
		flow += f, a -= f;
		st[e].f += f, st[e^1].f -=f;
	} 
	return flow;
}
bool check(int u) {
	fore 
		if (st[e].c != st[e].f) return 0;
	return 1;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	s = n + 1, t = s + 1;
	add(n, 1, 1e9);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x, y; scanf("%d%d", &x, &y);
			if (y) {
				add(i, j, y - x);
				if (x) add(s, j, x),add(i, t, x);
			}
		}
	}
	int ans = 0;
	while (bfs()) dfs(s, 1e9);
	s = 1, t = n;
	while (bfs()) ans += dfs(s,1e9);
	printf("%d\n", ans);
}
