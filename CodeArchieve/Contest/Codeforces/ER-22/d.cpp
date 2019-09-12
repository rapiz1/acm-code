#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
const int N = 5e3 + 10, W = 1e5 + 10;
int n, a[N], f[N][N], mm[N], mw[W], ans;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 0; i <= n; i++) {
		memset(mm, 0, sizeof mm);
		memset(mw, 0, sizeof mw);
		for (int j = 1; j < i; j++) {
			mw[a[j]] = std::max(mw[a[j]], f[i][j]);
			mm[a[j]%7] = std::max(mm[a[j]%7], f[i][j]);
		}
		for (int j = i + 1; j <= n; j++) {
			f[i][j] = std::max(f[i][j], std::max(std::max(mw[a[j] + 1], mw[a[j] - 1]), mw[a[j]]) + 1);
			f[i][j] = std::max(f[i][j], mm[a[j]%7] + 1);
			f[i][j] = std::max(f[i][j], f[i][0] + 1);
			f[j][i] = f[i][j];
			mw[a[j]] = std::max(mw[a[j]], f[i][j]);
			mm[a[j]%7] = std::max(mm[a[j]%7], f[i][j]);
			ans = std::max(ans, f[i][j]);
//			printf("%d %d: %d\n", i, j, f[i][j]);
		}
	}
	printf("%d\n", ans);
}	
