#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define file(x) "placetherobots."#x
const int N = 55, V = N*N, E = V*N << 1, INF = 0x3f3f3f3f;
struct EDGE{int u, v, c, f;}st[E];
int n, m, s, t, hed[V], nxt[E], sz = 1, lv[V];
char mm[N][N];
struct P{int i, s, t;
	inline bool in(int x) {return s <= x && x <= t;}
};
std::vector<P> x, y;
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	lv[s] = 1, q.push(s);
	while (!q.empty()) {
		int u = q.front();q.pop();
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && !lv[v]) {
			lv[v] = lv[u] + 1;
			q.push(v);
		}
	}
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	for (int e= hed[u], v; v= st[e].v; e = nxt[e]) 
		if (lv[v] == lv[u] + 1 && st[e].c > st[e].f && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
			flow += f, a -= f;
			st[e].f += f, st[e^1].f -= f;
			if (!a) break;
		}
	return flow;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", mm[i] + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) if (mm[i][j] == '*' || mm[i][j] == 'o') {
			bool f = mm[i][j] == 'o';
			int s = j;
			while (j + 1 <= m && (mm[i][j + 1] == '*' || mm[i][j + 1] == 'o')) {
				if (mm[i][++j] == 'o') f = 1;	
			}
			if (f) x.push_back((P){i, s, j});
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) if (mm[i][j] == '*' || mm[i][j] == 'o') {
			bool f = mm[i][j] == 'o';
			int s = i;
			while (i + 1 <= n && (mm[i + 1][j] == '*' || mm[i + 1][j] == 'o')) {
				if (mm[++i][j] == 'o') f = 1;	
			}
			if (f) y.push_back((P){j, s, i});
		}
	}
	for (int i = 0; i < x.size(); i++) for (int j = 0; j < y.size(); j++) 
		if (x[i].in(y[j].i) && y[j].in(x[i].i))
			if (mm[x[i].i][y[j].i] == 'o') add(i + 1, x.size() + 1 + j, 1);
	s = x.size() + y.size() + 1;
	t = s + 1;
	for (int i = 0; i < x.size(); i++) add(s, i + 1, 1);
	for (int i = 0; i < y.size(); i++) add(i + x.size() + 1, t, 1);
	int flow = 0;
	while (bfs()) flow += dfs(s, INF);
	printf("%d\n", flow);
}
