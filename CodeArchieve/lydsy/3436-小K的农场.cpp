#include <cstdio>
#include <queue>
#include <cstring>
const int V = 1e4 + 10, E = V << 2;
int n, m, dis[V], cnt[V], sz, hed[V], nxt[E];
bool inq[V];
std::queue<int> q;
struct Edge{int u, v, w;}st[E];
inline void add(int u, int v, int w) {
	st[++sz] = (Edge){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1, x, u, v, w; i <= m;i++) {
		scanf("%d%d%d", &x, &u, &v);
		if (x == 1) scanf("%d", &w), add(u, v, -w);
		else if (x == 2) scanf("%d", &w), add(v, u, w);
		else if (x == 3) add(u, v, 0), add(v, u, 0);
	}
	n++;
	for (int i = 1; i < n; i++) add(n, i, 0);
	memset(dis, 0x3f, sizeof dis);
	q.push(n);
	dis[n] = 0, cnt[n] = inq[n] = 1;
	while (!q.empty()) {
		int u = q.front();q.pop();
		inq[u] = 0;
		for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) if (dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			if (!inq[v]) {
				if (++cnt[v] > n) {
					puts("No");
					return 0;
				}
				inq[v] = 1, q.push(v);
			}
		}
	}
	puts("Yes");
}
