#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define fore for (int i = 0, v; i < (int)to[u].size(); i++)
const int N = 100010, V = 2e6, K = 20;
int n, m, val[N], hed[N], h, t, fa[N], sz[N], q[V], pre[N], dis[V], beg[N], end[N], a[V];
bool vis[N];
std::vector<int> to[N], ch[N];
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
	h = t;
	int tmp = h;
	pre[q[t++] = u] = 0;
	while (h < t) {
		int u = q[h++];
		sz[u] = 1;
		fore if (!vis[v = to[u][i]] && pre[u] != v)  pre[q[t++] = v] = u;
	}
	for (int i = t - 1; i >= tmp; i--) sz[pre[q[i]]] += sz[q[i]];
	t = tmp;
	int size = sz[u];
	for (int flag = 1; flag; ) {
		flag = 0;
		fore if (!vis[v = to[u][i]] && pre[u] != v && sz[v] > size/2) {
			u = v;
			flag = 1;
			break;
		}
	}
	vis[u] = 1;
	ch[fa[u] = p].push_back(u);
	fore if (!vis[v = to[u][i]]) {
		beg[v] = h = t;
		dis[t] = 1;
		pre[q[t++] = v] = 0;
		while (h < t) {
			int u = q[h], dd = dis[h++];
			fore if (!vis[v = to[u][i]] && v != pre[u]) {
				dis[t] = dd + 1;
			 	pre[q[t++] = u] = 0;
			}
		}
		end[v] = t;
		build(v, u);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", val + i);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v),
		to[u].push_back(v), to[v].push_back(u);
	build(1, 0);
	for (int i = 0; i < t; i++) add(i, val[q[i]]);
	while (m--) {
		int x, y, z;scanf("%d%d%d", &x, &y, &z);
		if (x) {
			int ret = 0;
			printf("%d\n", ret);
		}
		else {
		}
	}
}
