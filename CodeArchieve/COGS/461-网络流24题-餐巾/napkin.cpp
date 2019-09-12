#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define file(x) "napkin." #x
const int V = 210*2, E = 5*V*2;
int n, np, kd, kp, md, mp, hed[V], nxt[E], sz = 1, dis[V], p[V], a[V], s, t;
struct EDGE{int u, v, w, c, f;}st[E];
inline void _add(int u, int v, int w, int c) {
	st[++sz] = (EDGE){u, v, w, c, 0};	
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w, int c) {_add(u, v, w, c), _add(v, u, -w, 0);}
bool inq[V];
std::queue<int> q;
inline bool spfa(int&cost) {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	inq[s] = 1;
	a[s] = 1e5;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();q.pop();
		inq[u] = 0;
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
			a[v] = std::min(a[u], st[e].c - st[e].f);
			dis[v] = dis[u] + st[e].w;
			p[v] = e;
			if (!inq[v]) inq[v] = 1, q.push(v);
		}
	}
	if (dis[t] == 0x3f3f3f3f) return 0;
	for (int e = p[t]; e; e = p[st[e].u]) {
		st[e].f += a[t], st[e^1].f -= a[t];
		cost += st[e].w*a[t];
	}
	return 1;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	s = 2*n + 1, t = s + 1;
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), add(s, i, 0, x), add(i + n, t, 0, x);
	scanf("%d%d%d%d%d", &np, &kd, &kp, &md, &mp);
	for (int i = 1; i <= n; i++) {
		if (i + 1 <= n) add(i, i + 1, 0, 1e5);
		if (i + kd <= n) add(i, n + i + kd, kp, 1e5);
		if (i + md <= n) add(i, n + i + md, mp, 1e5);
		add(s, n + i, np, 1e5);
	}
	int cost = 0;
	while (spfa(cost)) ;
	printf("%d\n", cost);
}
