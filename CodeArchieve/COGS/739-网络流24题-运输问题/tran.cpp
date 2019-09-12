#include <cstdio>
#include <cstring>
#include <queue>
#define file(x) "tran."#x
const int V = 200, E = V*V*2;
int n, m, hed[V], nxt[E], sz = 1, dis[V], p[V], a[V], s, t;
struct EDGE{int u, v, w, c, f;}st[E];
inline void _add(int u, int v, int w, int c) {
	st[++sz] = (EDGE){u, v, w, c, 0};
	nxt[sz] = hed[u], hed[u]= sz;
}
inline void add(int u, int v, int w, int c) { _add(u, v, w, c), _add(v, u, -w, 0);}
bool inq[V];
inline bool spfa(int& cost) {
	static std::queue<int> q;
	memset(dis, 0x3f, sizeof(dis));
	inq[s] = 1, dis[s] = 0, a[s] = 0x3f3f3f3f;
	q.push(s);
	while(!q.empty()) {
		int u =q.front();q.pop();
		inq[u] = 0;
		for (int e = hed[u],v; v = st[e].v ; e= nxt[e]) if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			p[v] = e;
			a[v] = std::min(a[u], st[e].c - st[e].f);
			if (!inq[v]) inq[v] = 1,q.push(v);
		}
	}
	if (dis[t] == 0x3f3f3f3f) return 0;
	for (int e = p[t]; e; e = p[st[e].u])  {
		cost += st[e].w*a[t];
		st[e].f += a[t], st[e^1].f -= a[t];
	}
	return 1;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	s = n + m + 1, t = s + 1;
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), add(s, i, 0, x);
	for (int i = 1, x; i <= m; i++) scanf("%d", &x), add(n + i, t, 0, x);
	for (int i = 1, x; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &x), add(i, n + j, x, 0x3f3f3f3f); 
	int a = 0;
	while (spfa(a));
	printf("%d\n", a);
	for (int e = 2; e <= sz; e += 2) if (st[e].u <= n && st[e].v > n && st[e].v <= n + m) st[e].w *= -1, st[e^1].w *= -1;
	for (int e = 1; e <= sz; e++) st[e].f = 0;
	a = 0;
	while (spfa(a));
	printf("%d\n", -a); 
}
