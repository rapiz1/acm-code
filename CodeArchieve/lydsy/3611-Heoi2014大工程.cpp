#include <cstdio>
#include <algorithm>
#include <cctype>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
using std::min;
using std::max;
const int V = 1e6 + 10, K = 23, E = V << 1;
int n, m, k, kk, dfn[V], clk, ver[V], dep[V], anc[V][K], sk[V], top, sz[V];
bool inv[V];
typedef long long ll;
const ll inf = 1ll << 59;
namespace I {
	const int L = 1 << 15 | 1;
	char *s, *t, buf[L];
	inline int gc() {
		if (s == t) t = (s = buf) + fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int r = 0, ch;
		do ch = gc(); while (!isdigit(ch));
		for (;isdigit(ch); ch = gc()) r = r*10 + ch - '0';
		return r;
	}
}using I::gi;
struct Sol {
	ll mx, mn, sum;
	Sol() {
		mx = -inf, mn = inf, sum = 0;
	}
}ans;
struct Graph {
	int hed[V], nxt[E], esz;
	struct Edge{int u, v, w;}st[E];
	inline void add(int u, int v, int w) {
		st[++esz] = (Edge){u, v, w};
		nxt[esz] = hed[u], hed[u] = esz;
	}
	void dfs(int u) {
		for (int i = 1; i < K; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
		dfn[u] = ++clk;
		fore if (v != anc[u][0]) anc[v][0] = u, dep[v] = dep[u] + 1, dfs(v);
	}
	inline void init() {
		n = gi();
		for (int i = 1, u, v; i < n; i++) u = gi(), v = gi(), add(u, v, 0), add(v, u, 0);
		add(n + 1, 1, 0);
		dfs(n + 1);
	}
	inline void clear() {
		for (int i = 1; i <= kk; i++) hed[ver[i]] = 0;
		for (int i = 1; i <= esz; i++) st[i] = (Edge){0, 0, 0};
		esz = 0;
	}
	Sol solve(int u) {
		Sol ret;
		sz[u] = inv[u];
		fore {
			Sol tmp = solve(v);
			if (tmp.mn != inf) tmp.mn += st[e].w;
		 	if (tmp.mx != -inf) tmp.mx += st[e].w;
			if (inv[v]) {
				tmp.mn = std::min(tmp.mn, (ll)st[e].w);
			 	tmp.mx = std::max(tmp.mx, (ll)st[e].w);
			}
			tmp.sum += (ll)sz[v]*st[e].w;
			if (tmp.mn != inf && ret.mn != inf) ans.mn = min(ans.mn, tmp.mn + ret.mn);
			if (tmp.mx != -inf && ret.mx != -inf) ans.mx = max(ans.mx, tmp.mx + ret.mx);
			ans.sum += (ll)sz[u]*tmp.sum + (ll)sz[v]*ret.sum;
			ret.mn = min(tmp.mn, ret.mn);
			ret.mx = max(tmp.mx, ret.mx);
			ret.sum += tmp.sum;
			sz[u] += sz[v];
		}
		if (inv[u]) ans.mn = min(ans.mn, ret.mn), ans.mx = max(ans.mx, ret.mx);
		return ret;
	}
}g, vir;
inline int lca(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u, v);
	for (int x = dep[u] - dep[v], i = 0; x; i++, x>>=1) 
		if (x&1) u = anc[u][i];
	for (int i = K - 1; ~i; i--) if (anc[u][i] != anc[v][i])
		u = anc[u][i], v = anc[v][i];
	return u == v ? u : anc[u][0];
}
int cmp(int a, int b) {return dfn[a] < dfn[b];}
int main() {
//	freopen("input", "r", stdin);
	g.init();
	g.dfs(n + 1);
	m = gi();
	while (m--) {
		kk = k = gi();
		ans = Sol();
		for (int i = 1; i <= k; i++) inv[ver[i] = gi()] = 1;
		std::sort(ver + 1, ver + 1 + k, cmp);
		top = 0;
		sk[++top] = ver[++kk] = n + 1;
		for (int i = 1; i <= k; i++) {
			int u = ver[i], v = sk[top], w = lca(u, v);
			if (v == w) sk[++top] = u;
			else {
				while (top > 1 && dep[sk[top - 1]] >= dep[w])
					vir.add(sk[top -1], sk[top], dep[sk[top]] - dep[sk[top - 1]]), top--;
				if (sk[top] != w) {
					vir.add(w, sk[top], dep[sk[top]] - dep[w]);
					top--;
					sk[++top] = ver[++kk] = w;
				} 
				sk[++top] = u;
			}
		}
		for(;top > 1;top--) vir.add(sk[top - 1], sk[top], dep[sk[top]] - dep[sk[top - 1]]);
		vir.solve(n + 1);
		vir.clear();
		for (int i = 1; i <= k; i++) inv[ver[i]] = 0;
		printf("%lld %lld %lld\n",  ans.sum, ans.mn, ans.mx);
	}
}
