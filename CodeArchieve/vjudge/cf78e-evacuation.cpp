#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int N = 12, W = 65, V = N*N*W + 2 + N*N, E = V*7*2, INF = 1e9;
typedef std::pair<int, int> pa;
int n, t, hv[N][N], ex[N][N], lv[V], hed[V], nxt[E], sz = 1, bk[N][N], S, T;
char buf[20];
bool vis[N][N];
std::vector<pa> q1, q2;
std::queue<int> q;
struct Edge{int u, v, c, f;}st[E];
bool bfs() {
	memset(lv, 0, sizeof lv);
	q.push(S);
	lv[S] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fore(u) if (!lv[v] && st[e].c > st[e].f) lv[v] = lv[u] + 1, q.push(v);
	}
	return lv[T];
}
int dfs(int u, int a) {
	if (u == T || !a) return a;
	int fl = 0, f;
	fore(u) if (lv[v] == lv[u] + 1 && st[e].c > st[e].f && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
		a -= f;
		st[e^1].f -= f;
		st[e].f += f;
		fl += f;
		if (!a) break;
	}
	if (!fl) lv[u] = 0;
	return fl;
}
inline int zip(int x, int y, int t) {
	return t*n*n + (x - 1)*n + y;
}
inline void _add(int u, int v, int c) {
	st[++sz] = (Edge){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d\n" ,&n, &t);
	for (int i = 1; i <= n; i++) {
		fgets(buf + 1, 20, stdin);
		for (int j = 1; j <= n; j++) if (buf[j] != 'Y' && buf[j] != 'Z') hv[i][j] = buf[j] - '0';
	}
	pa s;
	getchar();
	for (int i = 1; i <= n; i++) {
		fgets(buf + 1, 20, stdin);
		for (int j = 1; j <= n; j++) if (buf[j] == 'Y') bk[i][j] = 1;
			else if (buf[j] == 'Z') bk[i][j] = 2, s = pa(i, j);
			else ex[i][j] = buf[j] - '0';
	}
//	S = zip(n, n, t + 1) + 1, T = S + 1;
	T = V - 1, S = T - 1;
	q1.push_back(s);
	vis[s.first][s.second] = 1;
	for (int i = 1; i <= t; i++) {
		for (int x = 1; x <= n; x++) for (int y = 1; y <= n; y++) if (!vis[x][y] && !bk[x][y]) {
			for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) if (dx*dy == 0) {
				int nx = x + dx, ny = y + dy;
				if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
				if (!vis[nx][ny] && !bk[nx][ny]) add(zip(x, y, i - 1), zip(nx, ny, i), INF);
			}
		}
		for (int x = 1; x <= n; x++) for (int y = 1; y <= n; y++) if (!vis[x][y] && ex[x][y]) {
			add(zip(x, y, i), zip(x, y, t + 1), ex[x][y]);
		}
		for (int j = 0; j < (int)q1.size(); j++) {
			pa& u = q1[j];
			for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) if (dx*dy == 0 && dx + dy){
				int x = u.first + dx, y = u.second + dy;
				if (x < 1 || x > n || y < 1 || y > n) continue;
				if (!vis[x][y] && !bk[x][y]) vis[x][y] = 1, q2.push_back(pa(x, y));
			}
		}
		q1.swap(q2);
		q2.clear();
	}
	for (int x = 1; x <= n; x++) for (int y = 1; y <= n; y++) {
		if (hv[x][y]) add(S, zip(x, y, 0), hv[x][y]);
		if (ex[x][y]) add(zip(x, y, t + 1), T, ex[x][y]);
	}
	int f = 0;
	while (bfs()) 
		f += dfs(S, 1e9);
	printf("%d\n", f);
}
