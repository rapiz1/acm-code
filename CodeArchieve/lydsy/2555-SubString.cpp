#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 12e5 + 10;
int q, sz = 1, last = 1, pre[N], nxt[N][26], val[N], mask, ans;
char s[N], cmd[100];
namespace LCT{
	int pre[N], ch[N][2], val[N], adv[N];
	bool rev[N];
	inline int gd(int o) {return ch[pre[o]][1] == o;}
	inline bool rt(int o) {return ch[pre[o]][gd(o)] != o;}
	inline void mkr(int o) {if (o) rev[o]^=1, std::swap(ch[o][0], ch[o][1]);}
	inline void mkad(int o, int v) {if (o) adv[o] += v, val[o] += v;}
	inline void down(int o) {
		if (rev[o]) mkr(ch[o][0]), mkr(ch[o][1]), rev[o] = 0;
		if (adv[o]) mkad(ch[o][0], adv[o]), mkad(ch[o][1], adv[o]), adv[o] = 0;
	}
	inline void lk(int x, int y, int d) {
		if (x) pre[x] = y;
		if (y) ch[y][d] = x;
	}
	inline void rot(int o) {
		int d = gd(o), x = pre[o];
		pre[o] = pre[x];
		if (!rt(x)) ch[pre[x]][gd(x)] = o;
		lk(ch[o][d^1], x, d);
		lk(x, o, d^1);
	}
	void clear(int o) {if (!rt(o))clear(pre[o]);down(o);}
	inline void splay(int o) {
		for (clear(o); !rt(o); rot(o))
			if (!rt(pre[o])) rot(gd(o) == gd(pre[o]) ? pre[o] : o);
	}
	inline void access(int o) {
		for (int x = 0; o; o = pre[x = o])
			splay(o), ch[o][1] = x;
	}
	inline void mkrt(int o) {access(o), splay(o), mkr(o);}
	inline void link(int x, int y) {mkrt(x), pre[x] = y;}
	inline void cut(int x, int y) {
		mkrt(x), access(y), splay(y);
		pre[x] = pre[y], pre[y] = ch[y][0] = 0;
	}
	inline void add(int o) {
		mkrt(1), access(o), splay(o);
		mkad(o, 1);
	}
	inline int get(int o) {splay(o);return val[o];}
}
inline void extend(int c) {
	int np = ++sz, p = last;
	val[np] = val[p] + 1;
	for (; p&&!nxt[p][c]; p = pre[p]) nxt[p][c] = np;
	if (p) {
		int q = nxt[p][c];
		if (val[q] == val[p] + 1) pre[np] = q, LCT::link(np, q);
		else {
			if (pre[q]) LCT::cut(q, pre[q]);
			int nq = ++sz;
			LCT::link(nq, pre[q]);
			LCT::val[nq] = LCT::get(q);
			val[nq] = val[p] + 1, pre[nq] = pre[q];
			memcpy(nxt[nq], nxt[q], sizeof nxt[0]);
			LCT::link(np, nq), LCT::link(q, nq);
			pre[np] = nq, pre[q] = nq;
			for (;p&&nxt[p][c] == q; p = pre[p]) nxt[p][c] = nq;
		}
	}
	else pre[np] = 1, LCT::link(np, 1);
	last = np;
	LCT::add(np);
}
inline void dec(int mask) {
	int l = strlen(s);
	for (int j = 0; j < l; j++) {
		mask = (mask*131 + j)%l;
		std::swap(s[j], s[mask]);
	}
}
int main() {
	scanf("%d%s", &q, s);
	for (int i = 0; s[i]; i++) extend(s[i] - 'A');
	while (q--) {
		scanf("%s%s", cmd, s);
		dec(mask);
		if (cmd[0] == 'A') for (int i = 0; s[i]; i++) extend(s[i] - 'A');
		else {
			int p, i;
			for (i = 0, p = 1; s[i]; i++) p = nxt[p][s[i] - 'A'];
			printf("%d\n", ans = p?LCT::get(p):0);
			mask^=ans;
		}
	}
}
