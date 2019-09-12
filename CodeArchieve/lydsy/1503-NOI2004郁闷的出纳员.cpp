#include <cstdio>
const int N = 2e5 + 10;
int n, lb, lf, ad, top = 1, st[N], ch[N][2], fa[N], rt = 1, sz[N], cnt[N], la;
char cmd[3];
inline int gd(int o) {return ch[fa[o]][1] == o;}
inline void lk(int x, int y, int d) {
	if (x) fa[x] = y;
	if (y) ch[y][d] = x;
}
inline void up(int o) {sz[o] = sz[ch[o][0]] + sz[ch[o][1]] + cnt[o];}
inline void rot(int o) {
	int x = fa[o], d = gd(o);
	lk(o, fa[x], gd(x));
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	up(x), up(o);
	if (x == rt) rt = o;
}
inline void splay(int o) {
	for (;fa[o];rot(o)) if (fa[fa[o]]) rot(gd(fa[o]) == gd(o) ? fa[o] : o);
}
void insert(int o, int v) {
	if (st[o] == v) cnt[o]++, la = o;
	else if (ch[o][v < st[o]]) insert(ch[o][v < st[o]], v);
	else {
		st[++top] = v;
		cnt[top] = 1;
		lk(top, o, v < st[o]);
		la = top;
	}
	up(o);
}
int kth(int o, int k) {
	if (k > sz[o]) return -1;
	while (k) {
		if (k <= sz[ch[o][0]]) o = ch[o][0];
		else if (k <= sz[ch[o][0]] + cnt[o]) return o;
		else k -= sz[ch[o][0]] + cnt[o], o = ch[o][1];
	}
	return o;
}
void fire(int v) {
	insert(rt, v);
	splay(la);
	fa[ch[rt][0]] = 0;
	rt = ch[la][0];
	lf += sz[la] - sz[ch[la][0]] - 1;
}
int main() {
	scanf("%d%d", &n, &lb);
	st[1] = 2e9;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%s%d", cmd, &x);
		if (cmd[0] == 'I') {
			if (x >= lb) insert(rt, x - ad), splay(la);
		}
		else if (cmd[0] == 'A') ad += x;
		else if (cmd[0] == 'S') {
			ad -= x;
			fire(lb - ad - 1);
//			printf("%d gone\n", lf);
		}
		else if (cmd[0] == 'F') {
			int o = kth(rt, x);
			if (o == -1) puts("-1");
			else splay(o), printf("%d\n", st[o] + ad);
		}
	}
	printf("%d\n", lf);
}
