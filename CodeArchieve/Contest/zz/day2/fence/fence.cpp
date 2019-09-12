#include <cstdio>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>
const int N = 55, M = 1025;
int n, m, hv[N], ned[M], ans;
void dfs(int p, int na) {
	if (p > m) {
		if (na > ans) ans = na, printf("%d\n", ans);
		return;
	}
	int lf = 0, opt = na;
	for (int i = 1; i <= n; i++) lf += hv[i];
	for (int i = p; i <= m; i++) if (lf >= ned[i]) lf -= ned[i], opt++;
	else break;
	if (opt <= ans) return;
	for (int i = 1, la = -1; i <= n; i++) if (hv[i] >= ned[p]) {
		if (la == hv[i]) continue;
		hv[i] -= ned[p];
		dfs(p + 1, na + 1);
		hv[i] += ned[p];
		la = hv[i];
	}
	dfs(p + 1, na);
}
int main() {
	freopen("fence.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", hv + i);
	std::sort(hv + 1, hv + 1 + n, std::greater<int>());
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", ned + i);
	std::sort(ned + 1, ned + 1 + m);
	dfs(1, 0);
	printf("%d\n", ans);
}
