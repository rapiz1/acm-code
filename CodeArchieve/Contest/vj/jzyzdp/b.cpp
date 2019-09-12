#include <cstdio>
#include <algorithm>
const int N = 1e4 + 10;
int n, a[N], ans;
short f[N][N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	std::sort(a + 1, a + 1 + n);
	for (int i = n; i; i--) {
		int p = i;
		for (int j = i + 1; j <= n; j++) {
			int d = a[j] - a[i];
			for (;p <= n && a[j] + d > a[p]; p++);
			if (p <= n && a[p] - a[j] == d) f[i][j] = f[j][p] + 1;
			else f[i][j] = 2;
			ans = std::max(ans, (int)f[i][j]);
		}
	}
	printf("%d\n", ans);
}
