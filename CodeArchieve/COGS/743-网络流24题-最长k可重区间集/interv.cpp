#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>
#define file(x) "interv."#x
const int V = 1100, E = 510*4 + 1100, INF = 0x3f3f3f3f;
int n, k, s, t, a[V], p[V], dis[V], nxt[E], hed[V], sz = 1, tot;
struct QU{int a, b;}ll[510];
struct EDGE{int u, v, w, c, f;}st[E];
inline void _add(int u, int v, int w, int c) {
	st[++sz] = (EDGE){u, v, w, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w, int c) {_add(u,v,w,c),_add(v,u,-w,0);}
bool inq[V];
std::queue<int> q;
inline bool spfa(int& cost) {
	memset(dis, 0x3f, sizeof(dis));
	a[s] = INF, dis[s] = 0, inq[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u =q.front(); q.pop();
		inq[u] = 0;
		for (int e = hed[u], v;v  =st[e].v; e=  nxt[e]) if (st[e].c > st[e].f && dis[v] > dis[u]+ st[e].w) {
			dis[v]= dis[u] + st[e].w;
			p[v] = e;
			a[v] = std::min(a[u], st[e].c - st[e].f);
			if (!inq[v]) inq[v] = 1, q.push(v);
		} 
	}
	if (dis[t] == INF) return 0;
	for (int e = p[t];e;e = p[st[e].u]) {
		cost += st[e].w*a[t];
		st[e].f += a[t],st[e^1].f -= a[t];
	}
	return 1;
}
std::map<int, int> mm;
inline void lisan() {
	static int val[V];
	for (int i = 1; i <= n; i++) val[i*2- 1] = ll[i].a, val[i*2] = ll[i].b;
	std::sort(val + 1, val + 1 + 2*n);
	for (int i = 1; i <= 2*n; i++) {
		if (mm.count(val[i])) continue;
		else  mm[val[i]] = ++tot;
	}
}
int main() {
	freopen(file(in),"r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d%d", &ll[i].a, &ll[i].b);
	lisan();
	s = tot + 1, t = s + 1;
	add(s, 1, 0, k);
	add(tot, t, 0, k);
	for (int i = 1; i < tot; i++) add(i, i + 1, 0, INF);
	for (int i = 1; i <= n; i++) {
		if (ll[i].a > ll[i].b) std::swap(ll[i].a, ll[i].b);
		add(mm[ll[i].a], mm[ll[i].b], ll[i].a - ll[i].b, 1); 
	}
	int ans = 0;
	while (spfa(ans));
	printf("%d\n", -ans);
}
