#include <cstdio>
#include <algorithm>
const int N = 3e5 + 10;
int n, m, w[N], s[N], pre[N], ch[N][2];
bool rt[N], rev[N];
inline void up(int o) {if (o) s[o] = s[ch[o][0]]^s[ch[o][1]]^w[o];}
inline void mkr(int o) {if (o) rev[o]^=1, std::swap(ch[o][0], ch[o][1]);}
inline void down(int o) {
	if (rev[o]) mkr(ch[o][0]), mkr(ch[o][1]), rev[o] = 0;
}
inline int gd(int o) {return ch[pre[o]][1] == o;}
inline void lk(int x, int y, int d) {
	if (x) pre[x] = y;
	if (y) ch[y][d] = x;
}
inline void rot(int o) {
	int x = pre[o], d = gd(o);
	pre[o] = pre[x];
	if (rt[x]) rt[x] = 0, rt[o] = 1;
	else ch[pre[x]][gd(x)] = o;
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	up(x);
	up(o);
}
void clear(int o) {
	if (!rt[o]) clear(pre[o]);
	down(o);
}
inline void splay(int o) {
	for (clear(o); !rt[o]; rot(o))
		if (!rt[pre[o]]) rot(gd(o) == gd(pre[o]) ? pre[o] : o);
}
inline void access(int o) {
	for (int x = 0; o;) {
		splay(o);
		rt[ch[o][1]] = 1, rt[ch[o][1] = x] = 0;
		up(o);
		o = pre[x = o];
	}	
}
inline void mkrt(int o) {
	access(o);
	splay(o);
	mkr(o);
}
inline int find(int o) {for (;pre[o];o = pre[o]); return o;}
inline void link(int u, int v) {
	if (find(u) == find(v)) return;
	mkrt(u);
	pre[u] = v;
}
inline void cut(int u, int v) {
	if (find(u) != find(v)) return;
	mkrt(u);
	access(v);
	splay(v);
	if (ch[v][0] == u && !ch[u][1]) {
		pre[u] = pre[v], rt[u] = 1;
		pre[v] = ch[v][0] = 0;
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n ,&m);
	for (int i = 1; i <= n; i++) scanf("%d", w + i), up(i), rt[i] = 1;
	while (m--) {
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);
		if (t == 0) {
			mkrt(u);
			access(v);
			splay(v);
			printf("%d\n", s[v]);
		}
		else if (t == 1) link(u, v);
		else if (t == 2) cut(u, v);
		else {
			access(u);
			splay(u);
			w[u] = v;
			up(u);
		}
	}
}
