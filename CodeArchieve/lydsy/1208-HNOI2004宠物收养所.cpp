#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
const int V = 80010, M = 1000000;
int n, sta = 3, ch[V][2], fa[V], cnt[V], st[V], top, rt, sz, ans;
inline int gd(int o) {return ch[fa[o]][1] == o;}
inline void lk(int x, int y, int d) {
	if (x) fa[x] = y;
	if (y) ch[y][d] = x;
}
inline void rot(int o) {
	int x = fa[o], d = gd(o);
	lk(o, fa[x], gd(x));
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	if (x == rt) rt = o;
}
inline void splay(int o) {
	for (;fa[o];rot(o)) if (fa[fa[o]]) rot(gd(o) == gd(fa[o]) ? fa[o] : o);
}
inline int sp(int o, int d){// 0 -> prev, 1 - > succ, assume o is rt
	for (o = ch[o][d], d^=1; ch[o][d]; o = ch[o][d]);
	return o;
}
inline int insert(int x) {
	for (int o = rt; o; ) if (x == st[o]) {cnt[o]++;return o;}
	else if (ch[o][x > st[o]]) o = ch[o][x > st[o]];
	else {
		st[++top] = x;
		cnt[top] = 1;
		lk(top, o, x > st[o]);
		return top;
	}
	return 0;
}
inline int find(int x) {
	int o = rt;
	while(1) if (x == st[o]) return o;
	else if (ch[o][x > st[o]]) o = ch[o][x > st[o]];
	else break;
	return o;
}
void remove(int o) {
	cnt[o]--;
	if (!cnt[o]) {
		splay(o);
		int d = bool(ch[o][1]), x = ch[o][d];
		if (!x) return;
		fa[rt = x] = 0;
		for (d^=1;ch[x][d];x = ch[x][d]);
		lk(ch[o][d], x, d);
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		int t, x;scanf("%d%d", &t, &x);
		if (t == sta) splay(insert(x)), sz++;
		else if (t == (sta^1)) {
			int o = find(x);
			splay(o);
			if (st[o] == x) ;
			else {
				int tt = sp(o, 0);
				if (tt && abs(st[tt] - x) <= abs(st[o] - x)) o = tt;
				tt = sp(o, 1);
				if (tt && abs(st[tt] - x) < abs(st[o] - x)) o = tt;
			}
			remove(o);
			ans = (ans + abs(st[o] - x))%M;
			sz--;
		}
		else {
			st[rt = ++top] = x;
			cnt[top] = 1;
			sta = t;
			sz++;
		}
		if (!sz) sta = 3;
	}
	printf("%d\n", ans);
}
