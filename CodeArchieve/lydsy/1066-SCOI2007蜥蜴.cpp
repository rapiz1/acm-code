#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
using std::max;
using std::min;
const int N = 23, V = N*N*2, E = 1e6, INF = 1e9;
struct Edge {int u, v, c, f;}st[E];
int n, m, d, S, T, hed[V], nxt[E], sz = 1, h[N][N], lv[V];
int sq(int x) {return x*x;}
bool l[N][N];
void _add(int u, int v, int c) {
	st[++sz] = (Edge){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
int zip(int i, int j) {return (i - 1)*m + j;}
bool bfs() {
	std::queue<int> q;
	memset(lv, 0, sizeof lv);
	lv[S] = 1;
	q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fore(u) if (!lv[v] && st[e].c > st[e].f) {
			lv[v] = lv[u] + 1;
			q.push(v);
		}
	}
	return lv[T];
}
int dfs(int u, int a) {
	if (!a || u == T) return a;
	int fl = 0, f;
	fore(u) if (lv[v] == lv[u] + 1 && st[e].c > st[e].f && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
		fl += f;
		st[e].f += f;
		st[e^1].f -= f;
		a -= f;
		if (!a) break;
	}
	if (!fl) lv[u] = 0;
	return fl;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d%d", &n, &m, &d);
	S = zip(n, m)*2 + 1, T = S + 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%1d", &h[i][j]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		char s[N];
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) l[i][j] = s[j] == 'L', ans+=l[i][j];
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			if (l[i][j])  add(S, zip(i, j), 1);
				for (int ii = max(1, i - d); ii <= min(i + d, n); ii++)
					for (int jj = max(1, j - d); jj <= min(j + d, m); jj++) if (h[ii][jj] && sq(i - ii) + sq(j - jj) <= d*d) 
						if (zip(i, j) != zip(ii, jj)) add(zip(i, j) + n*m, zip(ii, jj), INF);

			if (i - d <= 0 || i + d > n || j - d <= 0 || j + d > m) if (h[i][j]) add(zip(i, j) + n*m, T, INF);
			if (h[i][j]) add(zip(i, j), zip(i, j) + n*m, h[i][j]);
		}
	while (bfs()) {
		ans -= dfs(S, INF);
	}
	printf("%d\n", ans);
}
