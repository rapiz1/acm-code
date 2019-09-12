#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
const int V = 210, E = (V*V + V*4)*2, INF = 0x3f3f3f3f;
int n, m, hed[V], nxt[E], sz = 1, dis[V], a[V], p[V], s, t, ans;
struct EDGE{int u, v, w, c, f;}st[E];
inline void _add(int u, int v, int w, int c) {
	st[++sz] = (EDGE){u, v, w, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w, int c) {_add(u, v, w, c), _add(v, u, -w, 0);}
bool inq[V];
std::queue<int> q;
inline bool spfa(int& cost) {
	memset(dis, 0x3f, sizeof(a));
	inq[s] = 1, dis[s] = 0, a[s] = INF;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = 0;
		for (int e = hed[u],v;v = st[e].v ; e = nxt[e]) if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			p[v] = e, a[v] = std::min(a[u], st[e].c - st[e].f);
			if (!inq[v]) inq[v] = 1, q.push(v);
		}
	}
	if (dis[t] == INF) return 0;
	for (int e = p[t]; e; e = p[st[e].u]) {
		cost += a[t]*st[e].w;
		st[e].f += a[t], st[e^1].f -= a[t];
	}
	return 1;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	int s = 2*n + 1, ss = s + 1, t = ss + 2, S = t + 1, T = S + 1;
	add(s, ss, 0, m);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), add(i, T, 0, x), add(S, i + n, 0, x), add(ss, i, 0, 1e9), add(i + n, t, 0, 1e9);
	for (int i = 1; i < n; i++) for (int j = i + 1, x; j <= n; j++) {
		scanf("%d", &x);
		if (x == -1) continue;
	 	add(i + n, j, x, 1e9);
	}
	add(t, s, 0, 1e9);
	::s = S, ::t = T;
	while (spfa(ans));
	printf("%d\n", ans);
}
