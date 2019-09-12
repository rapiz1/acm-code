#include <cstdio>
#include <algorithm>
#include <vector> 
const int N = 2e5 + 10;
typedef long long ll;
int n, p, val;
bool vis[N];
std::vector<int> to[N];
struct Edge{int u, v, a, b, c;}st[N];
struct Exp{int k, c;}ans[N];
int qpow(int x, int r) {
	x%=p;
	if (!x) return 0;
	int y = 1;
	for (; r; r>>=1, x = (ll)x*x%p) if (r&1) y = (ll)y*x%p;
	return y;
}
void dfs(int u, int fa) {
	vis[u] = 1;
	for (int i = 0; i < (int)to[u].size(); i++) {
		int e = to[u][i], v = st[e].v;
		if (v == fa) continue;
		int d = qpow(p - st[e].b%p, p - 2);
		Exp tmp;
		tmp.k = (ll)st[e].a*ans[u].k%p*d%p;
		tmp.c = ((ll)st[e].a*ans[u].c%p + p - st[e].c)%p*d%p;
		if (vis[v]) {
			val = (ll)qpow(ans[v].k - tmp.k + p, p - 2)*(tmp.c - ans[v].c + p)%p;
		}
		else ans[v] = tmp, dfs(v, u);
	}
}
int main() {
//	freopen("data1.in", "r", stdin);
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d%d", &st[i].u, &st[i].v, &st[i].a, &st[i].b, &st[i].c);
		st[i+n] = st[i];
		std::swap(st[i+n].u, st[i+n].v);
		std::swap(st[i+n].a, st[i+n].b);
		to[st[i].u].push_back(i);
		to[st[i].v].push_back(i+n);
	}
	ans[1] = {1, 0};
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", int(((ll)val*ans[i].k%p + ans[i].c)%p));
	}
}
