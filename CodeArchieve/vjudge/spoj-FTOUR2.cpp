#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int V = 2e5 + 10, E = V << 1, NAG = -2e9;
namespace I {
	const int L = 1 << 15 | 1;
	char *s, *t, buf[L];
	inline int gc() {
		if (s == t) t = (s = buf) + fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int r = 0, ch, f = 1;
		do {
			ch = gc();
			if (ch == '-') f = -1;
		} while (!isdigit(ch));
		for(;isdigit(ch); ch = gc()) r = r*10 + ch - '0';
		return r*f;
	}
}using I::gi;
int n, m, k, hed[V], nxt[E], f[V], sz[V], q[V], h, t, dis[V], bcn[V], ans, pre[V];
bool blk[V], vis[V];
struct EDGE{int u, v, w;}st[E];
void add(int u, int v, int w) {
	static int sz = 0;
	st[++sz] = (EDGE){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline int lowbit(int x) {return x&-x;}
void change(int p, int v) {
	p++;
	for (;p <= n + 1; p+=lowbit(p)) f[p] = std::max(f[p], v);
}
int query(int p) {
	p++;
	if (p <= 0) return NAG;
	int r = NAG;
	for (;p; p -= lowbit(p)) r = std::max(r, f[p]);
	return r;
}
void clear(int p) {
	p++;
	for (;p<=n + 1; p+=lowbit(p)) f[p] = NAG;
}
void solve(int u) {
	h = t = 0;
	pre[q[t++] = u] = 0;
	while (h < t) {
		int u = q[h++];
		sz[u] = 1;
		fore if (!vis[v] && v != pre[u]) pre[q[t++] = v] = u;
	}
	for (int i = t - 1; ~i; i--) sz[pre[q[i]]] += sz[q[i]];
	int size = sz[u];
	for (int flag = 1; flag; ) {
		flag = 0;
		fore if (!vis[v] && pre[u] != v && sz[v] > size/2) {
			u = v;
			flag = 1;
			break;
		}
	}
	vis[u] = 1;
	static int modi[V], msz;
	msz = 0;
	fore if (!vis[v]) {
		int rt = u, u = v;
		h = t = 0;
		q[t++] = u;
		dis[u] = st[e].w;
		bcn[u] = blk[u];
		pre[u] = rt;
		while (h < t) {
			u = q[h++];
			ans = std::max(ans, dis[u] + query(k - bcn[u] - blk[rt]));
			fore if (!vis[v] && pre[u] != v) {
				dis[v] = dis[u] + st[e].w;
				bcn[v] = bcn[u] + blk[v];
				pre[q[t++] = v] = u;
			}
		}
		for (int i = 0; i < t; i++) modi[msz++] = bcn[q[i]], change(bcn[q[i]], dis[q[i]]);
	}
	ans = std::max(ans, query(k - blk[u]));
	for (int i = 0; i < msz; i++) clear(modi[i]);
	fore if (!vis[v]) solve(v);
}
int main() {
//	freopen("input", "r", stdin);
//	freopen("freetourII.in", "r", stdin);
//	freopen("freetourII.out","w", stdout);
	n = gi(), k = gi(), m = gi();
	for (int i = 1; i <= m; i++) blk[gi()] = 1;
	for (int i = 1, u, v, w; i < n; i++) u = gi(), v = gi(), w = gi(), add(u, v, w), add(v, u, w);
	for (int i = 0; i <= n; i++) f[i] = NAG;
	solve(1);
	printf("%d\n", ans);
}
