#include <cstdio>
#include <algorithm>
#include <vector>
#define fore for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
const int V = 4e4 + 10, E = V << 1;
int n, k, hed[V], nxt[E], sz[V], q[V], h, t, dis[V], pre[V];
bool vis[V];
struct EDGE{int u, v, w;}st[E];
void add(int u, int v, int w) {
	static int sz = 0;
	st[++sz] = (EDGE){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
int calc(int u, int d) {
	std::vector<int> dd;
	dd.push_back(dis[u] = d);
	h = t = 0;
	pre[q[t++] = u] = 0;
	while (h < t) {
		int u = q[h++];
		fore if (!vis[v] && v != pre[u]) {
			dis[v] = dis[u] + st[e].w;
			dd.push_back(dis[v]);
			pre[q[t++] = v] = u;
		}
	}
	std::sort(dd.begin(), dd.end());
	int ret = 0;
	for (int i = 0, j =  dd.size() - 1; i < j; i++) {
		while (i < j && dd[i] + dd[j] > k) j--;
		ret += j - i;
	}
	return ret;
}
int solve(int u) {
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
		fore if (!vis[v] && sz[v] > size/2 && pre[u] != v) {
			u = v;
			flag = 1;
			break;
		}
	}
	vis[u] = 1;
	int ret = calc(u, 0);
	fore if (!vis[v]) ret -= calc(v, st[e].w);
	fore if (!vis[v]) ret += solve(v);
	return ret;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%*d", &n);
	for (int i = 1, u, v, w; i < n; i++) scanf("%d%d%d%*s", &u, &v, &w), add(u, v, w), add(v, u, w);
	scanf("%d", &k);
	printf("%d\n", solve(1));
}
