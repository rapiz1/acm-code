#include <cstdio>
#include <vector>
#include <cstring>
const int N = 1e3 + 10;
int n, s, k, dep[N], fa[N];
bool isl[N], dd[N];
std::vector<int> to[N];
void dfs(int u) {
	isl[u] = 1;
	for (int i = 0, v; i < to[u].size(); i++) if ((v = to[u][i]) != fa[u]) {
		dep[v] = dep[u] + 1;
		fa[v] = u;
		isl[u] = 0;
		dfs(v);
	}
}
void cover(int u, int d, int fa) {
	dd[u] = 1;
	if (d == k) return;
	for (int i = 0, v; i < to[u].size(); i++) if ((v = to[u][i]) != fa) {
		cover(v, d + 1, u);
	}
}
int nd() {
	int x = 0;
	for (int i = 1; i <= n; i++) if (isl[i] && !dd[i] && dep[i] > dep[x]) x = i;
	return x;
}
inline int up(int x) {
	for (int i = 1; i <= k; i++) if (fa[x]) x = fa[x];else break;
	return x;
}
int main() {
//	freopen("input", "r", stdin);
	int T;scanf("%d", &T);
	dep[0] = -1;
	while (T--) {
		for (int i = 1; i <= n; i++) to[i].clear();
		memset(dep, 0, sizeof(dep));
		memset(isl, 0, sizeof(isl));
		memset(dd, 0, sizeof(dd));
		scanf("%d%d%d", &n, &s, &k);
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
		fa[s] = 0;
		dfs(s);
		cover(s, 0, 0);
		int i, j;
		for (j = 0; i = nd(); cover(up(i), 0, 0), j++);
		printf("%d\n", j);
	}
}
