#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
typedef long long ll;
const int V = 3010, E = ((V/2+1)*(V/2+1) + V)*2;
int n, a[V], sz = 1, hed[V], nxt[E], lv[V], now[V], s, t, ans;
struct EDGE{int u, v, c, f;}st[E];
inline ll sq(ll x) {return x*x;}
inline bool isq(ll x) {
	ll y = sqrt(x);
	return x == y*y;
}
int gcd(int x, int y) {return y ? gcd(y, x%y) : x;}
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	q.push(s);
	lv[s] = 1;
	while (!q.empty()) {
		int u = q.front();q.pop();
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && !lv[v])
			lv[v] = lv[u] + 1, q.push(v);
	}
	for (int i = 1; i <= n + 2; i++) now[i] = hed[i];
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	for (int& e = now[u]; e; e = nxt[e]) if (st[e].c > st[e].f) {
		int v = st[e].v;
		if (lv[v] == lv[u] + 1 && (f =dfs(v, std::min(a, st[e].c - st[e].f)))) {
			flow += f, a -= f;
			st[e].f += f, st[e^1].f -= f;
			if (!a) break;
		}
	}
	return flow;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	s = n + 1, t = n + 2;
	for (int i = 1; i <= n; i++) scanf("%d", a + i), ans += a[i];
	for (int i = 1; i <= n; i++) if (a[i]&1) {
		add(s, i, a[i]);
		for (int j = 1; j <= n; j++) if (!(a[j]&1) && (isq(sq(a[i]) + sq(a[j])) && gcd(a[i], a[j]) == 1)) add(i, j, 2e9);
	}
	for (int i = 1; i <= n; i++) if (!(a[i]&1)) add(i, t, a[i]);
	while (bfs()) ans -= dfs(s, 2e9);
	printf("%d\n", ans);
}
