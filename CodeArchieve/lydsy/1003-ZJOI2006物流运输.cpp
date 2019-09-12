#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
const int V = 30, E = (V*V)<<1, N = 110;
int n, m, k, hed[V], nxt[E], sz, dis[N][N], tmp[V], f[N];
bool inq[V];
struct pa {int l, r;
	inline bool jiao(int ll, int rr){return std::max(l, ll) <= std::min(r, rr);}
};
std::vector<pa> ban[V];
inline bool can(int u, int l, int r) {
	for (int i = 0; i < (int)ban[u].size(); i++) if (ban[u][i].jiao(l , r)) return 0;
	return 1;
}
struct Edge{int u, v, w;}st[E];
inline void _add(int u, int v, int w) {
	st[++sz] = (Edge){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w) {_add(u, v, w), _add(v, u, w);}
std::queue<int> q;
int main() {
	freopen("bzoj_1003.in", "r",stdin);
	freopen("bzoj_1003.out", "w", stdout);
	int e, d;
	scanf("%d%d%d%d", &n, &m, &k, &e);
	for (int u, v, w;e--;) scanf("%d%d%d", &u, &v, &w), add(u, v, w);
	scanf("%d", &d);
	for (int x, a, b;d--;) scanf("%d%d%d", &x, &a, &b), ban[x].push_back((pa){a, b});
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) {
		memset(tmp, 0x3f, sizeof tmp);
		q.push(1);
		inq[1] = 1, tmp[1] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			inq[u] = 0;
			for (int e = hed[u], v; (v  = st[e].v); e = nxt[e]) if (can(v, i, j) && tmp[v] > tmp[u] + st[e].w) {
				tmp[v] = tmp[u] + st[e].w;
				if (!inq[v]) q.push(v), inq[v] = 1;
			}
		}
		dis[i][j] = tmp[m];
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++) {
		if (dis[1][i] != 0x3f3f3f3f) f[i] = dis[1][i]*i;
		for (int j = 1; j < i; j++) if (dis[j + 1][i] != 0x3f3f3f3f)
			f[i] = std::min(f[i], f[j] + dis[j + 1][i]*(i - j) + k);
	}
	printf("%d\n", f[n]);
}
