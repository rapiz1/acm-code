#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>
#include <utility>
const int N = 60010, E = 360010;
typedef long long ll;
typedef std::pair<ll, int> pa;
int n, m, s, t, hed[N], nxt[E], sz;
struct Edge{int u, v, w;}st[E];
bool vis[N];
ll dis[N];
//std::vector<int> ci[N];
std::priority_queue<pa, std::vector<pa>, std::greater<pa> > q;
void _add(int u, int v, int w) {
	st[++sz] = (Edge){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
void add(int u, int v, int w) {
	_add(u, v, w), _add(v, u, w);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int k; scanf("%d", &k);
		for (int j = 1, x; j <= k; j++) scanf("%d", &x), _add(x, n + i, 0), _add(2*n + i, x, 0); //, ci[i].push_back(x);
	}
	int e; scanf("%d", &e);
	while (e--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	scanf("%d", &e);
	while (e--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		_add(u + n, v + 2*n, w);
		_add(v + n, u + 2*n, w);
	}
	scanf("%d%d", &s, &t);
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	q.push(pa(0, s));
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) if (dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			q.push(pa(dis[v], v));
		}
	}
	if (dis[t] == dis[N - 1]) puts("-1");
	else printf("%lld\n", dis[t]);
}
