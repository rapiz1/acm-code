#include <cstdio>
#include <vector>
const int N = 1e5 + 10;
int n, sz[N], dep[N];
std::vector<int> to[N];
long long ds[N], dss;
void dfs(int u, int fa = 0) {
	sz[u] = 1;
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
void calc(int u, int fa = 0){ 
	ds[u] = ds[fa] + (long long)(sz[fa] - sz[u])*dep[fa];
	dss += dep[u];
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (v == fa) continue;
		calc(v, u);
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), to[u].push_back(v), to[v].push_back(u);
	dfs(1);
	calc(1);
	for (int u = 1; u <= n; u++) 
		printf("%lld\n", (long long)n*dep[u] + dss - ((long long)sz[u]*dep[u] + ds[u])*2);
}
