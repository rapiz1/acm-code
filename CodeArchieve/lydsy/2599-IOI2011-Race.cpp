#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int V = 2e5 + 10, E = V << 1, K = 1e6 + 1;
namespace I {
	const int L = 1 << 15;
	char *s, *t, buf[L];
	inline int gc() {
		if (s == t) t = (s = buf) + fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int r = 0, f = 1, ch = gc();
		for (;!isdigit(ch); ch = gc()) if (ch == '-') f = -1;
		while (isdigit(ch)) r = r*10 + ch - '0', ch = gc();
		return r*f;
	}
}using I::gi;
struct EDGE{int u, v, w;}st[E];
int n, k, hed[V], nxt[E], f[K], ans = V, q[V], h, t, sz[V], pre[V], dis[V], ecn[V];
bool vis[V];
inline void _add(int u, int v, int w) {
	static int sz = 0;
	st[++sz] = (EDGE){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
void add(int u, int v, int w) {_add(u, v, w), _add(v, u, w);}
void solve(int u) {
	h = t = 0;
	pre[q[t++] = u] = 0;
	while (h<t) {
		u = q[h++];
		sz[u] = 1;
		fore if (!vis[v] && v != pre[u]) pre[q[t++] = v] = u;
	}
	for (int i = t - 1; ~i; i--) sz[pre[q[i]]] += sz[q[i]];
	int size = sz[u = q[0]];
	for (int flag = 1; flag; ) {
		flag = 0;
		fore if (!vis[v] && pre[u] != v && sz[v] > size/2) {
			flag = 1;
			u = v;
			break;
		}
	}
	vis[u] = 1;
	static int modi[V], msz;
	msz = 0;
	fore if (!vis[v]) {
		pre[v] = u;
		int u = v;
		dis[u] = st[e].w;
		ecn[u] = 1;
		h = t = 0;
		q[t++] = u;
		while (h < t) {
			u = q[h++];
			if (dis[u] <= k) ans = std::min(ans, f[k - dis[u]] + ecn[u]);
			fore if (!vis[v] && v != pre[u]) {
				dis[v] = dis[u] + st[e].w;
				ecn[v] = ecn[u] + 1;
				pre[v] = u;
				q[t++] = v;
			}
		}
		for (int i = 0; i < t; i++) {
			u = q[i];
			if (dis[u] <= k) f[dis[u]] = std::min(f[dis[u]], ecn[u]), modi[++msz] = dis[u];
		}
	}
	ans = std::min(ans, f[k]);
	for (int i = 1; i <= msz; i++) f[modi[i]] = 0x3f3f3f3f;
	fore if (!vis[v]) solve(v);
}
int main() {
//	freopen("ioi2011-race.in", "r", stdin);
//	freopen("ioi2011-race.out", "w", stdout);
	n = gi(), k = gi();
	for (int i = 1, u, v, w; i < n; i++) u = gi() + 1, v = gi() + 1, w = gi(), add(u, v, w);
	memset(f, 0x3f, sizeof f);
	solve(1);
	printf("%d\n", ans < V ? ans : -1);
}
