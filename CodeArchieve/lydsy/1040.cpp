#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
namespace I {
	const int L = 1 << 15 | 1;
	char buf[L], *s, *t;
	inline char gc() {
		if (s == t) t = (s=buf)+fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int x = 0 , ch = gc();
		while(!isdigit(ch)) ch = gc();
		while (isdigit(ch)) x=x*10+ch-'0', ch = gc();
		return x;
	}
}using I::gi;
const int N = 1e6 + 10;
std::vector<int> to[N];
typedef long long ll;
int n, xu, xv;
ll f[N][2], w[N], ans;
bool vis[N];
void dfs(int u, int fa) {
	f[u][1] = w[u];
	f[u][0] = 0;
	for (int i = 0, v; i < (int)to[u].size(); i++) if ((v=to[u][i]) != fa) {
		if (u == xu && v == xv) continue;
		if (v == xu && u == xv) continue;
		dfs(v, u);
		f[u][1] += f[v][0];
		f[u][0] += std::max(f[v][0], f[v][1]);
	}
}
void find(int u, int fa) {
	vis[u] = 1;
	std::sort(to[u].begin(), to[u].end());
	to[u].resize(std::unique(to[u].begin(), to[u].end()) - to[u].begin());
	for (int i = 0, v; i < (int)to[u].size(); i++) if ((v=to[u][i]) != fa) {
		if (vis[v]) xu = u, xv = v;
		else find(v, u);
	}
}
ll work(int u) {
	xu=xv=0;
	find(u, 0);
	if (!xu) {
		dfs(u, 0);
		return std::max(f[u][0], f[u][1]);
	}
	dfs(xu, 0);
	ll tmp = f[xu][0];
	w[xv] = -1e16;
	dfs(xu, 0);
	tmp = std::max(tmp, std::max(f[xu][0], f[xu][1]));
	return tmp;
}
int main() {
	n=gi();
	for (int i = 1; i <= n; i++) {
		int x;
		w[i]=gi(), x=gi();
		to[i].push_back(x), to[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) ans += work(i);
	printf("%lld\n", ans);
}
