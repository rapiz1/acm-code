#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
const int N = (1e5 + 10)*17, V = 1e5 + 10, K = 20;
namespace I {
	const int L = 1 << 15 | 1;
	char* s, *t, buf[L];
	inline char gc() {
		if (s == t) t = (s = buf) + fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int x;
		scanf("%d", &x);
		return x;
	}
}using I::gi;
int n, m, hed[V], nxt[V << 1], w[V], anc[V][K], ans, sz, rt[V], val[N], ch[N][2], dep[V];
namespace Lisan {
	inline bool cmp(int i, int j) {return w[i] < w[j];}
	int tot, rev[V], th[V];
	inline void work() {
		for (int i = 1; i <= n; i++) th[i] = i;
		std::sort(th + 1, th + 1 + n, cmp);
		for (int i = 1; i <= n;) {
			int j = i;
			while (j + 1 <= n && w[th[j]] == w[th[j + 1]]) j++;
			rev[++tot] = w[th[i]];
			while (i <= j) w[th[i++]] = tot;
		}
	}
};
struct EDGE{int u, v;}st[V << 1];
inline void _add(int u, int v) {
	static int sz = 0;
	st[++sz] = (EDGE){u, v};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v) {
	_add(u, v), _add(v, u);
}
inline void up(int o) {
	val[o] = val[ch[o][0]] + val[ch[o][1]];
}
int q1, q2;
int lca(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u, v);
	for (int d = dep[u] - dep[v], k = 0; d; k++, d >>= 1) if (d&1) u = anc[u][k];
	for (int k = K - 1; k >= 0; k--) if (anc[u][k] != anc[v][k]) u = anc[u][k], v = anc[v][k];
	return u == v ? u : anc[u][0];
}
int change(int p, int l, int r) {
	int o = ++sz;
	memcpy(ch[o], ch[p], sizeof(ch[o]));
	if (l == r) {
		val[o] = val[p] + q2;	
		return o;
	}
	int mid = (l + r) >> 1;
	if (q1 <= mid) ch[o][0] = change(ch[p][0], l, mid);
	else ch[o][1] = change(ch[p][1], mid + 1, r);
	up(o);
	return o;
}
void build(int u) {
	q1 = w[u], q2 = 1;
	rt[u] = change(rt[anc[u][0]], 1, n);
	for (int i = 1; i < K; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (v != anc[u][0]){
		anc[v][0] = u;
		dep[v] = dep[u] + 1;
		build(v);
	}
}
int query(int u, int v, int k) {
	int a[4];
	a[0] = u, a[1] = v, a[2] = lca(u, v), a[3] = anc[a[2]][0];
	for (int i = 0; i < 4; i++) a[i] = rt[a[i]];
	int l = 1, r = n;
	while (l != r) {
		int res = val[ch[a[0]][0]] + val[ch[a[1]][0]] - val[ch[a[2]][0]] - val[ch[a[3]][0]];
		if (k <= res) {
			for (int i = 0; i < 4; i++) a[i] = ch[a[i]][0];
			r = l + r >> 1;
		}
		else {
			k -= res;
			for (int i = 0; i < 4; i++) a[i] = ch[a[i]][1];
			l = (l + r >> 1) + 1;
		}
	}
	return l;
}
int main() {
	n = gi(), m = gi();
	for (int i = 1; i <= n; i++) w[i] = gi();
	Lisan::work();
	for (int i = 1; i < n; i++) add(gi(), gi());
	build(1);
	while (m--) {
		int u = gi(), v = gi(), k = gi();
		u = ans^u;
		printf("%d", ans = Lisan::rev[query(u, v, k)]);
		if (m) putchar('\n');
	}
}
