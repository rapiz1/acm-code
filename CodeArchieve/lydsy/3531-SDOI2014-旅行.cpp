#include <cstdio>
#include <cstring>
#include <algorithm>
#define mid ((l + r)>>1)
#define fore for (int e = hed[u], v; v = st[e].v, e; e = nxt[e])
using std::max;
const int N = 1e5 + 10;
struct ND{
	ND* ch[2];
	int s, mx;
	ND(int _s = 0){s = mx = _s;ch[0]=ch[1]=NULL;} 
	inline void up() {
		mx = s = 0;
		if (ch[0]) mx = max(mx, ch[0]->mx), s += ch[0]->s;
		if (ch[1]) mx = max(mx, ch[1]->mx), s += ch[1]->s;
	}
}*seg[N];
int q1, q2;
void change(ND*& o, int l, int r) {
	if (o == NULL) o = new ND;
	if (l == r) o->s = o->mx = q2;
	else {
		if (q1 <= mid) change(o->ch[0], l, mid);
		else change(o->ch[1], mid + 1, r);
		o->up();
	}
}
int qsum(ND*& o, int l, int r) {
	if (o == NULL) return 0;
	if (q1 <= l && r <= q2) return o->s;
	int x = 0;
	if (q1 <= mid) x += qsum(o->ch[0], l, mid);
	if (q2 > mid) x += qsum(o->ch[1], mid + 1, r);
	return x;
}
int qmax(ND*& o, int l, int r) {
	if (o == NULL) return 0;
	if (q1 <= l && r <= q2) return o->mx;
	int x = 0;
	if (q1 <= mid) x = max(x, qmax(o->ch[0], l, mid));
	if (q2 > mid) x = max(x, qmax(o->ch[1], mid + 1, r));
	return x;
}
int n, q, w[N], c[N], clk, dfn[N], hed[N], nxt[N << 1], sz[N], son[N], dep[N], top[N], fa[N];
struct EDGE{int u, v;}st[N << 1];
inline void _add(int u, int v) {
	static int sz = 0;
	st[++sz] = (EDGE){u, v};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v) {_add(u, v), _add(v, u);}
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
	dfn[u] = ++clk;
	top[u] = nt;
	if (son[u]) dfs2(son[u], nt);
	fore if (v != fa[u] && v != son[u]) dfs2(v, v);
}
char cmd[5];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d%d", w + i, c + i);
	for (int i = 1; i < n; i++) {
		int u, v;scanf("%d%d", &u, &v);
		add(u, v);
	}
	dfs(1), dfs2(1, 1);
	for (int i = 1; i <= n; i++) q1 = dfn[i], q2 = w[i], change(seg[c[i]], 1, n);
	while (q--) {
		int x, y;
		scanf("%s%d%d", cmd, &x, &y);
		if (cmd[1] == 'C') {
			q1 = dfn[x];
			q2 = 0;
			change(seg[c[x]], 1, n);
			q2 = w[x];
			change(seg[c[x] = y], 1, n);
		}
		else if (cmd[1] == 'W') {
			q1 = dfn[x], q2 = w[x] = y;
			change(seg[c[x]], 1, n);
		}
		else if (cmd[1] == 'S') {
			int ans = 0, cc = c[x];
			while (top[x] != top[y]) {
					if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
					q1 = dfn[top[x]], q2 = dfn[x];
					ans += qsum(seg[cc], 1, n);
					x = fa[top[x]];
			}
			if (dep[x] < dep[y]) std::swap(x, y);
			q1 = dfn[y], q2 = dfn[x];
			ans += qsum(seg[cc], 1, n);
			printf("%d\n", ans);
		}
		else if (cmd[1] == 'M') {
			int ans = 0, cc = c[x];
			while (top[x] != top[y]) {
					if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
					q1 = dfn[top[x]], q2 = dfn[x];
					ans = max(ans, qmax(seg[cc], 1, n));
					x = fa[top[x]];
			}
			if (dep[x] < dep[y]) std::swap(x, y);
			q1 = dfn[y], q2 = dfn[x];
			ans = max(ans, qmax(seg[cc], 1, n));
			printf("%d\n", ans);
		}
	}
}
