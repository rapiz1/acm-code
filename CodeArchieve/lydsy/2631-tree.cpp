#include <cstdio>
#include <vector>
#include <algorithm>
typedef unsigned int ll;
const int N = 1e5 + 10;
const ll M = 51061;
std::vector<int> to[N];
int n, m, pre[N], ch[N][2];
ll sz[N], ad[N], mu[N], w[N], s[N];
bool rt[N], rev[N];
void dfs(int u, int fa) {
	pre[u] = fa;
	for (int i = 0; i < (int)to[u].size(); i++) if (to[u][i] != fa) dfs(to[u][i], u);
}
inline void up(int o) {
	sz[o] = 1 + sz[ch[o][0]] + sz[ch[o][1]];
	s[o] = (w[o] + s[ch[o][0]] + s[ch[o][1]])%M;
}
inline void mkr(int o) {
	rev[o] ^= 1, std::swap(ch[o][0], ch[o][1]);
}
inline void mkad(int o, ll x) {
	if (o) {
		s[o] = (s[o] + sz[o]*x)%M;
		w[o] = (w[o] + x)%M;
		ad[o] = (ad[o] + x)%M;
	}
}
inline void mkmu(int o, ll x) {
	if (o) {
		s[o] = x*s[o]%M;
		w[o] = x*w[o]%M;
		ad[o] = ad[o]*x%M;
		mu[o] = mu[o]*x%M;
	}
}
inline void down(int o) {
	if (rev[o]) mkr(ch[o][0]), mkr(ch[o][1]), rev[o] = 0;
	if (mu[o] != 1) mkmu(ch[o][0], mu[o]), mkmu(ch[o][1], mu[o]), mu[o] = 1;
	if (ad[o]) mkad(ch[o][0], ad[o]), mkad(ch[o][1], ad[o]), ad[o] = 0;
}
inline void lk(int x, int y, int d) {
	if (x) pre[x] = y;
	if (y) ch[y][d] = x;
}
inline int gd(int o) {return ch[pre[o]][1] == o;}
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
inline void mkrt(int u) {
	access(u);
	splay(u);
	mkr(u);
}
inline void link(int u, int v) {
	mkrt(u);
	pre[u] = v;
}
inline void cut(int u, int v) {
	mkrt(u);
	access(v);
	splay(v);
	pre[ch[v][0]] = pre[v], rt[ch[v][0]] = 1;
	pre[v] = ch[v][0] = 0;
	up(v);
}
inline void select(int u, int v) {
	mkrt(u);
	access(v);
	splay(v);
}
char cmd[5];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		rt[i] = w[i] = mu[i] = 1;
		up(i);
		int u, v;scanf("%d%d", &u ,&v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	rt[n] = w[n] = mu[n] = 1;
	up(n);
	dfs(1, 0);
	while (m--) {
		int u0, v0, c, u1, v1;
		scanf("%s%d%d", cmd, &u0, &v0);
		if (cmd[0] == '+') {
			scanf("%d", &c);
			select(u0, v0);
			mkad(v0, c);
		}
		else if (cmd[0] == '-') {
			scanf("%d%d", &u1, &v1);
			cut(u0, v0);
			link(u1, v1);
		}
		else if (cmd[0] == '*') {
			scanf("%d", &c);
			select(u0, v0);
			mkmu(v0, c);
		}
		else if (cmd[0] == '/') {
			select(u0, v0);
			printf("%u\n", s[v0]);
		}
	}
}
