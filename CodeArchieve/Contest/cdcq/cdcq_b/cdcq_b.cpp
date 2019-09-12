#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <vector>
#define file(x) "cdcq_b."#x
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
namespace I {
	const int L = 1 << 15 | 1;
	char *s, *t, buf[L];
	inline char gc() {
		if ( s== t) t = (s = buf) + fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int ch, r = 0, f = 1;
		do {
			ch = gc(); 
			if (ch == '-') f = -1;
		}while (!isdigit(ch));
		for(;isdigit(ch);ch = gc()) r = r*10 + ch - '0';
		return r*f;
	}
}using I::gi;
const double EPS = 1e-4, INF = 1e18, eps = 1e-8;
const int V = 2e5 + 10, E = V << 1;
inline int sgn(double x) {
	if (x < -eps) return -1;
	else if (x > eps) return 1;
	else return 0;
}
int n, m, a[V], b[V], q[V], h, t, sz[V], pre[V], vcn[V], hed[V], nxt[E];
struct Edge{int u, v;}st[E];
void add(int u, int v) {
	static int sz = 0;
	st[++sz] = (Edge){u,v};
	nxt[sz] = hed[u], hed[u] = sz;
}
double ret, w[V], f[V], dis[V];
bool vis[V];
void solve(int u) {
	h = t = 0;
	pre[q[t++] = u] = 0;
	while (h < t) {
		int u = q[h++];
		sz[u] = 1;
		fore if (!vis[v] && pre[u] != v) pre[q[t++] = v] = u;
	}
	for (int i = t - 1; ~i; i--) sz[pre[q[i]]] += sz[q[i]];
	{
		int size = sz[u];
		for (int flag = 1; flag; ) {
			flag = 0;
			fore if (!vis[v] && v != pre[u] && sz[v] > size/2) {
				u = v;
				flag = 1;
				break;
			}
		}
	}
	//printf("%d\n", u);
//	assert(nu == u);
	vis[u] = 1;
	static int modi[V], msz;
	f[modi[msz++] = 1] = w[u];
	if (m == 1) ret = std::min(ret, w[u]);
	fore if (!vis[v]) {
		h = t = 0;
		pre[q[t++] = v] = u;
		int rt = u;
		int u = v;
		dis[u] = w[u];
		vcn[u] = 1;
		while (h < t) {
			int u = q[h++];
			if (vcn[u] <= m && dis[u] + f[m - vcn[u]] < ret && f[m - vcn[u]] != INF) 
				ret = dis[u] + f[m - vcn[u]];
			fore if (!vis[v] && v != pre[u]) {
				dis[v] = dis[u] + w[v];
				vcn[v] = vcn[u] + 1;
				pre[q[t++] = v] = u;
			}
		}
		for (int i = 0; i < t; i++) f[vcn[q[i]] + 1] = std::min(f[vcn[q[i]] + 1], dis[q[i]] + w[rt]), modi[msz++] = vcn[q[i]] + 1;
	}
	while (msz) f[modi[--msz]] = INF; 
	fore if (!vis[v]) solve(v);
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	n = gi(), m = gi();
	double l = 0, r = 0;
	for (int i = 1; i <= n; i++) a[i] = gi(), f[i] = INF, r = std::max(r, 1.0*a[i]);
	for (int i = 1; i <= n; i++) b[i] = gi();
	for (int i = 1, u, v; i < n; i++) u = gi(), v = gi(), add(u,v),add(v,u);
	if (m == -1) {
		double ans = (double)a[1]/b[1];
		for (int i = 1; i <= n; i++) ans = std::min(ans, (double)a[i]/b[i]);
		printf("%.2lf\n", ans);
		return 0;
	}
	while (r - l > EPS) {
		double mid = (l + r)/2;
		ret = INF;
		for (int i = 1; i <= n; i++) vis[i] = (pre[i] = sz[i] = dis[i] = 0), w[i] = a[i] - mid*b[i], f[i] = INF;
		solve(1);
		if (sgn(ret - INF) == 0) {
			puts("-1");
			return 0;
		}
		if (ret < -eps) r = mid;
		else l = mid;
	}
	printf("%.2lf", l);
}
