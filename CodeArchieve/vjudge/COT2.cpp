#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
const int V = 40010, E = V << 1, L = 21, MXQ = 1e5 + 10;
int n, m, hed[V], nxt[E], bk, dep[V], anc[V][L], dfn[E], ss[V], ee[V], clk, w[V], nans, cnt[V], ans[MXQ], th[V];
bool in[V];
struct EDGE{int u, v;}st[E];
struct Q{int u, v, c, i;
	bool operator<(const Q& b)const {return u/bk < b.u/bk || (u/bk == b.u/bk && v < b.v);}
}qu[MXQ];
inline void _add(int u, int v) {
	static int sz = 0;
	st[++sz] = (EDGE){u, v};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v) {
	_add(u, v), _add(v, u);
}
void dfs(int u) {
	dfn[ss[u] = ++clk] = u;
	for (int i = 1; i < L; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1 ];
	for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (v != anc[u][0]) {
		dep[v] = dep[u] + 1;
		anc[v][0] = u;
		dfs(v);
	}
	dfn[ee[u] = ++clk] = u;
}
inline int lca(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u, v);
	for (int d = dep[u] - dep[v], k = 0; d; d >>= 1, k++)
		if (d&1) u = anc[u][k];
	for (int k = L - 1; k >= 0; k--) if (anc[u][k] != anc[v][k])
		u = anc[u][k], v = anc[v][k];
	return u == v ? u : anc[u][0];
}
inline void inc(int pos) {
	nans += cnt[w[dfn[pos]]]++==0;
} 
inline void dec(int pos) {
	nans -= --cnt[w[dfn[pos]]]==0;
}
inline void turn(int pos) {
	if (in[dfn[pos]]) dec(pos);
	else inc(pos);
	in[dfn[pos]] ^= 1;
}
bool thcmp(int a, int b) {return w[a] < w[b];}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	bk = sqrt(2*n);
	for (int i = 1; i <= n; i++) scanf("%d", w + i), th[i] = i;
	std::sort(th + 1, th + 1 + n, thcmp);	
	for (int i = 1, j = 0; i <= n;) {
		int k = i;
		while (k + 1 <= n && w[th[k]] == w[th[k + 1]]) k++;
		++j;
		while (i <= k) w[th[i++]] = j;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	dfs(1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		qu[i].c = lca(u, v);
		qu[i].i = i;
		if (v == qu[i].c) std::swap(u, v);
		if (u == qu[i].c) qu[i].u = ss[u], qu[i].v = ss[v];
		else {
			if (ss[u] > ss[v]) std::swap(u, v);
			qu[i].u = ee[u], qu[i].v = ss[v];
		}
	}
	std::sort(qu + 1, qu + 1 + m);
	int l = 1, r = 1;
	nans = 1;
	cnt[w[dfn[1]]]++;
	in[dfn[1]] = 1;
	for (int i = 1; i <= m; i++) {
		int ll = qu[i].u, rr = qu[i].v;
		while (l > ll) turn(--l);
		while (r < rr) turn(++r);
		while (l < ll) turn(l++);
		while (r > rr) turn(r--);
		inc(ss[qu[i].c]);
		ans[qu[i].i] = nans;		
		dec(ss[qu[i].c]);
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
