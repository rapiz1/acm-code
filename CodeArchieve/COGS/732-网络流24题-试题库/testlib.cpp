#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define file(x) "testlib." #x
#define fore for (int e = hed[u], v; v = st[e].v; e = nxt[e])
const int V = 1310, E = 21*V*2; 
struct EDGE{int u, v, c, f;}st[E];
int n, k, s, t, hed[V], nxt[E], sz = 1, lv[V], tot;
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
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &k, &n);
	s = n + k + 1 , t = s + 1;
	for (int i = 1, x; i <= k; i++) scanf("%d", &x), add(s, i, x), tot += x;
	for (int i = 1; i <= n; i++) {
		int p;scanf("%d", &p);
		for (int j = 1, x; j <= p; j++) scanf("%d", &x), add(x, i + k, 1);
		add(i + k, t, 1);
	}
	int f = 0;
	while (bfs())
	 	f += dfs(s, 1e5);
	if (f == tot) {
		for (int i = 1; i <= k; i++) {
			printf("%d: ", i);
			for (int e = hed[i], v; v = st[e].v; e = nxt[e]) if (st[e].v > k && st[e].f == 1) printf("%d ", v - k);
			putchar('\n');
		}
	}
	else puts("NoSolution!");
}
