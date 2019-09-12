#include <cstdio>
const int N = 110;
int a[N][N], n, m, b[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= m; i++) scanf("%d%d", &x, &y), a[x][y] = a[y][x] = 1;
	int k;scanf("%d", &k);
	int ch = 0;
	for (int i = 1, x; i <= k; i++) scanf("%d", &x), b[x] = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (b[i] && b[j] && a[i][j]) ch++;
	printf("%lf", (double)ch/2/k);
}
