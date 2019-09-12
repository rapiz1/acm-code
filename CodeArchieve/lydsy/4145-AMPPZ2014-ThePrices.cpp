#include <cstdio>
#include <algorithm>
#include <cstring>
using std::min;
const int N = 110, M = 16;
int f[N][1 << M], n, m, c[N][M + 2];
int main() {
	memset(f, 0x3f, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 0; j <= m; j++) scanf("%d", &c[i][j]);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int s = 0; s < 1 << m; s++) f[i][s] = f[i - 1][s] + c[i][0];
		for (int j = 1; j <= m; j++) for (int s = 0; s < 1 << m; s++) 
			f[i][s|(1 << j -1)] = min(f[i][s|(1 << j - 1)], f[i][s] + c[i][j]);
		for (int s = 0; s < 1 << m; s++) f[i][s] = min(f[i][s], f[i - 1][s]);
	}
	printf("%d", f[n][(1 << m) - 1]);
}
