#include <bits/stdc++.h>
using namespace std;
const int V = 1e5;
vector<int> to[V];
int w[V];
bool dfs(int u, int fa) {
	for (int i = 0; i < (int)to[u].size(); i++) if (to[u][i] != fa) {
		int v = to[u][i];
		if (w[v] < w[u]) return 0;
		if (!dfs(v, u)) return 0;
	}
	return 1;
}
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) to[i].clear(), cin >> w[i];
	for (int i = 1, u, v; i < n; i++) cin >> u >> v, to[u].push_back(v), to[v].push_back(u);
	puts(dfs(1, 0) ? "Yes":"No");
}
int main() {
	int T;cin >> T;
	while (T--) solve();
}
