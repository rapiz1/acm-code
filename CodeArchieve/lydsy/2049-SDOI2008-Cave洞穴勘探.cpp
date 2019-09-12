#include <cstdio>
#include <algorithm>
#include <cassert>
#define file(x) "sdoi2008_cave." #x
const int N = 1e4 + 10;
int n, m, pre[N], ch[N][2];
bool rt[N], rev[N];
char cmd[20];
inline void mkr(int o) {
	if (!o) return;
	rev[o] ^= 1;
	std::swap(ch[o][0], ch[o][1]);
}
inline void down(int o) {
	if (rev[o]) mkr(ch[o][0]), mkr(ch[o][1]), rev[o] = 0;
}
inline int gd(int o) {return ch[pre[o]][1] == o;}
inline void lk(int x, int y, int d) {
	if (x) pre[x] = y;
	if (y) ch[y][d] = x;
}
inline void rot(int o) {
	int d = gd(o), x = pre[o];
	if (rt[x]) pre[o] = pre[x], rt[x] = 0, rt[o] = 1;
	else lk(o, pre[x], gd(x));
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
//	up(x), up(o);
}
void clear(int o) {
	if (!rt[o]) clear(pre[o]);
	down(o);
}
void splay(int o) {
	for (clear(o); !rt[o]; rot(o))
		if (!rt[pre[o]]) rot(gd(o) == gd(pre[o]) ? pre[o] : o);
}
void access(int o) {
	for (int x = 0; o;) {
		splay(o);
		rt[ch[o][1]] = 1, rt[ch[o][1] = x] = 0;
		o = pre[x = o];
	}
}
inline void mkrt(int o) {
	access(o);
	splay(o);
	mkr(o);
}
inline void cut(int u, int v) {
	mkrt(u);
	access(v);
	splay(v);
	pre[ch[v][0]] = pre[v], rt[ch[v][0]] = 1;
	pre[v] = ch[v][0] = 0;
}
inline void link(int u, int v) {
	mkrt(u);
	pre[u] = v;
}
inline bool query(int u, int v) {
	while (pre[u]) u = pre[u];
	while (pre[v]) v = pre[v];
	return u == v;
}
int main() {
//	freopen(file(in), "r", stdin);
//	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) rt[i] = 1;
	while (m--) {
		int x, y;
		scanf("%s%d%d", cmd, &x, &y);
		if (cmd[0] == 'Q') puts(query(x, y) ? "Yes" : "No");
		else if (cmd[0] == 'C') link(x, y);
		else cut(x, y);
	}
}
