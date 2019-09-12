#include <cstdio>
#include <vector>
#include <cstring>
#define lch (o<<1)
#define rch ((o<<1)|1)
#define mid ((l+r)>>1)
const int N = 1e5 + 10, V = N << 2;
int n, m, co[N], fa[N], sz[N], son[N], top[N], sa[N], clk, dfn[N], dep[N], ct[V];
std::vector<int> to[N];
struct Node {int lc, rc, num;
	Node(int a = 0, int b = 0, int c = 0):lc(a), rc(b), num(c) {;}
}st[V];
inline Node merge(Node a, Node b) {
	if (!a.num) std::swap(a, b);
	return b.num ? (Node){a.lc, b.rc, a.num + b.num - (a.rc == b.lc)} : a;
}
void dfs(int u) {
	sz[u] = 1;
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (v == fa[u]) continue;
		dep[v] = dep[u] + 1;
		fa[v] = u;
		dfs(v);
		sz[u] += sz[v];
		if (sz[v] > sz[son[u]]) son[u] = v;
	}
}
void dfs2(int u, int tt) {
	top[u] = tt;
	sa[dfn[u] = ++clk] = u;
	if (son[u]) dfs2(son[u], tt);	
	for (int i = 0 ; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
void mkct(int o, int x) {
	if (!o) return;
	ct[o] = x;
	st[o] = (Node){x, x, 1};
}
inline void up(int o) {
	st[o] = merge(st[lch], st[rch]);
}
inline void down(int o) {
	if (~ct[o]) mkct(lch, ct[o]), mkct(rch, ct[o]), ct[o] = -1;
}
void build(int o, int l, int r) {
	if (l == r) {
		st[o].lc = st[o].rc = co[sa[l]];
		st[o].num = 1;
		return;
	}
	build(lch, l, mid);
	build(rch, mid + 1, r);
	up(o);
}
void paint(int o, int l, int r, int q1, int q2, int q3) {
	if (q1 <= l && r <= q2) {
		mkct(o, q3);
		return;
	}
	down(o);
	if (q1 <= mid) paint(lch, l, mid, q1, q2, q3);
	if (mid < q2) paint(rch, mid + 1, r, q1, q2, q3);
	up(o);
}
Node query(int o, int l, int r, int q1, int q2) {
	if (q1 <= l && r <= q2) return st[o];
	Node ret;
	down(o);
	if (q1 <= mid) ret = merge(ret, query(lch, l, mid, q1, q2));
	if (mid < q2) ret = merge(ret, query(rch, mid + 1, r, q1, q2));
	return ret;
}
char cmd[10];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", co + i);
	for (int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		to[x].push_back(y);
		to[y].push_back(x);
	}
	dfs(1);
	dfs2(1, 1);
	memset(ct, -1, sizeof ct);
	build(1, 1, n);
	while (m--) {
		int u, v;
		scanf("%s%d%d", cmd, &u, &v);
		if (cmd[0] == 'C') {
			int c; scanf("%d", &c);
			while (top[u] != top[v]) {
				if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
				paint(1, 1, n, dfn[top[u]], dfn[u], c);
				u = fa[top[u]];
			}
			if (dep[u] < dep[v]) std::swap(u, v);
			paint(1, 1, n, dfn[v], dfn[u], c);
		}
		else {
			Node l, r;
			while (top[u] != top[v]) {
				if (dep[top[u]] > dep[top[v]]) {
					l = merge(query(1, 1, n, dfn[top[u]], dfn[u]), l);
					u = fa[top[u]];
				}
				else {
					r = merge(query(1, 1, n, dfn[top[v]], dfn[v]), r);
					v = fa[top[v]];
				}
			}
			if (dep[u] > dep[v]) l = merge(query(1, 1, n, dfn[v], dfn[u]), l);
			else r = merge(query(1, 1, n, dfn[u], dfn[v]), r);
			printf("%d\n", l.num + r.num - (l.lc == r.lc));
		}
	}
}
