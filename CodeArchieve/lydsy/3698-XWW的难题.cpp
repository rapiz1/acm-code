#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) 
const int V = 310, E = (110*110*2 + 240*2 + 110*110*2)*2;
int n, hed[V], nxt[E], sz = 1, s, t, lv[V], du[V], ans, necc;
struct EDGE{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
inline void ula(int u, int v, int lower, int upper) {
	add(u, v, upper);
	du[u] -= lower, du[v] += lower;
}
inline int zip(int i, int j) {return (i - 1)*n + j;}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	lv[s] = 1;q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fore if (st[e].c > st[e].f && !lv[v])
			lv[v] = lv[u] + 1, q.push(v);
	}
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int fl = 0, f;
	fore if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(st[e].c - st[e].f, a)))) {
		fl += f, a -= f;
		st[e^1].f -= f, st[e].f += f;
		if (!a) break;
	} 
	return fl;
}
int main() {
	freopen("input", "r", stdin);
	scanf("%d", &n);
	int s = n*n + 2*n + 1, t = s + 1, S = t + 1, T = S + 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		double x;scanf("%lf", &x);
		int ce = ceil(x), fl = floor(x);
		if (i == n && j == n) {
			if (ce != 0) {
				puts("No");
				return 0;
			}
		}
		else if (j == n) ula(s, n*n + i, fl, ce);
		else if (i == n) ula(n*n + n + j, t, fl, ce);
		else ula(n*n + i, zip(i, j), fl, ce), add(zip(i, j), n*n + n + j, 1e9);
	}
	for (int i = 1; i <= t; i++) if (du[i] < 0) add(i, T, -du[i]); else if (du[i] > 0) add(S, i, du[i]), necc += du[i];
	add(t, s, 1e9);
	::s = S, ::t = T;
	while (bfs()) necc -= dfs(S, 1e9);
	if (necc) puts("No");
	else {
		::s = s, ::t = t;
		while (bfs()) ans += dfs(s, 1e9);
		printf("%d\n", ans);
	}
}
