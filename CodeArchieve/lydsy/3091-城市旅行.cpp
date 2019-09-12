#include <cstdio>
#include <algorithm>
#include <vector>
#define forch for (int i = 0; i < 2; i++)
const int N = 5e4 + 10;
typedef long long ll;
int n, m, pre[N], ch[N][2];
bool rt[N], rev[N];
ll ad[N], w[N], s[N], sz[N], ls[N], rs[N], e[N];
inline void up(int o) {
	s[o] = w[o] + s[ch[o][0]] + s[ch[o][1]];
	sz[o] = 1 + sz[ch[o][0]] + sz[ch[o][1]];
	ls[o] = ls[ch[o][0]] + (sz[ch[o][0]] + 1)*s[ch[o][1]] + ls[ch[o][1]] + w[o]*(sz[ch[o][0]] + 1);
	rs[o] = rs[ch[o][1]] + (sz[ch[o][1]] + 1)*s[ch[o][0]] + rs[ch[o][0]] + w[o]*(sz[ch[o][1]] + 1);
	e[o] = e[ch[o][0]] + e[ch[o][1]] + (sz[ch[o][0]] + 1)*rs[ch[o][1]] + (sz[ch[o][1]] + 1)*ls[ch[o][0]] + (sz[ch[o][0]] + 1)*(sz[ch[o][1]] + 1)*w[o];
}
inline void mkad(int o, ll x) {
	if (o)  {
		s[o] += x*sz[o],
		w[o] += x,
		ad[o] += x;
		ll u = sz[o]*(sz[o] + 1)*x/2;
		ls[o] += u, rs[o] += u;
		e[o] += x*sz[o]*(sz[o] + 1)*(sz[o] + 2)/6;
	}
}
inline void mkr(int o) {if (o) std::swap(ch[o][0], ch[o][1]), std::swap(ls[o], rs[o]), rev[o] ^= 1;}
inline void down(int o) {
	if (ad[o]) mkad(ch[o][0], ad[o]), mkad(ch[o][1], ad[o]), ad[o] = 0;
	if (rev[o]) mkr(ch[o][0]), mkr(ch[o][1]), rev[o] = 0;
}
inline int gd(int o) {return ch[pre[o]][1] == o;}
inline void lk(int x, int y, int d) {
	if (x) pre[x] = y;
	if (y) ch[y][d] = x;
}
inline void rot(int o) {
	int d = gd(o), x = pre[o];
	pre[o] = pre[x];
	if (rt[x]) rt[x] = 0, rt[o] = 1;
	else ch[pre[x]][gd(x)] = o;
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	up(x);
	up(o);
}
inline void clear(int o) {
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
inline int find(int u) {for(;pre[u]; u = pre[u]); return u;}
inline void cut(int u, int v) {
	if (find(u) != find(v)) return; 
	mkrt(u);
	access(v);
	splay(v);
	if (ch[v][0] == u && ch[u][1] == 0) {
		pre[ch[v][0]] = pre[v], rt[ch[v][0]] = 1;
		pre[v] = ch[v][0] = 0;
		up(v);
	}
}
inline void link(int u, int v) {
	if (find(u) == find(v)) return;
	mkrt(u);
	pre[u] = v;
}
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
std::vector<int> to[N];
void dfs(int u, int fa) {
	for (int i = 0; i < (int)to[u].size(); i++) if (to[u][i] != fa) pre[to[u][i]] = u, dfs(to[u][i], u);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", w + i), rt[i] = 1, up(i);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dfs(1, 0);
	while (m--) {
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);
		if (t == 1) cut(u, v);
		else if (t == 2) link(u, v);
		else if (t == 3) {
			int d;
			scanf("%d", &d);
			if (find(u) != find(v)) continue;
			mkrt(u);
			access(v);
			splay(v);
			mkad(v, d);
		}
		else {
			if (find(u) != find(v)) {
				puts("-1");
				continue;
			}
			mkrt(u);
			access(v);
			splay(v);
			ll c = e[v], m = sz[v]*(sz[v] + 1)/2, d = gcd(c, m);
			printf("%lld/%lld\n", c/d, m/d);
		}
	}
}
