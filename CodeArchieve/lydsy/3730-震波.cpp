#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define fore for (int i = 0, v; i < (int)to[u].size(); i++)
const int N = 100010, V = 2e6, K = 20;
int n, m, val[N], hed[N], h, t, fa[N], sz[N], cnt, q[V], pre[N], dis[N], beg[N], end[N], a[V], anc[V][K], dep[V];
bool vis[N];
std::vector<int> to[N];
std::map<int, int> mm[N];
inline int lowbit(int x) {return x&-x;}
void add(int p, int v) {
	for(;p<=t;p+=lowbit(p)) a[p]+=v; 
}
int pp(int p) {
	int ret = 0;
	for(;p;p-=lowbit(p)) ret += a[p];
	return ret;
}
inline int sum(int l, int r) {return pp(r) - pp(l - 1);}
void build(int u, int p) {
	h = t = cnt;
	pre[q[t++] = u] = 0;
	while (h < t) {
		int u = q[h++];
		fore if (!vis[v = to[u][i]] && pre[u] != v)  pre[q[t++] = v] = u;
	}
	for (int i = t - 1; i >= cnt; i--) sz[pre[q[i]]] += sz[q[i]];
	int size = sz[u];
	for (int flag = 1; flag; ) {
		flag = 0;
		fore if (!vis[v = to[u][i]] && pre[u] != v && sz[v] > size/2) {
			u = v;
			flag = 1;
			break;
		}
	}
	beg[u] = cnt;
	end[u] = cnt = t;
	vis[u] = 1;
	fa[u] = p;
	h = t = beg[u];
	dis[u] = 0;
	pre[q[t++] = u] = 0;
	std::map<int, int> nm = mm[u];
	while (h < t) {
		int u = q[h++];
		nm[u] = h - 1;
		fore if (!vis[v = to[u][i]] && pre[u] != v) {
			dis[v] = dis[u] + 1;
			pre[q[t++] = v] = u;
		}
	}
	for (int i = beg[u]; i < end[u]; i++) add(q[i], val[q[i]]);
	fore if (!vis[v = to[u][i]]) build(v, u);
}
void dfs(int u) {
	for (int i = 1; i < K; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	fore if ((v = to[u][i]) != anc[u][0]) {
		anc[v][0] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}
int lca(int u, int v) {
	if (dep[u] > dep[v]) std::swap(u, v);
	for (int x = dep[u] - dep[v], i = 0; x; x>>=1, i++) if (x&1) u = anc[u][i];
	for (int i = K - 1; ~i; i--) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	return u == v ? u : anc[u][0];
}
inline int gdis(int u, int v) {return dep[u] + dep[v] - 2*dep[lca(u,v)];}
int cmp(int a, int b) {return dis[a] < dis[b];}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", val + i);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v),
		to[u].push_back(v), to[v].push_back(u);
	build(1, 0);
	while (m--) {
		int x, y, z;scanf("%d%d%d", &x, &y, &z);
		if (x) {
			int ret = 0;
			for (int u = y; u; u = fa[u]) {
				int dd = gdis(u, y);
				dis[V - 1] = z - dd;
			 	int pos = std::lower_bound(q + beg[u], q + end[u], V - 1, cmp) - q;
				ret += sum(beg[u], pos);
			}
			printf("%d\n", ret);
		}
		else {
			for (int u = y; u; u = fa[u]) {
				int pos = mm[u][y];
				add(pos, z - val[y]);
			}
		}
	}
}
