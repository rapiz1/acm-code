#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
const int V = 1e5 + 10, INF = 0x3f3f3f3f, NAG = 0xc0c0c0c0;
std::vector<int> to[V];
struct Prog {
int n, m, pre[V], ch[V][2], mx[V], mmx[V], mxt[V], mmxt[V], inc[V], cov[V], rev[V], w[V], sz[V];
inline void lk(int x, int y, int d) {
	if (x) pre[x] = y;
	if (y) ch[y][d] = x;
}
inline int gd(int o) {return ch[pre[o]][1] == o;}
inline bool rt(int o) {return ch[pre[o]][gd(o)] != o;}
inline void mkcov(int o, int v) {if (o) inc[o] = 0, cov[o] = w[o] = mx[o] = v, mmx[o] = NAG, mxt[o] = sz[o];}
inline void mkinc(int o, int v) {if (o) inc[o] += v, mx[o] += v, mmx[o] = mmx[o] == NAG ? mmx[o] : mmx[o] + v, w[o] += v;}
inline void mkrev(int o) {if (o) std::swap(ch[o][0], ch[o][1]), rev[o]^=1;}
inline void down(int o) {
	if (rev[o]) mkrev(ch[o][0]), mkrev(ch[o][1]), rev[o] = 0;
	if (cov[o] != INF) mkcov(ch[o][0], cov[o]), mkcov(ch[o][1], cov[o]), cov[o] = INF;
	if (inc[o]) mkinc(ch[o][0], inc[o]), mkinc(ch[o][1], inc[o]), inc[o] = 0;
}
inline void up(int o) {
	if (!o) return;
	mx[o] = w[o], mxt[o] = 1;
	mmx[o] = NAG, mmxt[o] = 0;
	sz[o] = sz[ch[o][0]] + sz[ch[o][1]] + 1;
	for (int d = 0; d < 2; d++) if (ch[o][d]) {
		if (mx[ch[o][d]] > mx[o]) mx[o] = mx[ch[o][d]], mxt[o] = mxt[ch[o][d]];
		else if (mx[ch[o][d]] == mx[o]) mxt[o] += mxt[ch[o][d]];
	}
	for (int d = 0; d < 2; d++) if (ch[o][d]) {
		if (mx[ch[o][d]] < mx[o]) {
			if (mx[ch[o][d]] > mmx[o]) mmx[o] = mx[ch[o][d]], mmxt[o] = mxt[ch[o][d]];
			else if (mx[ch[o][d]] == mmx[o]) mmxt[o] += mxt[ch[o][d]];
		}
		if (mmx[ch[o][d]] < mx[o]) {
			if (mmx[ch[o][d]] > mmx[o]) mmx[o] = mmx[ch[o][d]], mmxt[o] = mmxt[ch[o][d]];
			else if (mmx[ch[o][d]] == mmx[o]) mmxt[o] += mmxt[ch[o][d]];
		}
	}
	if (w[o] < mx[o] && w[o] > mmx[o]) mmx[o] = w[o], mmxt[o] = 1;
	else if (w[o] == mmx[o]) mmxt[o]++;
}
inline void rot(int o) {
	int x = pre[o], d = gd(o);
	pre[o] = pre[x];
	if (!rt(x)) ch[pre[x]][gd(x)] = o;
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	up(x), up(o);
}
void clear(int o) {if (!rt(o)) clear(pre[o]);down(o);}
inline void splay(int o) {
	for (clear(o); !rt(o); rot(o)) 
		if (!rt(pre[o])) rot(gd(o) == gd(pre[o]) ? pre[o] : o);
}
void access(int o) {
	for (int x = 0; o; o = pre[x = o]) 
		splay(o), ch[o][1] = x, up(o);	
}
void mkrt(int o) {
	access(o);
	splay(o);
	mkrev(o);
}
void dfs(int u, int fa) {
	pre[u] = fa;
	up(u);
	for (int i = 0; i < (int)to[u].size(); i++) if (to[u][i] != fa) dfs(to[u][i], u);
}
inline void link(int u, int v) {
	mkrt(u);
	pre[u] = v;
}
inline void cut(int u, int v) {
	mkrt(u), access(v);
	splay(v);
	pre[u] = ch[v][0] = 0;
	up(v);
}
void solve() {
	for (int i = 1; i <= n; i++) to[i].clear();
	memset(this, 0, sizeof *this);
	memset(cov, 0x3f, sizeof cov);
	memset(mmx, 0xc0, sizeof mmx);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", w + i);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), to[u].push_back(v), to[v].push_back(u);
	dfs(1, 0);
	while (m--) {
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);
		if (t == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			cut(u, v), link(x, y);
		}
		else {
			mkrt(u), access(v), splay(u);
			int x;
			if (t == 2) scanf("%d", &x), mkcov(u, x);
			else if (t == 3) scanf("%d", &x), mkinc(u, x);
			else if (t == 4) {
				if (mmx[u] == NAG) puts("ALL SAME");
				else printf("%d %d\n", mmx[u], mmxt[u]);
			}
		}
	}
}
}prog;
int main() {
//	freopen("input", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d:\n", i);
		prog.solve();
	}
}
