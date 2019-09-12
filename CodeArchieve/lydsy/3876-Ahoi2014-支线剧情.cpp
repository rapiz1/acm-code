#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) 
const int V = 400, E = V*50*4, INF = 0x3f3f3f3f;
int n, hed[V], nxt[E], sz = 1, s, t, ans, necc, p[V], a[V], dis[V];
struct EDGE{int u, v, c, w, f;}st[E];
inline void _add(int u, int v, int w, int c) {
	st[++sz] = (EDGE){u, v, c, w, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w, int c) {_add(u, v, w, c), _add(v, u, -w, 0);}
std::queue<int> q;
bool inq[V];
inline bool spfa(int& flow, int& cost) {
	memset(dis, 0x3f, sizeof(dis));
	q.push(s);
	inq[s] = 1, dis[s] = 0, a[s] = INF;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = 0;
		fore if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			a[v] = std::min(a[u], st[e].c - st[e].f);
			p[v] = e;
			if (!inq[v]) q.push(v), inq[v] = 1;
		}
	}
	if (dis[t] == INF) return 0;
	for (int e = p[t]; e; e = p[st[e].u]) {
		flow += a[t], cost += a[t]*st[e].w;
		st[e].f += a[t], st[e^1].f -= a[t];
	}
	return 1;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	int s = 1, t = n + 1, S = t + 1, T = S + 1;
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		add(i, t, 0, 1e9);
		for (int j = 1; j <= k; j++) {
			int x, y;
			scanf("%d%d", &x, &y);
			add(i, x, y, 1e9);
			add(i, T, y, 1);
			add(S, x, 0, 1);
		}
	}
	add(t, s, 0, 1e9);
	int cost = 0, flow = 0;
	::s = S, ::t = T;
	while (spfa(flow, cost)) ;
	printf("%d\n", cost);
}
