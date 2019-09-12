#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 80010, W = 1e8, K = 18;
int n, q, dfn[N], a[N], clk, sz[N], dep[N], anc[N][K];
std::vector<int> to[N], li;
namespace Seg {
struct Node {
	int s;
	Node* ch[2];
	Node() {ch[0] = ch[1] = 0, s = 0;}
}*rt[N];
void add(Node*& o, int l, int r, int x, int v) {
	if (!o) o = new Node();
	o->s += v;
	if (l != r) {
		int mid = (l + r) >> 1;
		if (x <= mid) add(o->ch[0], l, mid, x, v);
		else add(o->ch[1], mid + 1, r, x, v);
	}
	if (o->s == 0) {Node*x = o; o = 0; delete x;}
}
int query(Node* o, int l, int r, int ll, int rr) {
	if (!o) return 0;
	if (ll <= l && r <= rr) return o->s;
	int ret = 0, mid = (l + r) >> 1;
	if (ll <= mid)  ret += query(o->ch[0], l, mid, ll, rr);
	if (mid < rr) ret += query(o->ch[1], mid + 1, r, ll, rr);
	return ret;
}
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u, v);
	for (int d = dep[u] - dep[v], i = 0; i < K; i++) 
		if(d>>i&1) u = anc[u][i];
	for (int i = K - 1; ~i; i--) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	return u == v ? u : anc[u][0];
}
namespace BIT {
	inline void add(int p, int x, int d) {
		for (;p<=n;p+=p&-p) Seg::add(Seg::rt[p], 0, W, x, d);
	}
	inline int pre(int p, int x, int y) {
		int ret = 0;
		for (;p; p-=p&-p) 
			ret += Seg::query(Seg::rt[p], 0, W, x, y);
		return ret;
	}
	void query(int u, int v, int k) {
		int w = lca(u, v), x = dfn[u], y = dfn[v], z = dfn[anc[w][0]], zz = dfn[w];
		int l = -1, r = W;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (pre(x, mid, W) + pre(y, mid, W) - pre(z, mid, W) - pre(zz, mid, W) >= k) l = mid;
			else r = mid - 1;
		}
		if (l == -1) puts("invaild request!");
		else printf("%d\n", l);
	}
}
void dfs(int u) {
	dfn[u] = ++clk;
	sz[u] = 1;
	for (int i = 1; i < K; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (v == anc[u][0]) continue;
		dep[v] = dep[u] + 1;
		anc[v][0] = u;
		dfs(v);
		sz[u] += sz[v];
	}
	BIT::add(dfn[u], a[u], 1);
	BIT::add(dfn[u] + sz[u], a[u], -1);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		li.push_back(a[i]);
	}
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), to[u].push_back(v), to[v].push_back(u);
	dfs(1);
	while (q--) {
		int k, u, v;
		scanf("%d%d%d", &k, &u, &v);
		if (k) BIT::query(u, v, k);
		else {
			BIT::add(dfn[u], a[u], -1);
			BIT::add(dfn[u] + sz[u], a[u], 1);
			a[u] = v;
			BIT::add(dfn[u], a[u], 1);
			BIT::add(dfn[u] + sz[u], a[u], -1);
		}
	}
}
