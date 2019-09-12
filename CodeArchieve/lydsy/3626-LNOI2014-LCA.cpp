#include <cstdio>
#include <vector>
#include <algorithm>
#define lch (o << 1)
#define rch ((o << 1)|1)
#define mid ((l + r)>>1)
const int N = 50010, V = N << 2;
typedef long long ll;
const ll MOD = 201314;
int n, q, dfn[N], clk, top[N], son[N], sz[N], fa[N], dep[N];
ll val[V], adv[V], ans[N];
struct QUERY{int f, u, id;};
std::vector<int> to[N];
std::vector<QUERY> qu[N];
int dfs(int u) {
	for (int i = 0, v; i < (int)to[u].size(); i++) if ((v = to[u][i]) != fa[u]) {
		dep[v] = dep[u] + 1;
		sz[u] += dfs(v);
		if (sz[v] > sz[son[u]]) son[u] = v;
	} 
	return ++sz[u];
}
void split(int u, int tt) {
	dfn[u] = ++clk;
	top[u] = tt;
	if (son[u]) split(son[u], tt);
	for (int i = 0, v; i < (int)to[u].size(); i++) if ((v = to[u][i]) != fa[u] && v != son[u]) split(v, v);
}
inline void mkad(int o, int l, int r, ll v) {if (o) (val[o] += v*(r - l + 1ll))%=MOD, (adv[o] += v)%=MOD;}
inline void down(int o, int l, int r) {
	if (adv[o]) mkad(lch, l, mid, adv[o]), mkad(rch, mid + 1, r, adv[o]), adv[o] = 0;
}
void up(int o) {val[o] = (val[lch] + val[rch])%MOD;}
void add(int o, int l, int r, int q1, int q2, int v) {
	if (q1 <= l && r <= q2)	mkad(o, l, r, v); 
	else {
		down(o, l, r);
		if (q1 <= mid) add(lch, l, mid, q1, q2, v);
		if (mid < q2) add(rch, mid + 1, r, q1, q2, v);
		up(o);
	}
}
int query(int o, int l, int r, int q1, int q2) {
	if (q1 <= l && r <= q2) return val[o];
	down(o, l, r);
	int ret = 0;
	if (q1 <= mid) (ret += query(lch, l, mid, q1, q2))%=MOD;
	if (mid < q2) (ret += query(rch, mid + 1, r, q1, q2))%=MOD;
	return ret;
}
/*
void inc_path(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
		add(1, 1, n, dfn[top[u]], dfn[u], 1);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) std::swap(u, v);
	add(1, 1, n, dfn[v], dfn[u], 1);
}
*/
inline void inc(int u) {
	for (;u; u = fa[top[u]]) add(1, 1, n, dfn[top[u]], dfn[u], 1);
}
inline int sum(int u) {
	int ret = 0;
	for (;u; u = fa[top[u]]) (ret += query(1, 1, n, dfn[top[u]], dfn[u]))%=MOD;
	return ret;
}
int adj(ll x) {return x > 0 ? x : (x + (-x + MOD - 1)/MOD*MOD)%MOD;}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++) scanf("%d", fa + i), fa[i]++, to[fa[i]].push_back(i), to[i].push_back(fa[i]);
	dfs(1), split(1, 1);
	for (int i = 1, l, r, z; i <= q; i++) scanf("%d%d%d", &l, &r, &z), l++, r++, z++, qu[r].push_back((QUERY){1, z, i}), qu[l - 1].push_back((QUERY){-1, z, i});
	for (int i = 1; i <= n; i++) {
		inc(i);
		for (int j = 0; j < (int)qu[i].size(); j++) ans[qu[i][j].id] += qu[i][j].f*sum(qu[i][j].u);
	}
	for (int i = 1; i <= q; i++) printf("%d\n", adj(ans[i]));
}
