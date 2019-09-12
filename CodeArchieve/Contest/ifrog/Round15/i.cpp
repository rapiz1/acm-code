#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
const int N = 510, V = N << 1, E = (N*N + V)*2;
int n, m, k, a[N], c[N], f[N];
bool ff[N][N];
int hed[V], nxt[E], s, t, sz, lv[V];
std::queue<int> q;
struct Edge{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (Edge){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz; }
inline void add(int u, int v, int c) {
	_add(u, v, c), _add(v, u, 0);
}
bool bfs() {
	memset(lv, 0, sizeof lv);
	q.push(s);
	lv[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) if (st[e].c > st[e].f && !lv[v]){
			lv[v] = lv[u] + 1;
			q.push(v);
		}
	}
	return lv[t];
}
int dfs(int u, int a) {
	if (u == t) return a;
	int f, fl = 0;
	for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(st[e].c - st[e].f, a)))) {
		fl += f;
		st[e].f += f;
		st[e^1].f -= f;
		a -= f;
		if (!a) break;
	}
	return fl;
}
void solve() {
	memset(ff, 0, sizeof ff);
	memset(hed, 0, sizeof hed);
	memset(f, 0, sizeof f);
	memset(st, 0, sizeof st);
	sz = 1;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), ff[u][v] = 1;
	for (int i = 1; i <= n; i++) ff[i][i] = 1;
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		ff[i][j] = ff[i][j] || (ff[i][k] && ff[k][j]);
	s = 2*n + 1, t = s + 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j && ff[i][j]) {
		add(i + n, j, 1);
	}
	for (int i = 1; i <= n ;i++) add(s, i + n, 1), add(i, t, 1);
	int tt = 0;
	while (bfs()) tt += dfs(s, 1e9);
	for (int i = 1; i <= k; i++) scanf("%d%d", a + i, c + i);
	tt = n - tt;
	for (int i = 1; i <= n; i++) for (int j = m; j; j--) if (j >= a[i])
		f[j] = std::max(f[j], f[j - a[i]] + c[i]);
	int ans = -1;
	for (int j = 1; j <= m; j++) if (f[j] >= tt) {ans = j;break;}
	printf("%d\n", ans);
}
int main(){
	freopen("input", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}
