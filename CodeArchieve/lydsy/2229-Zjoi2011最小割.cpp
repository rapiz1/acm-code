#include <cstdio>
#include <vector>
#include <cassert>
#include <queue>
#include <cstring>
#include <algorithm>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
#define file "mincuto."
const int V = 200, E = 6010;
int n, m, fl[V][V], hed[V], nxt[E], sz = 1, lv[V], S, T;
struct Edge{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
	st[++sz] = (Edge){u, v, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int c) {
	_add(u, v, c), _add(v, u, c);
}
std::queue<int> q;
bool bfs() {
	memset(lv, 0, sizeof lv);
	q.push(S);
	lv[S] = 1;
	while (!q.empty()) {
		int u = q.front();q.pop();
		fore(u) if (st[e].c >  st[e].f && !lv[v]) {
			q.push(v);
			lv[v] = lv[u] + 1;
		}
	}
	return lv[T];
}
int dfs(int u, int a) {
	if (u == T || !a) return a;
	int fl=0, f;
	fore(u) if (st[e].c > st[e].f && lv[v] == lv[u] + 1 && (f = dfs(v, std::min(st[e].c - st[e].f, a)))) {
		a -= f;
		st[e].f += f;
		st[e^1].f -= f;
		fl += f;
		if (!a) break;
	}
	if (!fl) lv[u] = 0;
	return fl;
}
int ver[V], tmp[V];
int flow(int x, int y) {
	S = x, T = y;
	for (int i = 1; i <= sz; i++) st[i].f=0;
	int fl = 0;
	while (bfs()) fl += dfs(S, 1e9);
	return fl;
}
void work(int l, int r) {
	if (l == r) return;
	S = ver[l], T = ver[r];
	for (int i = 1; i <= sz; i++) st[i].f = 0;
	int s = 0;
	while (bfs()) s += dfs(S, 1e9);
	int q1 = l, q2 = r;
	for (int i = l; i <= r; i++) if (lv[ver[i]]) tmp[q1++] = ver[i];
	else tmp[q2--] = ver[i];
	for (int i = l; i <= r; i++) ver[i] = tmp[i];
	for (int i = 1; i <= n; i++) if (lv[i]) for (int j = 1; j <= n; j++) if (!lv[j])
		fl[i][j] = std::min(fl[i][j],s);
	work(l, q2), work(q1, r);
}
inline void solve() {
	sz = 1;
	memset(st, 0, sizeof st);
	memset(hed, 0, sizeof hed);
	memset(fl, 0x3f, sizeof fl);
	scanf("%d%d", &n, &m);
	for (int i = 1; i<= m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		add(u, v, c);
	}
	for (int i = 1; i <= n; i++) ver[i] = i;
	work(1, n);
	int q; scanf("%d", &q);
	while (q--) {
		int x; scanf("%d", &x);
		int re = 0;
		for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
			re += std::min(fl[i][j], fl[j][i]) <= x;
		}
		printf("%d\n", re);
	}
	puts("");
}
int main() {
//	freopen("input", "r", stdin);
//	freopen(file"in", "r", stdin);
//	freopen(file"out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) solve();
}
