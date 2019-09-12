#include <cstdio>
#include <algorithm>
#include <cctype>
#include <map>
#define file(x) "tube."#x
typedef long long ll;
const int M = 1e6 + 10, N = 1e5 +10 +M, Q = 1e5 + 10, V = 1e5 + 10;
namespace I {
	const int L = 1 << 15 | 1;
	char *s,*t, buf[L];
	inline char gc() {
		if (s == t) t = (s = buf) + fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int ch = gc(), x = 0;
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch)) x = x*10 + ch - '0', ch = gc();
		return x;
	}
}using I::gi;
int n, m, q, ch[N][2], pre[N], hed[N], nxt[M << 2], w[N], mxi[N], st[M << 2], th[M];
bool rt[N], rev[N];
struct EDGE{int u, v, w;
	bool rm, in;
	bool operator<(const EDGE& b)const {
		return w < b.w;
	}
	inline void rd() {
		u = gi(), v = gi(), w = gi();
	}
}e[M], qu[Q];
bool cmp2(int i, int j) {return e[i].u < e[j].u || (e[i].u == e[j].u && e[i].v < e[j].v);}
inline ll zip(ll u, ll v) {
	if (u > v) std::swap(u, v);
	return u*V + v;
}
inline void _add(int u, int v){
	static int sz = 0;
	st[++sz] = v;
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v){
	_add(u, v), _add(v, u);
}
namespace Kruskal {
	int p[N];
	int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
	void solve() {
		for (int i = 1; i <= m; i++) p[i] = i;
		std::sort(e + 1, e + 1 + m);
		for (int i = 1; i <= m; i++) if (!e[i].rm) {
			int u = find(e[i].u), v = find(e[i].v);
			if (u == v) continue;
			p[u] = v;
			e[i].in = 1;
		}
	}
}
inline void mkr(int o) {if(o) std::swap(ch[o][0], ch[o][1]), rev[o] ^= 1;}
inline void down(int o) {if (rev[o]) mkr(ch[o][0]), mkr(ch[o][1]), rev[o] = 0;}
inline void up(int o) {
	mxi[o] = o > n ? o : 0;
	for (int i = 0; i < 2; i++) if (w[mxi[ch[o][i]]] > w[mxi[o]]) mxi[o] = mxi[ch[o][i]];
}
inline int gd(int o) {return ch[pre[o]][1] == o;}
inline void lk(int x, int y, int d) {
	if (x) pre[x] = y;
	if (y) ch[y][d] = x;
}
//inline bool rt(int o) {return ch[pre[o]][0] == o || ch[pre[o]][1] == o;}
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
	for (int x = 0; o; ) {
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
inline void link(int u, int v) {mkrt(u), pre[u] = v;}
inline void cut(int u, int v) {
	mkrt(u);
	access(v);
	splay(v);
	pre[u] = pre[v], rt[u] = 1;
	pre[v] = ch[v][0] = 0;
	up(v);
}
void dfs(int u, int fa) {
	pre[u] = fa;
	rt[u] = 1;
	up(u);
	for (int g = hed[u], v; v = st[g]; g = nxt[g]) if (v != fa) dfs(v, u);
}
inline int query(int u, int v) {
	mkrt(u),access(v), splay(v);
	return mxi[v];
}
int find(int u, int v) {
	if (u > v) std::swap(u, v);
	e[m + 1].u = u, e[m + 1].v = v;
	int p = std::lower_bound(th + 1, th + 1 + m, m + 1, cmp2) - th;
	return th[p];
}
int main() {
//	freopen("input", "r", stdin);
//	freopen(file(in), "r", stdin);
//	freopen(file(out), "w", stdout);
	n = gi(), m = gi(), q = gi();
	for (int i = 1; i <= m; i++) e[i].rd(), th[i] = i;
	std::sort(th + 1, th + 1 + m, cmp2);
	for (int i = 1; i <= q; i++) {
		qu[i].rd();
		if (qu[i].u == 2) {
			e[find(qu[i].v, qu[i].w)].rm = 1;
		}
	}
	Kruskal::solve();
	std::sort(th + 1, th + 1 + m, cmp2);
	for (int i = 1; i <= m; i++) {
		if (e[i].in) {
			add(e[i].u, n + i);	
			add(e[i].v, n + i);
		}
		w[n + i] = e[i].w;
	}
	dfs(1, 0);
	for (int i = q; i; i--) if (qu[i].u == 1) qu[i].v = w[query(qu[i].v, qu[i].w)];
	else {
		int x = query(qu[i].v, qu[i].w), id = find(qu[i].v, qu[i].w);
		if (w[n + id] < w[x]) {
			cut(x, e[x - n].u);
			cut(x, e[x - n].v);
			link(n + id, qu[i].v);
			link(n + id, qu[i].w);
		}
	}
	for (int i = 1; i <= q; i++) if (qu[i].u == 1) printf("%d\n", qu[i].v);
}
