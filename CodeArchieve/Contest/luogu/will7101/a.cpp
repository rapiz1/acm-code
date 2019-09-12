#include <cstdio>
#include <vector>
const int N = 1e5 + 10, M = 10007;
std::vector<int> to[N];
int n, f[N];
bool at[N], calc[N];
int dfs(int u) {
	if (calc[u]) return f[u];
	calc[u] = 1;
	bool lf = 1;
	for (int i = 0; i < to[u].size(); i++) f[u] = (dfs(to[u][i]) + f[u])%M, lf = 0;
	if (lf) f[u] = 1;
	return f[u];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k;scanf("%d", &k);
		for (int j = 1, x; j <= k; j++) scanf("%d", &x), to[x].push_back(i);
		if (!k) at[i] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) 
		if(at[i]) ans = (ans + dfs(i))%M;
	printf("%d\n", ans);
}
