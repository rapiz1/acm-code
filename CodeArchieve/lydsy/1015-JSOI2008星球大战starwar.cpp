#include <cstdio>
#include <vector>
const int M = 2e5 + 10, N = M << 1;
int n, m, k, p[N], sz, des[N], ans[N];
std::vector<int> to[N];
bool rm[N];
int find(int u) {return u == p[u] ? u : p[u] = find(p[u]);}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), u++, v++, to[u].push_back(v), to[v].push_back(u);
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) scanf("%d", des + i), rm[++des[i]] = 1;
	ans[k] = n - k;
	for (int i = 1; i <= n; i++) if (!rm[i]) for (int j = 0; j < (int)to[i].size(); j++) if (!rm[to[i][j]])
		ans[k] -= find(i) != find(to[i][j]), p[find(i)] = find(to[i][j]);
	for (int i = k - 1; ~i; i--) {
		ans[i] = ans[i + 1] + 1;
		int u = des[i + 1];
		rm[u] = 0;
		for (int j = 0, v; j < (int)to[u].size(); j++) if (!rm[v = to[u][j]])
			ans[i] -= find(u) != find(v), p[find(u)] = find(v);
	}
	for (int i = 0; i <= k; i++) printf("%d\n", ans[i]);
}
