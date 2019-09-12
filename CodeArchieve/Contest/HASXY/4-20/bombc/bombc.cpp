#include <cstdio>
#include <cstring>
#include <algorithm>
#define mid ((l + r)>>1)
const int N = 1e5 + 10, V = N << 2;
int n, m;
bool cl[V];
struct Discret{
	int sz, a[V], mx;
	inline void in(int x) {a[sz++] = x;}
	void init() {
		std::sort(a, a + sz);
		sz = std::unique(a, a + sz) - a;
		mx = sz;
	}
	inline int lo(int x) {
		int ret = std::lower_bound(a, a + sz, x) - a + 1;
		return std::min(ret, sz);
	}
	inline int up(int x) {
		return std::upper_bound(a, a + sz, x) - a;
	}
	int rev(int x){return a[x - 1];}
}dx, dd;
namespace Seg {
int top, s[V], ch[V][2], rt[N];
inline void init() {
	memset(rt, 0, sizeof rt);
	memset(s, 0, sizeof s);
	memset(ch, 0, sizeof ch);
	top = 0;
}
inline void mkcl(int o) {if (o) s[o] = 0,cl[o] = 1;}
inline void down(int o) {
	if (cl[o]) mkcl(ch[o][0]), mkcl(ch[o][1]), cl[o] = 0;
}
void add(int& o, int l, int r, int q1) {
	if (!o) o = ++top;
	if (l == r) s[o]++;
	else {
		down(o);
		if (q1 <= mid) add(ch[o][0], l, mid, q1);
		else add(ch[o][1], mid + 1, r, q1);
		s[o] = s[ch[o][0]] + s[ch[o][1]];
	}
}
void clean(int& o, int l, int r, int q1, int q2) {
	if (!o) return;
	if (q1 <= l && r <= q2) {
		mkcl(o);
		return;
	}
	down(o);
	if (q1 <= mid) clean(ch[o][0], l, mid, q1, q2);
	if (mid < q2) clean(ch[o][1], mid + 1, r, q1, q2);
	s[o] = s[ch[o][0]] + s[ch[o][1]];
}
int query(int& o, int l, int r, int q1, int q2) {
	if (!o) return 0;
	if (q1 <= l && r <= q2) return s[o];
	down(o);
	int x = 0;
	if (q1 <= mid) x += query(ch[o][0], l, mid, q1, q2);
	if (mid < q2) x += query(ch[o][1], mid + 1, r, q1, q2);
	return x;
}
void dfs(int o, int l, int r) {
	if (!o) return;
	down(o);
	if (l == r) {
		if (s[o]) printf("[%d: %d] ", dx.rev(l), s[o]);
		return;
	}
	dfs(ch[o][0], l, mid), dfs(ch[o][1], mid + 1, r);
}
void show() {
	for (int i = 1; i < dd.mx; i++) printf("%d: ", dd.rev(i)), dfs(rt[i], 0, dx.mx), putchar('\n');
}
}
struct Cmd{int x, r, d;}op[N];
inline int lowbit(int x) {return x&-x;}
void add(int x, int d, int v) {
	for (;d <= dd.mx; d += lowbit(d)) Seg::add(Seg::rt[d], 0, dx.mx, x);
}
void rm(int l, int r, int d) {
	if (l > r) return;
	for (;d;d-=lowbit(d)) Seg::clean(Seg::rt[d], 0, dx.mx, l, r);
}
int pre(int l, int r, int d) {
	if (l > r) return 0;
	int ret = 0;
	for(;d;d-=lowbit(d)) ret += Seg::query(Seg::rt[d], 0, dx.mx, l, r);
	return ret;
}
void work() {
	Seg::init();
	dx.sz = dd.sz = 0;
	for (int i = 1, x, d; i <= n; i++) scanf("%d%d", &x, &d), op[i] = (Cmd){x, 0, d}, dx.in(x), dd.in(d);
	dx.init(), dd.init();
	for (int i = 1; i <= n; i++) add(dx.lo(op[i].x), dd.lo(op[i].d), 1);
	scanf("%d", &m);
	for (int i = 1, r, x, d; i <= m; i++) {
		scanf("%d%d%d", &d, &r, &x);
		int y = x + r;
	 	x -= r;
		d = dd.up(d);
		y = dx.up(y);
		x = dx.lo(x);
		printf("%d\n", pre(x, y, d));
		rm(x, y, d);
		Seg::show();
	}
}
int main() {
	freopen("bombc.in", "r", stdin);
//	freopen("bombc.out", "w", stdout);
	while (scanf("%d", &n), n) work();
}
