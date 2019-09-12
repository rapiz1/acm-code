#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
typedef long long ll;
const int N = 2e4 + 10, E = N*3*2;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, k, c[N], hed[N], nxt[E], sz;
ll dis[N];
bool inq[N];
std::queue<int> q;
struct Edge{int u,v , w;}st[E];
void _add(int u, int v, int w ){
	st[++sz] = (Edge){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
void add(int u, int v, int w) {_add(u,v ,w), _add(v, u, w);}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d",c + i), add(std::max(i - k, 1), std::min(i + k + 1, n + 1), c[i]);
	memset(dis, 0x3f, sizeof dis);
	q.push(1);
	inq[1] = 1;
	dis[1] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = 0;
		for (int e = hed[u], v;(v = st[e].v); e = nxt[e]) if (dis[v] > st[e].w + dis[u]) {
			dis[v] = dis[u] + st[e].w;
			if (!inq[v]) inq[v] = 1, q.push(v);
		}
	}
	printf("%lld\n", dis[n + 1]);
}
