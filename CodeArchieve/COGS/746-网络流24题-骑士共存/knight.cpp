#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define file(x) "knight." #x
const int V = 50000, E = (V*8 + V)*2;
int n, m, hed[V], nxt[E], sz = 1, lv[V], s, t, now[V];
bool ban[210][210];
struct EDGE{int u, v, c, f;}st[E];
inline int zip(int i, int j) {return (i - 1)*n + j;}
inline bool check(int i, int j) {return 1 <= i && i <= n && 1 <= j && j <= n;}
inline void _add(int u, int v, int c) {
	st[++sz] = (EDGE){u,v,c,0};
	nxt[sz] = hed[u], hed[u] = sz; 
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
std::queue<int> q;
inline bool bfs() {
	memset(lv, 0, sizeof(lv));
	lv[s] = 1, q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int e = hed[u],v;v=st[e].v; e=nxt[e]) if (st[e].c > st[e].f && !lv[v]) {
			lv[v] = lv[u] + 1;
			q.push(v);
		}
	}
	for (int i = 1; i <= n*n + 2; i++) now[i] = hed[i];
	//now[s] = hed[s], now[t] = hed[t];
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int flow = 0, f;
	for (int& e = now[u]; e;e = nxt[e]) if (st[e].c > st[e].f) {
		int v = st[e].v;
		if (lv[v] == lv[u] + 1 && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
			flow += f, a-= f;
			st[e].f += f, st[e^1].f -= f;
			if (!a) break;
		}
	}
	return flow;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	int ans = n*n - m;
	while (m--) {
		int x, y;scanf("%d%d", &x ,&y);
		ban[x][y] =1;
	}
	s = n*n + 1, t = s + 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if ((i + j)%2 && !ban[i][j]) {
		add(s, zip(i, j), 1);
		for (int dx = -2; dx <= 2; dx++) for (int dy = -2; dy <= 2; dy++)
			if ((dx*dy == 2 || dx*dy == -2) && check(i + dx, j + dy) && !ban[i + dx][j + dy]) {
				add(zip(i, j), zip(i + dx, j + dy), 1e5);//, printf("%d --> %d\n", zip(i, j), zip(i + dx, j + dy));
			}
	}
	else if (!ban[i][j]) add(zip(i, j), t, 1);
	while (bfs()) ans -= dfs(s, 1e5);
	printf("%d\n", ans);
}
