#include <cstdio>
#include <cstring>
#include <algorithm>
const int E = 1e5 + 10, V = E << 1;
struct Edge{int u, v, a, b;}st[E];
bool cmpa(const Edge& x, const Edge& y) {return x.a < y.a;}
int n, m, ch[V][2], mx[V], mxp[V], fa[V], w[V], ans = 1e9;
bool rev[V];
inline void mkrev(int o) {
	if (o) {
		std::swap(ch[o][0], ch[o][1]);
		rev[o] ^= 1;
	}
}
inline void up(int o) {
	int d = mx[ch[o][1]] > mx[ch[o][0]];
	mx[o] = mx[ch[o][d]];
	mxp[o] = mxp[ch[o][d]];
	if (w[o] > mx[o]) {
		mx[o] = w[o];
		mxp[o] = o;
	}
}
inline void down(int o) {
	if (rev[o]) mkrev(ch[o][0]), mkrev(ch[o][1]), rev[o] = 0;
}
inline void lk(int x, int y, int d) {
	if (x) fa[x] = y;
	if (y) ch[y][d] = x;
}
inline int gd(int o) {return ch[fa[o]][1] == o;}
inline bool rt(int o) {return ch[fa[o]][gd(o)] != o;}
void rot(int o) {
	int x = fa[o], d = gd(o);
	fa[o] = fa[x];
	if (!rt(x)) ch[fa[x]][gd(x)] = o;
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	up(x), up(o);
}
void clear(int o) {
	if (fa[o]) clear(fa[o]);
	down(o);
}
void splay(int o) {
	for (clear(o);!rt(o);rot(o))
		if (!rt(fa[o])) rot(gd(o) == gd(fa[o]) ? fa[o] : o);
}
void access(int o) {
	for (int x = 0; o; o = fa[x = o])
		splay(o), ch[o][1] = x, up(o);
}
inline void mkrt(int o) {access(o), splay(o), mkrev(o);}
inline void link(int x, int y) {mkrt(x), fa[x] = y;}
inline void cut(int x, int y) {
	mkrt(x), access(y), splay(x);
 	ch[x][1] = fa[y] = 0, up(x);
}
/*
inline void cut(int u, int v) {
    mkrt(u);
    access(v);
    splay(v);
    fa[ch[v][0]] = fa[v];
    fa[v] = ch[v][0] = 0;
		up(v);
}
*/
int find(int o) {return fa[o] ? find(fa[o]) : o;}
inline void select(int u, int v) {mkrt(u),access(v), splay(u);}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n ,&m);
	for (int i=1; i <= m; i++) scanf("%d%d%d%d", &st[i].u, &st[i].v, &st[i].a, &st[i].b);
	std::sort(st + 1, st + 1 + m, cmpa);
	for (int i =  1; i <= n; i++) w[i] = -1;
	for (int i = 1; i <= m; i++) {
		w[i + n] = st[i].b;
		if (find(st[i].u) != find(st[i].v)) 
			link(st[i].u, i + n),
			 	link(i + n, st[i].v);
		else {
			select(st[i].u, st[i].v);
			if (mx[st[i].u] > st[i].b) {
				int x = mxp[st[i].u];
				cut(st[x-n].u, x);
				cut(st[x-n].v, x);
				link(st[i].u, i + n);
				link(st[i].v, i + n);
			}
		}
		if (find(1) == find(n)) {
			select(1, n);
			ans = std::min(ans, st[i].a + mx[1]);
		}
	}
	printf("%d\n", ans < 1e9? ans : -1);
}
