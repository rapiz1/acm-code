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
int sz[N];
int find(int u, int fa) {
	sz[u] = 1;
	vis[u] = 1;
	for (int i = 0, v; i < (int)to[u].size(); i++) if ((v = to[u][i]) != fa && in[v]) sz[u] += find(to[u][i], u);
	return sz[u];
}
void mkcent(int u) {
	cent.clear();
	int cval = 1e9;
	find(u, 0);
	for (int i = 1; i <= n; i++) if (in[i]) {
		int mxs = sz[u] - sz[i];
		for (int j = 0; j < (int)to[i].size(); j++) {
			int v = to[i][j];
			if (in[v] && sz[v] < sz[i]) mxs = std::max(mxs, sz[v]);
		}
		if (cval > mxs) cent.clear(), cent.push_back(i), cval = mxs;
		else if (cval == mxs) cent.push_back(i);
	}
}
const ull F = rand(), C = rand();
ull dfs(int u, int fa) {
	ull ret = 7;
	std::vector<ull> chv;
//	chv.push_back(C);
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (in[v] && v != fa) {
			chv.push_back(dfs(v, u));
		}
	}
	std::sort(chv.begin(), chv.end());
	for (int i = 0; i < int(chv.size()); i++) ret = (ret*F) ^ chv[i];
	return ret*C;
}
bool check(ull& ret) {
	memset(vis, 0, sizeof vis);
	std::vector<ull> tmp;
	for (int i = 1; i <= n; i++) if (in[i]) {
		mkcent(i);
		for (int j = 0; j < (int)cent.size(); j++) tmp.push_back(dfs(cent[j], 0));
		break;
	}
	for (int i = 1; i <= n; i++) if (in[i] && !vis[i]) return 0;
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
