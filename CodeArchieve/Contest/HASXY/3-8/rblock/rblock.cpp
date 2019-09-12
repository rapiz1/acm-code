#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define fore for (int e = hed[u], v; v = st[e].v; e = nxt[e]) 
#define file(x) "rblock." #x
const int V = 300, E = 25e3 + 10;
int n, m, sz = 1, hed[V], nxt[E], dis[V], ans;
struct EDGE{int u, v, w;}st[E];
inline void _add(int u, int v, int w) {
	st[++sz] = (EDGE){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v ,int w) {_add(u, v, w), _add(v, u, w);}
bool inq[V], ins[E];
std::queue<int> q;
inline void spfa() {
	memset(dis, 0x3f, sizeof(dis));
	q.push(1);
	inq[1] = 1, dis[1] = 0;
	while (!q.empty()) {
		int u = q.front();q.pop();
		inq[u] = 0;
		fore if (dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			if (!inq[v]) q.push(v);
		}
	}
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, w; i <= m; i++) scanf("%d%d%d", &u, &v, &w), add(u, v, w);
	spfa();
	q.push(n);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fore if (dis[v] == dis[u] - st[e].w)
			q.push(v), ins[e] = 1;
	}
	int past = dis[n];
	for (int i = 2; i <= sz; i += 2) if (ins[i] || ins[i^1]) {
		st[i].w = (st[i^1].w*=2);
		spfa();
		ans = std::max(ans, dis[n] - past);
		st[i].w = (st[i^1].w/=2);
	}
	printf("%d\n", ans);
}
