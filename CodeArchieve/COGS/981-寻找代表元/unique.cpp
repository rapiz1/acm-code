#include <cstdio>
#include <vector>
#include <cstring>
#define file(x) "unique."#x
const int N = 500;
int n, m, ans, f[N];
bool vis[N];
std::vector<int> to[N];
bool find(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	for (int i = 0; i < to[u].size(); i++) {
		int v = to[u][i];
		if (!vis[v]) {
			vis[v] = 1;
			if (!f[v] || find(f[v])) return f[f[v] = u] = v;
		}
	}
	return 0;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1, j; i <= n; i++)
		while (scanf("%d", &j), j) to[i].push_back(n + j), to[n + j].push_back(i);
	for (int i = 1; i <= n; i++) memset(vis, 0, sizeof vis), ans += find(i);
	printf("%d\n", ans);
}
