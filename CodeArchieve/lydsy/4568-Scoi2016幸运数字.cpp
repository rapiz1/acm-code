#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cassert>
typedef long long ll;
const int V = 2e4 + 10, K = 60;
int n, q, fa[V][20], dep[V];
ll val[V];
std::vector<int> to[V];
struct BASE{
	ll r[61];
	BASE(){memset(r, 0, sizeof r);}
	void ins(ll x) {
		for (int i = K; ~i; i--) if (x>>i&1) {
			if (r[i]) x ^= r[i];
			else {
				r[i] = x;
				break;
			}
		}
	}
	void operator+=(const BASE& b){
		for (int i = K; ~i; i--) if (b.r[i]) ins(b.r[i]);
	}
	inline ll span() {
		ll ret = 0;
		for (int i = K; ~i; i--) ret = std::max(ret, ret^r[i]);
		return ret;
	}
}bas[V][20];
void dfs(int u) {
	for (int i = 1; i <= 16; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 1; i <= 16; i++) bas[u][i] = bas[u][i - 1], bas[u][i] += bas[fa[u][i - 1]][i - 1];
	for (int i = 0; i < (int)to[u].size(); i++) {
		int v = to[u][i];
		if (v == fa[u][0]) continue;
		dep[v] = dep[u] + 1;
		fa[v][0] = u;
		bas[v][0].ins(val[u]), bas[v][0].ins(val[v]);
		dfs(v);
	}
}
int main() {
//	freopen("input", "r", stdin);
//	freopen("output", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%lld", val + i);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), to[u].push_back(v), to[v].push_back(u);
	dfs(1);
	while(q--) {
		int u, v;scanf("%d%d", &u, &v);
		BASE ans;
		ans.ins(val[u]), ans.ins(val[v]);
		if (dep[u] < dep[v]) std::swap(u, v);
		for (int x = dep[u] - dep[v], i = 16; ~i; i--) 
			if (x>>i&1) ans += bas[u][i], u = fa[u][i];
		for (int i = 16; ~i; i--) if (fa[u][i] != fa[v][i]) 
			ans += bas[u][i], ans += bas[v][i], u = fa[u][i], v = fa[v][i];
		if (u != v) ans.ins(val[fa[u][0]]), u =fa[u][0];
#ifdef DBG
			printf("lca stoped at %d %d with %d\n", u, v, fa[u][0]);
#endif
			printf("%lld\n", ans.span());
	}
//	printf("glc: %d\n", glc);
}
