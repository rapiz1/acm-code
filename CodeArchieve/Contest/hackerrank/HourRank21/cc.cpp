#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <vector>
typedef unsigned long long ull;
const int N = 20;
int n, ans;
std::vector<int> to[N], cent;
std::set<ull> mm;
bool in[N], vis[N];
const ull F = rand(), C = rand();
ull dfs(int u, int fa) {
	ull ret = 0;
	vis[u] = 1;
	std::vector<ull> chv;
	chv.push_back(C);
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (in[v] && v != fa) {
			chv.push_back(dfs(v, u));
		}
	}
	std::sort(chv.begin(), chv.end());
	for (int i = 0; i < int(chv.size()); i++) ret = (ret*F) ^ chv[i];
	return ret;
}
bool check(ull& ret) {
	memset(vis, 0, sizeof vis);
	std::vector<ull> tmp;
	for (int i = 1; i <= n; i++) if (in[i]) {
		tmp.push_back(dfs(i, 0));
		for (int i = 1; i <= n; i++) if (in[i] && !vis[i]) return 0;
	}
	std::sort(tmp.begin(), tmp.end());
	ret = tmp[0];
	return 1;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) val[i] = (ull)rand()*rand();
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), to[u].push_back(v), to[v].push_back(u);
	for (int s = 1; s < 1 << n; s++) {
		for (int j = 0; j < n; j++) in[j + 1] = s>>j&1;
		ull hv;
		if (!check(hv)) continue;
		if (!mm.count(hv)) ans++, mm.insert(hv);
	}
	printf("%d\n", ans);
}
