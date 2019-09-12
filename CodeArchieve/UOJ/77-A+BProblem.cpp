#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int N = 5010, V = 1e5, E = 1e6, INF = 1e9;
int n, a[N], b[N], w[N], l[N], r[N], p[N],  sz=1, hed[V], nxt[E], lv[V], S, T;
std::vector<int> hv[V];
std::queue<int> q;
struct Edge{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (Edge){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {
	_add(u, v, c), _add(v, u, 0);
}
int dfs(int u, int a) {
	if (u == T || !a) return a;
	int f, fl = 0;
	fore(u) if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(st[e].c - st[e].f, a)))) {
		fl += f;
		st[e].f += f;
		st[e^1].f -= f;
		a -= f;
		if (!a) break;
	}
	return fl;
}
int main() {
}
