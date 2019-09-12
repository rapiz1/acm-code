#include <cstdio>
#include <vector>
#include <cstring>
#define file(x) "graphgame."#x
const int N = 1010; 
int n1, n2, m, f[N];
bool vis[N], cov[N];
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
	scanf("%d%d%d", &n1, &n2, &m);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), to[u].push_back(n1 + v), to[n1 + v].push_back(u);
	for (int i = 1; i <= n1; i++) memset(vis, 0, sizeof vis), find(i);
	for (int i = 1, x; i <= n1 + n2; i++) if (f[i]) {
		memset(vis, 0, sizeof vis);
		f[i] = f[x = f[i]] = 0;
		vis[i] = 1;
		if (cov[i] = !find(x)) f[f[i] = x] = i;
	}
	for (int i = 1; i <= n1 + n2; i++) {
		putchar(cov[i]?'N':'P');
		if (i == n1 || i == n2) putchar('\n');
	}
}
