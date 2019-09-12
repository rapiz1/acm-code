#include <cstdio>
const int N = 110;
int n, m, k, ans, a[N][N];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, d, c; i <= k; i++) {
		scanf("%d%d", &d, &c);
		if (d) for (int j = 1; j <= n; j++) a[j][c] = 1;
		else for (int j = 1; j <= m; j++) a[c][j] = 1;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (!a[i][j]) {
		int w = 1, h = 1;
		while (j + w <= m && !a[i][j + w]) w++;
		while (i + h <= n && !a[i + h][j]) h++;
		ans += w*h/2;
		for (int p = 0; p < h; p++) for (int q = 0; q < w; q++) a[i + p][j + q] = 1;
	}
	printf("%d\n", ans);
}
