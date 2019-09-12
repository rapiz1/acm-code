#include <cstdio>
#include <algorithm>
const int N = 120;
int n, m, ans = 1e9, a[N][N];
bool clear(int x) {
	for (int i = x; i <= n; i++) for (int j = 1; j <= m + 2; j++) if (a[i][j]) return 0;
	return 1;
}
void dfs(int l, int p, int now) {
	if (now > ans) return;
	int x = 0;
	if (p) {
		for (int i = m + 2; i; i--) if (a[l][i]) x = std::max(x, m + 2 - i);
	}
	else for (int i = 1; i <= m + 2; i++) if (a[l][i]) x = std::max(x, i - 1);
	if (clear(l + 1)) {
		ans = std::min(ans, now + x);
	}
	else dfs(l + 1, p, now + x*2 + 1), dfs(l + 1, p^1, now + m + 2);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m + 2; j++) scanf("%1d",&a[n - i + 1][j]);
	dfs(1, 0, 0);
	printf("%d\n", ans);
}
