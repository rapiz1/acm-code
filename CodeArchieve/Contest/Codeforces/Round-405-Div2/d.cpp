#include <cstdio>
#include <vector>
#include <cassert>
typedef long long ll;
const int N = 2e5 + 10;
int n, k; 
ll f[N][6], sz[N][6], ans;
std::vector<int> to[N];
void dfs(int u, int fa) {
	sz[u][0] = 1;
	for (int i = 0; i < to[u].size(); i++) {
		int v = to[u][i];
		if (v == fa) continue;
		dfs(v, u);
		for (int j = 0; j < k; j++) {
			for (int p = 0; p < k; p++) {
				ll ss = sz[v][(j - 1 + k)%k], ff = f[v][(j - 1 + k)%k] + ss;
				ll tmp = ff*sz[u][p] + f[u][p]*ss + (2*k - j - p)%k*sz[u][p]*ss;
//				assert(tmp%k == 0);
//				printf("%d %d : %lld\n", u, v, tmp);
				ans += tmp/k;
			}
		}
		for (int j = 0; j < k; j++) sz[u][j] += sz[v][(j - 1 + k)%k], f[u][j] += f[v][(j - 1 + k)%k] + sz[v][(j - 1 + k)%k]; 
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		int x, y;scanf("%d%d", &x, &y);
		to[x].push_back(y), to[y].push_back(x);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
}
