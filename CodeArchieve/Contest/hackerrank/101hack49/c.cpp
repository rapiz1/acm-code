#include <cstdio>
#include <vector>
const int N = 1e5 + 10;
typedef long long ll;
typedef std::vector<int> num;
int n, co[N], hed[N], nxt[N << 1], sz;
ll ans;
struct Edge{int u, v, w;}st[N << 1];
struct Info {
	std::vector<ll> sum, num;
	Info() {sum.resize(2);num.resize(2);}
};
inline void _add(int u, int v, int w) {
	st[++sz] = (Edge){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
inline void add(int u, int v, int w) {
	_add(u, v, w), _add(v, u, w);
}
Info dfs(int u, int fa) {
	Info ret, x;
	ret.num[co[u]] = 1;
	for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) if (v != fa) {
		x = dfs(v, u);
		x.sum[0] += x.num[0]*st[e].w;
		x.sum[1] += x.num[1]*st[e].w;
		ans += ret.num[0]*x.sum[1] + ret.num[1]*x.sum[0] + x.num[1]*ret.sum[0] + x.num[0]*ret.sum[1];
		ret.num[0] += x.num[0], ret.num[1] += x.num[1];
		ret.sum[0] += x.sum[0], ret.sum[1] += x.sum[1];
	}
	return ret;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", co + i);
	for (int i = 1, u, v, w; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
}
