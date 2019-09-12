#include <cstdio>
#include <queue>
#include <cstring>
const int N = 1e3 + 10, M = 1e4;
int n, m, dis[N], hed[N], nxt[M], sz;
struct ND{int u, dis;
	bool operator<(const ND& b)const {return dis > b.dis;}
};
struct EDGE{int u, v, w;}st[M];
std::priority_queue<ND> q;
inline void _add(int u, int v, int w) {
	st[++sz] = (EDGE){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w) {_add(u, v, w), _add(v, u, w);}
int main() {
	while (scanf("%d%d", &m, &n) == 2) {
		sz = 0;
		memset(dis, 0x3f, sizeof dis), memset(hed, 0, sizeof hed), memset(st, 0, sizeof st);
		for (int i = 1, u, v, w; i <= m; i++) scanf("%d%d%d", &u, &v, &w), add(u, v, w);
		q.push((ND){n, 0});
		dis[n] = 0;
		while (!q.empty()) {
			ND u = q.top(); q.pop();
			for (int e = hed[u.u], v; v = st[e].v; e = nxt[e])
				if (dis[v] > dis[u.u] + st[e].w) dis[v] = dis[u.u] + st[e].w, q.push((ND){v, dis[v]});
		}
		printf("%d\n", dis[1]);
	}
}
