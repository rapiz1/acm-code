#include <cstdio>
#include <algorithm>
const int N = 110, M = 1100, MOD = 31011;
int n, m, p[N], ans = 1;
struct EDGE{int u, v, w;
	bool operator<(const EDGE& b)const {return w < b.w;}
	inline void un() {p[u] = w;}
	inline void ap() {p[u] = v;}
}st[M], oper[M], uu[M];
int find(int x) {return p[x] == x ? x : find(p[x]);}
int clk;
int dfs(int p, int end, int dd, int tot) {
	if (dd >= tot) return 1;
	if (p > end) return 0;
	if (end - p + 1 + dd < tot) return 0;
	int ret = dfs(p + 1, end, dd, tot);
	int x = find(st[p].u), y = find(st[p].v);
	if (x != y) {
		(uu[clk++] = (EDGE){x, y, ::p[x]}).ap();
		ret = (ret + dfs(p + 1, end, dd + 1, tot))%MOD;
		uu[--clk].un();
	}
	return ret%MOD;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &st[i].u, &st[i].v, &st[i].w);
	for (int i = 1; i <= n; i++) p[i] = i;
	std::sort(st + 1, st + 1 + m);
	for (int i = 1; i <= m; i++) {
		int cc = 0, beg = i, time = 0;
		while (i <= m && st[i].w == st[beg].w) {
			int x, y;
			if ((x = find(st[i].u)) != (y = find(st[i].v))) {
				(oper[++time] = (EDGE){x, y, p[x]}).ap();
				cc++;
			}
			i++;
		}
		i--;
		for (int k = 1; k <= time; k++) oper[k].un();
		int rr = dfs(beg, i, 0, cc);
		ans = ans*rr%MOD;
		for (int k = 1; k <= time; k++) oper[k].ap();
	}
	for (int i = 1; i <= n; i++) if (find(i) != find(1)) {
		ans = 0;
		break;
	}
	printf("%d\n", ans);
}
