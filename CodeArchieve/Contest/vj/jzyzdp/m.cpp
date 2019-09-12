#include <cstdio>
#include <cstring>
#include <algorithm>
const int T = 1e5 + 10, W = 12;
int n, mxt, a[T][W], f[T][W], ans;
void solve() {
	memset(a, 0, sizeof a);
	mxt = 0;
	for (int i = 1, x, y; i <= n; i++) scanf("%d%d", &y, &x), a[x][y]++, mxt = std::max(mxt, x);
	memset(f, 0xc0, sizeof f);
	ans = 0;
	f[0][5] = 0;
	for (int i = 1; i <= mxt; i++) for (int j = 0; j <= 10; j++) {
		if (j) f[i][j] = std::max(f[i - 1][j - 1], f[i][j]);
		if (j < 10) f[i][j] = std::max(f[i - 1][j + 1], f[i][j]);
		f[i][j] = std::max(f[i][j], f[i - 1][j]);
		if (f[i][j] >= 0) {
			f[i][j] += a[i][j];
			ans = std::max(ans, f[i][j]);
		}
	}
	printf("%d\n", ans);
}
int main() {
//	freopen("input", "r", stdin);
	while (scanf("%d", &n), n) solve();
}
