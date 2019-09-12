#include <cstdio>
#include <algorithm>
#define file(x) "bzoj_2733." #x
#define lch ch[o][0]
#define rch ch[o][1]
const int N = 2e6 + 10;
int n, q, m, ch[N][2], st[N], w[N], fa[N], nsz, p[N], rt[N], sz[N], be[N];
inline int gd(int o) {return ch[fa[o]][1] == o;}
inline void up(int o) {
	sz[o] = sz[lch] + sz[rch] + 1;
}
inline void lk(int x, int y, int d) {
	if (x) fa[x] = y;
	if (y) ch[y][d] = x;
}
inline void rot(int o) {
	int d = gd(o), x = fa[o];
	lk(o, fa[x], gd(x));
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	up(x), up(o);
	if (be[x]) be[o] = be[x], be[x] = 0, rt[be[o]] = o;
}
inline void splay(int o) {
//	return;
	for (int x; x = fa[o]; rot(o))
		if (fa[x]) rot(gd(o) == gd(x) ? x : o);
}
inline int kth(int o, int k) {
	while (k != sz[lch] + 1) {
		if (k <= sz[lch]) o = lch;
		else k -= sz[lch] + 1, o = rch;
	}
	splay(o);
	return o;
}
inline int mknd(int v) {
	st[++nsz] = v;
	sz[nsz] = 1;
	return nsz;
}
inline void in(int o, int v) {
	int d = w[v] >= w[st[o]];
	if (ch[o][d]) in(ch[o][d], v);
	else ch[o][d] = mknd(v);
	up(o);
}
int tar;
void lmr(int o) {
	if (ch[o][0]) lmr(ch[o][0]);
	in(tar, st[o]);
	splay(nsz);
	if (ch[o][1]) lmr(ch[o][1]);
}
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
inline void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[rt[x]] < sz[rt[y]]) std::swap(x, y);
	p[y] = x;
	tar = rt[x];
	lmr(rt[y]);
}
char cmd[5];
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		rt[i] = mknd(i);
		be[i] = i;
		p[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		merge(x, y);
	}
	scanf("%d", &q);
	while (q--) {
		int x, y;scanf("%s%d%d", cmd, &x, &y);
		if (cmd[0] == 'Q') {
			x = find(x);
			printf("%d\n", sz[rt[x]] >= y ? st[kth(rt[x], y)] : -1);
		}
		else merge(x, y);
	}
}
