#include <cstdio>
#include <algorithm>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
typedef long long ll;
const int V = 1e5 + 10, E = V << 1;
int n, hed[V], nxt[E], sz[V], q[V], h, t, pre[V];
ll g[V << 2][2], f[V << 2][2], ans;
bool vis[V];
struct EDGE{int u, v, w;}st[E];
void add(int u, int v, int w) {
	static int sz = 0;
	st[++sz] = (EDGE){u, v, w};
	nxt[sz] = hed[u], hed[u]=  sz;
}
int ext[V << 2];
int dfs(int u, int fa, int dis) {
	if (ext[dis + V]) g[dis + V][1]++;
	else g[dis + V][0]++;
	ext[dis + V]++;	
	int dep = 1;
	fore if (!vis[v] && v != fa) {
		dep = std::max(dep, dfs(v, u, dis + st[e].w) + 1);
	}
	ext[dis + V]--;
	return dep;
}
void solve(int u) {
	h = t = 0;
	pre[q[t++] = u] = 0;
	while (h < t) {
		int u = q[h++];
		sz[u] = 1;
		fore if (!vis[v] && pre[u] != v) {
			pre[v] = u;
			q[t++] = v;
		}
	}
	for (int i = t - 1; ~i; i--) sz[pre[q[i]]] += sz[q[i]];
	int size = sz[u];
	for (int flag = 1;flag;) {
		flag = 0;
		fore if (!vis[v] && sz[v] > size/2 && pre[u] != v) {
			u = v;
			flag = 1;
			break;
		}
	}
	vis[u] = 1;
	int tot = 0;
	f[V][0] = 1;
	fore if (!vis[v]) {
		int dep = dfs(v, u, st[e].w);
		tot = std::max(dep, tot);
		ans += (f[V][0] - 1)*g[V][0];
		for (int i = -dep; i <= dep; i++) {
			int j = i + V;	
			ans += f[2*V - j][0]*g[j][1] + f[2*V - j][1]*g[j][0] + f[2*V - j][1]*g[j][1];
		}
		for (int i = -dep; i <= dep; i++) {
			int j = i + V;	
			f[j][0] += g[j][0], f[j][1] += g[j][1];
			g[j][0] = g[j][1] = 0;
		}
	}
	for (int i = -tot; i <= tot; i++) {
		int j = i + V;
		f[j][0] = f[j][1] = 0;
	}
	fore if (!vis[v]) solve(v);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, u, v, w; i < n; i++) scanf("%d%d%d", &u, &v, &w), w = w ? 1 : -1, add(u, v, w), add(v, u, w);
	solve(1);
	printf("%lld\n", ans);
}
