#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const double eps = 1e-10;
const int V = 210, E = (V*V + V*2) << 1;
int n, a[V][V], b[V][V];
double mid, dis[V];
namespace Dinic {
	struct Edge{int u, v, c, f;
		double w;
		Edge(int _u = 0, int _v = 0, double _w = 0, int _c = 0) {u = _u, v = _v, w = _w, c = _c, f = 0;}; 
	}st[E];
	int sz, s, t, hed[V], nxt[E], pre[V], a[V];
	inline void _add(int u, int v, double w, int c) {
		st[++sz] = Edge(u, v, w, c);
		nxt[sz] = hed[u], hed[u] = sz;
	}
	inline void add(int u, int v, double w, int c) {_add(u,v , w, c), _add(v, u, -w, 0);}
	inline void build() {
		s = 2*n + 1, t = s + 1;
		for (int i = 1; i <= t; i++) hed[i] = 0;
		while (sz) st[sz--] = Edge();
		sz = 1;
		for (int i = 1; i <= n; i++) {
			add(s, i, 0, 1);
			add(n + i, t, 0, 1);
			for (int j = 1; j <= n; j++) add(i, n + j, -(::a[i][j] - mid*b[i][j]),1);
		}
	}
	bool inq[V];
	inline bool spfa(double& cost) {
		std::queue<int> q;
		for (int i = 1; i <= t; i++) dis[i] = 1e18;
		q.push(s);
		dis[s] = 0, inq[s] = 0;
		a[s] = 1e9;
		while (!q.empty()) {
			int u = q.front();q.pop();
			inq[u] = 0;
			fore(u) if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
				dis[v] = dis[u] + st[e].w;
				pre[v] = e;
				a[v] = std::min(a[u], st[e].c - st[e].f);
				if (!inq[v]) inq[v] = 1, q.push(v);
			}
		}
		if (dis[t] == 1e18) return 0;
		for (int e = pre[t]; e; e = pre[st[e].u]) {
			cost += a[t]*st[e].w;
			st[e].f += a[t], st[e^1].f -= a[t];
		}
		return 1;
	}
	double solver() {
		build();
		double cost = 0;
		while (spfa(cost)) ;
		return -cost;
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	double l = 0, r = 0;
	for (int i = 1; i <= n;i ++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]), r = std::max(r, (double)a[i][j]);
	for (int i = 1; i <= n;i ++) for (int j = 1; j <= n; j++) scanf("%d", &b[i][j]);
	while (r - l > 1e-8) {
		mid = (l + r)/2;
		if (Dinic::solver() > eps) l = mid;
		else r = mid;
	} 
	printf("%.6lf\n", l);
}
