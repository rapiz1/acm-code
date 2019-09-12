#include <cstdio>
#include <algorithm>
const int N = 3e4 + 10;
int n, m, pre[N], ch[N][2], w[N], s[N];
bool rev[N];
inline int gd(int o) {return ch[pre[o]][1] == o;}
inline void lk(int x, int y, int d) {
	if (x) pre[x] = y;
	if (y) ch[y][d] = x;
}
inline bool rt(int o) {return ch[pre[o]][gd(o)] != o;}
inline void mkr(int o) {if (o) std::swap(ch[o][1], ch[o][0]), rev[o] ^= 1;}
inline void down(int o) {if (rev[o]) mkr(ch[o][0]), mkr(ch[o][1]), rev[o] = 0;}
inline void up(int o) {
	s[o] = w[o] + s[ch[o][0]] + s[ch[o][1]];
}
inline void rot(int o) {
	int x = pre[o], d = gd(o);
	pre[o] = pre[x];
	if (!rt(x)) ch[pre[x]][gd(x)] = o;
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	up(x), up(o);
}
void clear(int o) {
	if (!rt(o)) clear(pre[o]);
	down(o);
}
inline void splay(int o) {
	for (clear(o); !rt(o); rot(o))
		if (!rt(pre[o])) rot(gd(o) == gd(pre[o]) ? pre[o] : o);
}
inline void access(int o) {
	for (int x = 0; o; o = pre[x = o])
		splay(o), ch[o][1] = x, up(o);
}
inline void mkrt(int o) {access(o), splay(o), mkr(o);}
int find(int o) {return pre[o] ? find(pre[o]) : o;}
inline void link(int u, int v){mkrt(u),pre[u] = v;}
inline void cut(int u, int v) {
	mkrt(u), access(v), splay(v);
	pre[u] = pre[v], pre[v] = ch[v][0] = 0;
	up(v);
}
char cmd[20];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", w + i), up(i);
	scanf("%d", &m);
	while (m--) {
		int u, v;
		scanf("%s%d%d", cmd, &u, &v);
		if (cmd[0] == 'b') {
			if (find(u) == find(v)) puts("no");
			else {
				puts("yes");
				link(u, v);
			}
		}
		else if (cmd[0] == 'p') splay(u), w[u] = v, up(u);
		else if (cmd[0] == 'e') {
			if (find(u) == find(v)) {
				mkrt(u), access(v), splay(v);
				printf("%d\n", s[v]);
			}
			else puts("impossible");
		}
	}
}
