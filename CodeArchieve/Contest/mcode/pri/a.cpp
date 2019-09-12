#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 2010;
double f[N][N], g[N][N];
int n;
int main() {
	scanf("%d", &n);
	f[0][0] = 0;
	g[0][0] = 1;
	for (int i = 0; i < n; i++) {
		f[i+1][0] += f[i][0]*0.5;
		g[i+1][0] += g[i][0]*0.5;
		f[i+1][1] += f[i][0]*0.5;
		g[i+1][1] += g[i][0]*0.5;
		for (int j = 1 ;j <= i;j++) {
			f[i+1][j-1] += f[i][j]*0.5 + g[i][j];
			g[i+1][j-1] += g[i][j]*0.5;
			f[i+1][j+1] += f[i][j]*0.5;
			g[i+1][j+1] += g[i][j]*0.5;
		}
	}
	for (int i = 0; i < n; i++) f[n][n] += f[n][i];
	printf("%.3lf\n", n-f[n][n]);
}
