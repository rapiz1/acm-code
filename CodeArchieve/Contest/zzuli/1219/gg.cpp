#include <cstdio>
#include <cstring>
#include <algorithm>
#define lch (o << 1)
#define rch ((o<<1)|1)
#define mid ((l + r)>>1)
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
using std::max;
using std::min;
const int V = 5e5 + 10, E = V << 1, INF = 0x3f3f3f3f;
int n, m, hed[V], nxt[E], esz, clk, dfn[V], top[V], dep[V], son[V], fa[V], sz[V], faw[V], rev[V];
struct Node {
	int mx, mmx, mn, bb;
	Node(int x = -1) {
		if (x >= 0) {
			mx = mn = x;
			mmx = -1;
		}
		else mx = mmx = -1, mn = INF;
		bb = -1;
	}
	friend Node operator+(const Node&, const Node&);
	inline bool vaild() {
		if (mmx == -1) return 0;
		return (long long)mx + mmx > mn;
	}
}nd[V << 2];
Node operator+(const Node& a, const Node& b) {
	Node c;
	if (c.mx < a.mx) c.mx = a.mx, c.bb = 0;
	if (c.mx < b.mx) c.mx = b.mx, c.bb = 1;
	if (c.mmx < a.mx && c.bb != 0) c.mmx = a.mx;
	if (c.mmx < b.mx && c.bb != 1) c.mmx = b.mx;
	c.mmx = max(c.mmx, max(a.mmx, b.mmx));
	c.mn = min(a.mn, b.mn);
	return c;
}
struct Edge{int u, v, w;}st[E];
void _add(int u, int v, int w) {
	st[++esz] = (Edge){u, v, w};
	nxt[esz] = hed[u], hed[u] = esz;
}
void add(int u, int v, int w) {_add(u, v, w), _add(v, u, w);}
int dfs(int u) {
	sz[u] = 1;
	fore(u) if (v != fa[u]) {
		dep[v] = dep[u] + 1, fa[v] = u, sz[u] += dfs(v);
		faw[v] = st[e].w;
		if (sz[son[u]] < sz[v]) son[u] = v;
	}
	return sz[u];
}
void dfs(int u, int tt) {
	top[u] = tt;
	rev[dfn[u] = ++clk] = u;
	if (son[u]) dfs(son[u], tt);
	fore(u) if (v != fa[u] && v != son[u]) dfs(v, v);
}
void build(int o, int l, int r) {
	if (l == r) nd[o] = Node(faw[rev[l]]);
	else build(lch, l, mid), build(rch, mid + 1, r), nd[o] = nd[lch] + nd[rch];
}
Node query(int o, int l, int r, int q1, int q2) {
	if (q1 <= l && r <= q2) return nd[o];
	else {
		Node ret;
		if (q1 <= mid) ret = ret + query(lch, l, mid, q1, q2);
		if (mid < q2) ret = ret + query(rch, mid + 1, r, q1, q2);
		return ret;
	}
}
void solve() {
	memset(hed, 0, sizeof hed);
	memset(son, 0, sizeof son);
	while (esz) st[esz--] = (Edge){0};
	clk = 0;
	scanf("%d", &n);
	for (int i = 1, u, v, w; i < n; i++) scanf("%d%d%d", &u, &v, &w), add(u, v, w);
	dfs(1);
	dfs(1, 1);
	build(1, 1, n);
	scanf("%d", &m);
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		Node ans;
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
			ans = ans + query(1, 1, n, dfn[top[u]], dfn[u]);
			u = fa[top[u]];
		}
		if (dep[u] < dep[v]) std::swap(u, v);
		if (u != v) ans = ans + query(1, 1, n, dfn[son[v]], dfn[u]);
		puts(ans.vaild() ? "Yes" : "No");
	}
}
int main() {
	freopen("input", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
