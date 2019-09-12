#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 250010;
int n, m, dfn[N], clk, sz[N], a[N], fa[N];
std::vector<int> to[N];
char buf[100];
inline void add(int p, int v) {
	for (;p<=n; p+=p&-p) a[p] += v;
}
int pre(int p) {
	int ret = 0;
	for (;p;p-=p&-p) ret += a[p];
	return ret;
}
void dfs(int u) {
	dfn[u] = ++clk;
	sz[u] = 1;
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (v == fa[u]) continue;
		fa[v] = u;
		dfs(v);
		sz[u] += sz[v];
	}
	add(dfn[u], 1);
	add(dfn[u] + sz[u], -1);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), to[v].push_back(u), to[u].push_back(v);
	dfs(1);
	scanf("%d", &m);
	m += n - 1;
	while (m--) {
		int x, y;
		scanf("%s%d", buf, &x);
		if (buf[0] == 'W') printf("%d\n", pre(dfn[x]) - 1);
		else {
			scanf("%d", &y);
			if (fa[x] == y) ;
			else std::swap(x, y);
			add(dfn[x], -1), add(dfn[x] + sz[x], 1);
		}
	}
}
