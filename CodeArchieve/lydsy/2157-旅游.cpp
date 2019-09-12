#include <cstdio>
#include <algorithm>
#include <vector>
using std::max;
using std::min;
const int N = (2000*10 + 10) << 1, INF = 1e5;
int n, m, pre[N], mx[N], mn[N], ch[N][2], w[N], s[N], tot;
bool rev[N], neg[N], rt[N];
std::vector<int> to[N];
inline void up(int o) {
	mx[o] = -INF, mn[o] = INF, s[o] = 0;
	for (int i = 0; i < 2; i++) {
		mx[o] = max(mx[ch[o][i]], mx[o]);
		mn[o] = min(mn[ch[o][i]], mn[o]);
		s[o] += s[ch[o][i]];
	}
	if (o > n) {
		mx[o] = max(mx[o], w[o]);
		mn[o] = min(mn[o], w[o]);
		s[o] += w[o];
	}
}
inline void mkr(int o) {if (o) rev[o] ^= 1, std::swap(ch[o][0], ch[o][1]);}
inline void mkneg(int o) {
	if (o) {
		neg[o] ^= 1;
		std::swap(mx[o], mn[o]);
		mx[o] = -mx[o];
		mn[o] = -mn[o];
		s[o] = -s[o];
		w[o] = -w[o];
	}
}
inline void down(int o) {
	if (neg[o]) mkneg(ch[o][0]),mkneg(ch[o][1]), neg[o] = 0;
	if (rev[o]) mkr(ch[o][0]), mkr(ch[o][1]), rev[o] = 0;
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
	for(clear(o); !rt[o]; rot(o))
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
inline void select(int u, int v) {
	mkrt(u);
	access(v);
	splay(v);
}
void dfs(int u, int fa) {
	pre[u] = fa;
	rt[u] = 1;
	up(u);
	for (int i = 0; i < (int)to[u].size(); i++) if (to[u][i] != fa) dfs(to[u][i], u);
}
char cmd[10];
inline void con(int u, int v) {
	to[u].push_back(v);
	to[v].push_back(u);
}
int main() {
	scanf("%d", &n);
	mx[0] = -INF, mn[0] = INF;
	tot = n;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u++, v++;
		con(u, ++tot);
		con(v, tot);
		::w[tot] = w;
		up(tot);
	}
	scanf("%d", &m);
	dfs(1, 0);
	while (m--) {
		int u, v;
		scanf("%s%d%d", cmd, &u, &v);
		u++, v++;
		if (cmd[0] == 'C') {
			u += n - 1;
			v--;
			splay(u);
			w[u] = v;
			up(u);
		}
		else if (cmd[0] == 'N') {
			select(u, v);
			mkneg(v);
		}
		else if (cmd[0] == 'S') {
			select(u, v);
			printf("%d\n", s[v]);
		}
		else if (cmd[0] == 'M') {
			select(u, v);
			printf("%d\n", cmd[1] == 'A' ? mx[v] : mn[v]);
		}
	}
}
