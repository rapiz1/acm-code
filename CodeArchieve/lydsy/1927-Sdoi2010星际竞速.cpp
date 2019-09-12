#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
const int V = 900*2, E = (V*V + 15010 + 4*V)*2, inf = 0x3f3f3f3f;
int n, m, hed[V], sz = 1, nxt[E], dis[V], a[V], pre[V], s, t;
bool inq[V];
struct EDGE{int u, v, w, c, f;}st[E];
void _add(int u, int v, int w, int c) {
	st[++sz] = (EDGE){u, v, w, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
void add(int u, int v, int w, int c) {
	_add(u, v, w, c), _add(v, u, -w, 0);
}
std::queue<int> q;
inline bool spfa(int& cost) {
	memset(dis, 0x3f, sizeof dis);
	inq[s] = 1;
	a[s] = inf;
	dis[s] = pre[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = 0;
		for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			pre[v] = e;
			a[v] = std::min(st[e].c - st[e].f, a[u]);
			if (!inq[v]) q.push(v), inq[v] = 1;
		}
	}
	if (dis[t] == inf) return 0;
//	puts("");
	for (int e = pre[t]; e; e = pre[st[e].u]) {
		cost += st[e].w*a[t];
		st[e].f += a[t], st[e^1].f -= a[t];
	}
//	puts("done");
	return 1;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d",&n,&m);
	int s = 2*n + 1, t = s + 1, S = t + 1, T = S + 1;
	for (int i = 1; i <= n; i++) {
		int x;scanf("%d", &x);
		add(s, i, x, 1);
//		for (int j = 1; j <= n; j++) if (i != j) add(n + j, i, x, inf);
	}
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		if (u > v) std::swap(u, v);
		add(u + n, v, w, inf);
	}
	add(t, s, 0, inf);
	for (int i = 1; i <= n; i++) add(i + n, t, 0, 1), add(i, T, 0, 1), add(S, i + n, 0, 1);
	::s = S, ::t = T;
	int cost = 0;
	while (spfa(cost));
//	::s = s, ::t = t;
//	while (spfa(cost));
	printf("%d\n", cost);
}
