#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
typedef long long ll;
const int V = 3e5 + 10;
int n, m, k, q, ch[V][2], pre[V], s[V], val[V], tot; 
bool rev[V];
std::map<ll, int> condi;
inline ll zip(ll x,ll y) {if(x > y) std::swap(x, y); return x*(n + 1) + y;}
inline int adj(int x) {
	if (x >= 0) return x%k;
	else return (x + (-x + k - 1)/k*k)%k;
}
inline int gd(int o) {return ch[pre[o]][1] == o;}
inline bool rt(int o) {return ch[pre[o]][gd(o)] != o;}
inline void lk(int x, int y, int d) {
	if (x) pre[x] = y;
	if (y) ch[y][d] = x;
} 
inline void mkr(int o) {if (o) rev[o]^=1, val[o] = adj(-val[o]), s[o] = adj(-s[o]), std::swap(ch[o][0], ch[o][1]);}
inline void up(int o) {s[o] = (s[ch[o][0]] + s[ch[o][1]] + val[o])%k;}
inline void down(int o) {if (rev[o]) mkr(ch[o][0]), mkr(ch[o][1]), rev[o] = 0;}
inline void rot(int o) {
	int x = pre[o], d = gd(o);
	pre[o] = pre[x];
	if (!rt(x)) ch[pre[x]][gd(x)] = o;
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	up(x);
	up(o);
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
	for (int x = 0; o; o = pre[x = o]) {
		splay(o);
		ch[o][1] = x;
		up(o);
	}
}
inline void mkrt(int o) {
	access(o), splay(o), mkr(o);
}
inline int find(int o) {return pre[o] ? find(pre[o]) : o;}
inline void link(int u, int v) {
	mkrt(u);pre[u] = v;
}
inline void cut(int u, int v) {
	mkrt(u), access(v), splay(v);
	pre[u] = pre[v];
	pre[v] = ch[v][0] = 0;
	up(v);
}
inline void addeq(int a, int b, int c) {
	val[++tot] = adj(c);
	up(tot);
	link(a, tot), pre[tot] = b;
	condi[zip(a, b)] = tot;
}
int main() {
//	freopen("input1", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &k, &q);
	tot = n;
	for (int i = 1; i <= m; i++) {
		int a, b, c;scanf("%d%d%d", &a, &b, &c);
		addeq(a, b, c);
	}
	while (q--) {
		int t, a, b, c;scanf("%d%d%d", &t, &a, &b);
		if (t == 1) {
			scanf("%d", &c);
			addeq(a, b, c);
		}
		else if (t == 2) {
			if (condi.count(zip(a, b))) {
				int pos = condi[zip(a,b)];
				if (pos == 0) continue;
				cut(a, pos), cut(b, pos);
			}
		}
		else if (t == 3) {
			scanf("%d", &c);
			if (find(a) != find(b)) {
				puts("-1");
				continue;
			}
			mkrt(a);
			access(b);
			splay(a);
			printf("%d\n", (c + s[a])%k);
		}
	}
}
