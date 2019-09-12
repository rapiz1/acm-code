#include <cstdio>
#include <vector>
typedef unsigned int uint;
const int N = 200010, K = 7;
const uint M = 1 << 31;
int n, q, sz[N], dfn[N], top[N], son[N], dep[N], clk, fa[N];
uint s[N << 2], ad[N << 2];
std::vector<int> to[N];
struct L {int u, v;
	inline void adj() {if (dep[u] < dep[v]) std::swap(u, v);}
}ll[K];
int dfs1(int u) {
	for (int i = 0, v; i < (int)to[u].size(); i++) if ((v = to[u][i])!=fa[u]) {
		dep[v] = dep[u] + 1;
		fa[v] = u;
		sz[u] += dfs1(v);
		if (sz[v] > sz[son[u]]) son[u] = v;
	}
	return ++sz[u];
}
void dfs2(int u, int tt) 	{
	dfn[u] = ++clk;
	top[u] = tt;
	if (son[u]) dfs2(son[u], tt);
	for (int i = 0, v; i< (int)to[u].size(); i++) 
		if ((v = to[u][i]) != fa[u] && v != son[u]) dfs2(v, v);
}
inline int lca(int u, int v) {
	for (;top[u] != top[v]; u = fa[top[u]]) if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
	return dep[u] < dep[v] ? u : v;
}
bool jiao(L& a, const L& b) {
	int u = lca(a.u, b.u), v = dep[a.v] > dep[b.v] ? a.v : b.v;
	if (dep[u] < dep[v]) return 0;
	a = (L){u, v};
	return 1;
}
void mkad(int o, int l, int r, uint x) {ad[o] = (ad[o] + x)%M, s[o] = (s[o] + (r - l + 1)*x%M)%M;}
void down(int o, int l, int r) {if (o) mkad(o<<1, l, l + r>>1, ad[o]), mkad(o<<1|1, (l + r>>1)+1, r, ad[o]), ad[o] = 0;}
uint query(int o, int l, int r, int q1, int q2) {
	if (q1 <= l && r <= q2) return s[o];
	down(o, l, r);
	int mid = l + r >> 1;
	uint ret = 0;
	if (q1 <= mid) ret = (ret + query(o<<1,l, mid, q1, q2))%M;
	if (q2 > mid) ret = (ret + query(o<<1|1, mid + 1, r, q1, q2))%M;
	return ret;
}
void change(int o, int l, int r, int q1, int q2, uint x) {
	if (q1 <= l && r <= q2) {
		mkad(o, l, r, x);
		return;
	}
	down(o, l, r);
	int mid = l + r >> 1;
	if (q1 <= mid) change(o<<1,l, mid, q1, q2, x);
	if (q2 > mid) change(o<<1|1, mid + 1, r, q1, q2, x);
	s[o] = (s[o<<1] + s[o<<1|1])%M;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), to[u].push_back(v), to[v].push_back(u);
	dfs1(1), dfs2(1, 1);
	scanf("%d", &q);
	while (q--) {
		int t;scanf("%d", &t);
		if (t) {
			int k;
			scanf("%d", &k);
			for (int i = 0; i < k; i++) scanf("%d%d", &ll[i].u, &ll[i].v), ll[i].adj();
			long long ret = 0;
			for (int s = 0; s < 1 << k; s++) {
				int cc = 0;
				bool em = 1;
				L nl;
				for (int j = 0; j < k; j++) if (s>>j&1) {
					cc++;
					if (em) nl = ll[j], em = 0;
					else if (!jiao(nl, ll[j])) {
						em = 1;
						break;
					}
				}
				if (em) continue;
				int u = nl.u, v = nl.v, fac = cc&1 ? 1:-1;	
				while (top[u] != top[v]) {
					if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
					int r = dfn[u], l = dfn[top[u]];
					ret = (ret + fac*query(1, 1, clk, l , r) + M)%M;
					u = fa[top[u]];
				}
				if (dep[u] < dep[v]) std::swap(u, v);
				ret = (ret + fac*query(1, 1, clk, dfn[v], dfn[u]) + M)%M;
			}
			printf("%lld\n", ret);
		}
		else {
			int u, d;scanf("%d%d", &u, &d);
			change(1, 1, clk, dfn[u], dfn[u] + sz[u] - 1, d);
		}
	}
}
