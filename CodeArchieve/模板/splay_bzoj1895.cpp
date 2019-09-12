#include <cstdio>
#include <algorithm>
#define lch ch[o][0]
#define rch ch[o][1]
using std::min;
const int N = 2e5 + 10;
int n, m, st[N], ch[N][2], adv[N], a[N], rt, nsz, fa[N], mn[N], sz[N], id[N];
bool flp[N];
char cmd[1000];
inline int gd(int o) {return ch[fa[o]][1] == o;}
inline void up(int o) {
	mn[o] = min(st[o], min(mn[lch], mn[rch]));
	sz[o] = sz[lch] + sz[rch] + 1;
}
inline void lk(int x, int y, int d) {
	if (y) ch[y][d] = x;
	if (x) fa[x] = y;
}
inline int cut(int o) {
	ch[fa[o]][gd(o)] = 0;
	fa[o] = 0;
	return o;
}
inline void rot(int o) {
	int x = fa[o], d = gd(o);
	lk(o, fa[x], gd(x));
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	up(x);
	up(o);
	if (x == rt) rt = o;
}
inline void mkadv(int o, int x) {
	if (!o) return;
	adv[o] += x, st[o] += x, mn[o] += x;
}
inline void mkflp(int o) {
	if (!o) return;
	flp[o] ^= 1;
	std::swap(lch, rch);
}
inline void down(int o) {
	if (adv[o]) mkadv(lch, adv[o]), mkadv(rch, adv[o]), adv[o] = 0;
	if (flp[o]) mkflp(lch), mkflp(rch), flp[o] = 0;
}
int build(int o, int l, int r) {
	int mid = l + r >> 1;
	st[o] = a[mid];
	id[o] = mid;
	if (l <= mid - 1) lk(build(++nsz, l, mid - 1), o, 0);
	if (mid + 1 <= r) lk(build(++nsz, mid + 1, r), o, 1);
	up(o);
	return o;
}
int kth(int o, int k) {
	while (k) {
		down(o);
		if (k == sz[lch] + 1) return o;
		else if (k <= sz[lch]) o = lch;
		else k -= sz[lch] + 1, o = rch; 
	}
	return o;
}
int splay(int o, int t) {
	while(fa[o] != t) {
		int x = fa[o];
		if (fa[x] != t) gd(o) == gd(x) ? rot(x) : rot(o);
		rot(o);
	}
	return o;
}
inline int subarr(int l, int r) {
	splay(kth(rt, l), 0);
	splay(kth(rt, r + 2), rt);
	return ch[ch[rt][1]][0];
}
inline int merge(int o, int t) {
	kth(t, 1);
	t = splay(kth(t, 1), fa[t]);
	lk(o, t, 0);
	up(t);
	return t;
}
inline void move(int o, int k) {
	k = sz[o] - k%sz[o];
	if (!k) return;
	o = splay(kth(o, k), fa[o]);
	int s = cut(ch[o][1]);
	up(o);
	merge(s, o);
}
int main() {
	scanf("%d", &n);
	mn[0] = 1e9;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	rt = build(++nsz, 0, n + 2);
	scanf("%d", &m);
	while (m--) {
		int l, r, v;
		scanf("%s", cmd);
		if (cmd[0] == 'D') {
			scanf("%d", &l);
			splay(kth(rt, l + 1), 0);
			rt = merge(cut(ch[rt][0]), cut(ch[rt][1]));
			continue;
		}
		else if (cmd[0] == 'I') {
			scanf("%d%d", &l, &v);
			splay(kth(rt, l + 1), 0);
			splay(kth(ch[rt][1], 1), rt);
			st[++nsz] = v;
			lk(nsz, ch[rt][1], 0);
			up(nsz);
			up(ch[rt][1]);
			up(rt);
			continue;
		}
		scanf("%d%d", &l, &r);
		if (cmd[0] == 'A') scanf("%d", &v), mkadv(subarr(l, r), v);
		else if (cmd[0] == 'R' && cmd[3] == 'E') mkflp(subarr(l, r));
		else if (cmd[0] == 'R') scanf("%d", &v), move(subarr(l, r), v);
		else if (cmd[0] == 'M') printf("%d\n", mn[subarr(l, r)]);
		up(rt);
	}
}
/* Debug
 * 子树树根的更改，何为取代 
 * */
