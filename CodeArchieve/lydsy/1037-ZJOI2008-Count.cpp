#include <cstdio>
#include <algorithm>
#include <cstring>
#define file(x) "bzoj_1036."#x
#define lch (o << 1)
#define rch (o << 1 | 1)
#define mid ((l + r) >> 1)
#define fore for (int e = hed[u], v; v = st[e].v, e; e = nxt[e])
using std::max;
const int V = 3e4 + 10, E = V << 1, INF = 0x3f3f3f3f;
struct EDGE{int u, v;}st[E];
int n, w[V], hed[V], nxt[E], clk, dfn[V], sz[V], son[V], fa[V], s[V << 3], mx[V << 3], dep[V], top[V];
inline void _add(int u, int v) {
	static int sz = 0;
	st[++sz] = (EDGE){u, v};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v) {
	_add(u, v), _add(v, u);
}
int dfs(int u) {
	sz[u] = 1;
	fore if (v != fa[u]) {
		fa[v] = u;
		dep[v] = dep[u] + 1;
		sz[u] += dfs(v);
		if (sz[v] > sz[son[u]]) son[u] = v;
	}
	return sz[u];
}
void dfs2(int u, int nt) {
	top[u] = nt;
	dfn[u] = ++clk;
	if (son[u]) dfs2(son[u], nt);
	fore if (v != fa[u] && v != son[u]) dfs2(v, v);
}
int q1, q2;
inline void up(int o) {
	mx[o] = max(mx[lch], mx[rch]);
	s[o] = s[lch] + s[rch];
}
void change(int o, int l, int r) {
	if (l == r) s[o] = mx[o] = q2;
	else {
		if (q1 <= mid) change(lch, l, mid);
		else change(rch, mid + 1, r);
		up(o);
	}
}
int qmax(int o, int l, int r) {
	if (q1 <= l && r <= q2) return mx[o];
	int x = -INF;
	if (q1 <= mid) x = max(x, qmax(lch, l, mid));
	if (q2 > mid) x = max(x, qmax(rch, mid + 1, r));
	return x;
}
int qsum(int o, int l, int r) {
	if (q1 <= l && r <= q2) return s[o];
	int x = 0;
	if (q1 <= mid) x += qsum(lch, l, mid);
	if (q2 > mid) x += qsum(rch, mid + 1, r);
	return x;
}
char cmd[20];
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	memset(mx, 0xc0, sizeof mx);
	for (int i = 1; i <= n; i++) scanf("%d", w + i);
	dfs(1), dfs2(1, 1);
	for (int i = 1; i <= n; i++) q1 = dfn[i], q2 = w[i], change(1, 1, n);
	int q; scanf("%d", &q);
	while (q--) {
		scanf("%s%d%d", cmd, &q1, &q2);
		if (cmd[0] == 'C') q1 = dfn[q1], change(1, 1, n);
		else if (cmd[1] == 'M') {
			int x = q1, y = q2, ans = -INF;
			while (top[x] != top[y]) {
				if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
				q1 = dfn[top[x]], q2 = dfn[x];
				ans = max(ans, qmax(1, 1, n));
				x = fa[top[x]];
			}
			if (dep[x] < dep[y]) std::swap(x, y);
			q1 = dfn[y], q2 = dfn[x];
			ans = max(ans, qmax(1, 1, n));
			printf("%d\n", ans);
		}
		else if (cmd[1] == 'S') {
			int x = q1, y = q2, ans = 0;
			while (top[x] != top[y]) {
				if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
				q1 = dfn[top[x]], q2 = dfn[x];
				ans += qsum(1, 1, n);
				x = fa[top[x]];
			}
			if (dep[x] < dep[y]) std::swap(x, y);
			q1 = dfn[y], q2 = dfn[x];
			ans += qsum(1, 1, n);
			printf("%d\n", ans);
		}
	}
}
