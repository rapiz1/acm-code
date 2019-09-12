#include <cstdio>
#include <queue>
#include <cstring>
const int N = 65, M = 12, V = N*M + N, E = (V*2 + N*N*M) << 1, INF = 0x3f3f3f3f;
int n, m, a[V], hed[V], nxt[E], sz = 1, s, t, pre[V], dis[V], ans;
bool inq[V];
struct Edge{int u, v, w, c, f;}st[E];
inline void _add(int u, int v, int w, int c) {
	st[++sz] = (Edge){u, v, w, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w, int c) {_add(u, v, w, c), _add(v, u, -w, 0);}
std::queue<int> q;
bool spfa() {
	memset(dis, 0x3f, sizeof dis);
	q.push(s);
	inq[s] = 1, dis[s] = 0, a[s] = INF;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = 0;
		for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
			a[v] = std::min(a[u], st[e].c - st[e].f);
			pre[v] = e;
			dis[v] = dis[u] + st[e].w;
			if (!inq[v]) inq[v] = 1, q.push(v);
		}
	}
	if (dis[t] == INF) return 0;
	for (int e = pre[t]; e; e = pre[st[e].u]) {
		ans += a[t]*st[e].w;
		st[e].f += a[t], st[e^1].f -= a[t];
	}
	return 1;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &m, &n);
	s = n + n*m + 1, t = s + 1;
	for (int i = 1; i <= n; i++) {
		add(s, i, 0, 1);
		for (int j = 1; j <= m; j++) {
			int x;scanf("%d", &x);
			for (int k = 1; k <= n; k++) add(i, n + (k - 1)*m + j, k*x, 1);
		}
	}
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) add(n + (j - 1)*m + i, t, 0, 1);
	while (spfa());
	printf("%.2lf\n", (double)ans/n);
}
