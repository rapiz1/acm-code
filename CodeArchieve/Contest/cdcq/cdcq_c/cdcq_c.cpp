#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
#define file(x) "cdcq_c."#x
typedef long long ll;
const int V = 160, T = 151, INF = 0x3f3f3f3f;
int n, m, w, t, mid, v[V][T];
std::vector<int> to[V];
namespace Dinic {
	const int V = ::V*T, E = 2e6;
	struct Edge{int u, v, c, f;}st[E];
	int S, T, hed[V], nxt[E], sz, lv[V];
	inline void _add(int u, int v,int c) {
		st[++sz] = (Edge){u, v, c, 0};
		nxt[sz] = hed[u], hed[u] = sz;
	}
	inline void add(int u, int v,int c) {
		_add(u, v, c), _add(v, u, 0);
	}
	std::queue<int> q;
	bool bfs() {
		memset(lv, 0, sizeof lv);
		lv[S] = 1;
		q.push(S);
		while (!q.empty()) {
			int u = q.front();q.pop();
			fore if (!lv[v] && st[e].c > st[e].f) lv[v] = lv[u] + 1, q.push(v);
		}
		return lv[T];
	}
	int dfs(int u, int a) {
		if (u == T) return a;
		int fl = 0, f;
		fore if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(st[e].c - st[e].f, a)))) {
			fl += f;
			st[e].f += f, st[e^1].f -= f;
			a -= f;
			if (!a) break;
		}
		if (!fl) lv[u] = 0;
		return fl;
	}
	inline int zip(int i, int j) {return i + (j - 1)*n;}
	inline int solver() {
		sz = 1;
		S = n*t + 1, T = S + 1;
		for (int i = 1; i <= n; i++) {
			add(S, zip(i, 1), INF);
			for (int j = 1; j < t; j++) add(zip(i, j), zip(i, j + 1), v[i][j]);
			add(zip(i, t), T, v[i][t]);
			for (int j = 1; j <= t; j++) {
				for (int k = 0; k < (int)to[i].size(); k++) {
					int poi = to[i][k];
					add(zip(i, j), zip(poi, std::max(1, j - mid)), INF);
					int x = std::min(t, j + mid);
					if (x == t) add(T, zip(i, j), INF);
					else add(zip(poi, x + 1), zip(i, j), INF);
				}
			}
		}
		int f = 0;
		while (bfs()) 
			f += dfs(S, INF);
		for(;sz;sz--) st[sz] = (Edge){0};
		for (int i = 1; i <= T; i++) hed[i] = 0;
		return f;
	}
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d%d%d", &n, &m, &w, &t);
	for (int i = 1, u, v; i <=m; i++) scanf("%d%d", &u, &v),to[u].push_back(v), to[v].push_back(u);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= t; j++) scanf("%d", &v[i][j]);
	int l = 0, r = t + 1;
	while (l < r) {
		mid = (l + r) >> 1;
		if (Dinic::solver() <= w) r = mid; 
		else l = mid + 1;
	}
	printf("%d\n", l == t + 1 ? -1: l);
}
