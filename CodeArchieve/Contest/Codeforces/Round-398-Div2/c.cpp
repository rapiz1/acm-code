#include <cstdio>
#include <vector>
#include <cstdlib>
const int N = 1e6 + 10;
int n, fa[N], sz[N], w[N], rt, tot, ans[N];
std::vector<int> ch[N];
int dfs(int u) {
	sz[u] = w[u];
	for (int i = 0; i < ch[u].size(); i++) {
		sz[u] += dfs(ch[u][i]);
		if (ans[ch[u][i]]) {
			if (ans[u]) {
				printf("%d %d\n", ans[u], ans[ch[u][i]]);
				exit(0);
			}
			else ans[u] = ans[ch[u][i]];
		}
	}
	if (ans[u] && sz[u] == tot*2 && u != rt) {
		printf("%d %d\n", ans[u], u);
		exit(0);
	}
	ans[u] = sz[u] == tot ? u : ans[u];
	return sz[u];
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", fa + i, w + i), rt = fa[i] == 0 ? i : rt, tot += w[i], ch[fa[i]].push_back(i);
	if (tot%3) {
		puts("-1");
		return 0;
	}
	tot/=3;
	dfs(rt);
	puts("-1");
}
