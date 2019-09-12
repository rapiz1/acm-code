#include <cstdio>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>
namespace I{
	const int L = 1 << 15 | 1;
	char *s, *t, buf[L];
	inline char gc() {
		if(s==t) t=(s=buf)+fread(buf, 1, L , stdin);
		return *s++;
	}
	inline int gi() {
		int x = 0, ch=gc();
		while (!isdigit(ch)) ch=gc();
		while (isdigit(ch)) x=x*10+ch-'0', ch = gc();
		return x;
	}
}using I::gi;
const int N = 1e6 + 10, E = N << 1;
typedef long long ll;
int n, sz[N];
struct Edge{int u, v, w;}st[E];
std::vector<int> to[N];
ll ans;
void dfs(int u, int faw ,int fa) {
	sz[u] = 1;
	for (int i = 0; i < (int)to[u].size(); i++) {
		int e = to[u][i], v = st[e].v;
		if (v == fa) continue;
		dfs(v, st[e].w, u);
		sz[u] += sz[v];
	}
	ans += (ll)(abs(n - 2*sz[u]))*faw;
}
int main() {
//	freopen("input", "r", stdin);
	n=gi();
	for (int i = 1; i < n; i++) {
		int u=gi(), v=gi(), w=gi();
		st[i] = st[i + n] = (Edge){u,v , w};
		std::swap(st[i + n].u, st[i + n].v);
		to[u].push_back(i), to[v].push_back(n + i);
	}
	dfs(1, 0, 0);
	printf("%lld\n", ans);
}
