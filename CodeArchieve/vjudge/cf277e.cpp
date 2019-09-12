#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
typedef std::pair<int, int> pa;
typedef long long ll;
const int N = 410, V = N << 1, E = (N*N + V)*2, D = 1e8;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, hed[V], nxt[E], sz = 1, a[V], p[V], flow, S, T;
ll ans, dis[V];
bool inq[V];
std::queue<int> q;
struct Edge{int u, v, c, f;ll w;}st[E];
void _add(int u, int v, ll w, int c) {
	st[++sz] = (Edge){u, v, c, 0, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
void add(int u, int v, ll w, int c) {_add(u, v, w, c), _add(v, u, -w, 0);}
bool bfs() {
	memset(dis, 0x3f, sizeof dis);
	q.push(S);
	dis[S] = 0;
	a[S] = 1e9;
	inq[S] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = 0;
		for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) if (st[e].c > st[e].f && dis[v] > dis[u] + st[e].w) {
			dis[v] = dis[u] + st[e].w;
			a[v] = std::min(a[u], st[e].c - st[e].f);
			p[v] = e;
			if (!inq[v]) inq[v] = 1, q.push(v);
		}
	}
	if (dis[T] == INF) return 0;
	flow += a[T];
	for (int e = p[T]; e; e = p[st[e].u]) {
		ans += a[T]*st[e].w;
		st[e].f += a[T];
		st[e^1].f -= a[T];
	}
	return 1;
}
bool cmp(pa x, pa y) {return x.second < y.second;}
pa poi[N];
inline ll sq(ll x) {return x*x;}
inline ll gd(pa x, pa y) {return sqrt(sq(x.first - y.first) + sq(x.second - y.second))*D;}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);	
	for (int i = 1; i <= n; i++) scanf("%d%d", &poi[i].first, &poi[i].second);
	std::sort(poi + 1, poi + 1 + n, cmp);
	S = 2*n + 1, T = S + 1;
	for (int i = 1; i <= n; i++) {
		add(S, i + n, 0, 1);
		add(i, T, 0, 2);
		for (int j = i + 1; j <= n; j++) if (poi[j].second > poi[i].second) add(i + n, j, gd(poi[i], poi[j]), 1);
	}
	while (bfs()) ;
	if (flow == n - 1) printf("%.8lf", (double)ans/D);
	else puts("-1");
}
