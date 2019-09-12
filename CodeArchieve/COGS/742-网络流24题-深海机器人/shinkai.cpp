#include <cstdio>
#include <cstring>
#include <queue>
#define file(x) "shinkai." #x
const int V = 500, E = V*6*2;
int n, m, hed[V], nxt[E], sz = 1, dis[V], a[V], p[V], s, t;
struct EDGE{int u, v, w, c, f;}st[E];
bool inq[V];
inline void _add(int u, int v, int w, int c) {
	st[++sz] = (EDGE){u, v, w, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v ,int w, int c) {_add(u, v, w, c), _add(v, u, -w, 0);}
inline bool inr(int i, int j) {return 1 <= i && i <= n && 1 <= j && j <= m;}
inline int zip(int i, int j) {return (i - 1)*n + j;}
inline bool spfa(int& cost) {
	static std::queue<int> q;
	memset(dis, 0x3f, sizeof(dis));
	q.push(s), dis[s] = 0, a[s] = 0x3f3f3f3f, inq[s] = 1;
	while (!q.empty()) {
		int u = q.front();q.pop();
		inq[u] = 0;
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			p[v] = u, a[v] = std::min(a[u], st[e].c - st[e].f);
			if (!inq[v]) q.push(v), inq[v] = 1;
		}
	}
	if (dis[t] == 0x3f3f3f3f) return 0;
	for (int e = p[t]; e; e = p[st[e].u]) {
		st[e].f += a[t], st[e^1].f -= a[t];
		cost += a[t]*st[e].w;
	}
	return 1;
}
int main() {
	freopen(file(in), "r", stdin);
	int a, b;
	scanf("%d%d%d%d", &a, &b, &n, &m);
	n++, m++;
	s = n*m + 1, t = s + 1;
	for (int i = 1; i <= n; i++) for (int j = 1, x; j < m; j++) {
		scanf("%d", &x);
	 	add(zip(i, j), zip(i, j + 1), -x, 1);
		add(zip(i, j), zip(i, j + 1), 0, 0x3f3f3f3f);
	}
 for (int j = 1, x; j <= m;j ++) for (int i = 1; i < n; i++) {
		scanf("%d", &x);
		add(zip(i, j), zip(i + 1, j), -x, 1);
		add(zip(i, j), zip(i + 1, j), 0, 0x3f3f3f3f);
	}
	for (int i = 1, x, y, z; i <= a; i++) scanf("%d%d%d", &z, &x, &y), x++, y++, add(s, zip(x, y), 0, z);
	for (int i = 1, x, y, z; i <= b; i++) scanf("%d%d%d", &z, &x, &y), x++, y++, add(zip(x, y), t, 0, z);
	int ans = 0;
	while (spfa(ans));
	printf("%d\n", ans);
}
