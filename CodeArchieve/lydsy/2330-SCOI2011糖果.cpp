#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int V = 1e5 + 10, E = 3e5 + 10;
int n, k, dis[V], hed[V], nxt[E], sz, cnt[V];
bool inq[V];
std::queue<int> q;
struct Edge{int u, v, w;}st[E];
inline void add(int u, int v, int w) {
#ifdef DBG
	printf("%d -- %d with %d\n", u, v, w);
#endif
	w = -w;
	st[++sz] = (Edge){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	while (k--) {
		int u, v, x; scanf("%d%d%d", &x, &u, &v);
		if (x == 1) add(u, v, 0), add(v, u, 0);
		else if (x == 2) add(u, v, 1);
		else if (x == 3) add(v, u, 0);
		else if (x == 4) add(v, u, 1);
		else if (x == 5) add(u, v, 0);
	}
//	for (int i = 1; i <= n; i++) add(n + 1, i, 1);
	for (int i = n; i; i--) add(n + 1, i, 1);
	q.push(n + 1);
	memset(dis, 0x3f, sizeof dis);
	dis[n + 1] = 0;
	inq[n + 1] = 1, cnt[n + 1]++;
	while (!q.empty()) {
		int u = q.front();q.pop();
		inq[u] = 0;
		fore if (dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			if (!inq[v]) {
				inq[v] = 1, q.push(v);
				if (++cnt[v] > n + 1) {
					puts("-1");
					return 0;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) ans -= dis[i];
	printf("%lld\n", ans);
}
