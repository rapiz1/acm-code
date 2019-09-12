#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
const int N = 20;
int n;
double a[N][N], x[N][N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n + 1; i++) 
		for (int j = 1; j <= n; j++) scanf("%lf", &a[i][j]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			x[i][j] = 2*(a[n + 1][j] - a[i][j]),
			x[i][n + 1] += pow(a[n + 1][j], 2) - pow(a[i][j], 2);
	}
	for (int i = 1; i <= n; i++) {
		int r = i;
		for (int j = i + 1; j <= n; j++) if (fabs(x[j][i]) > fabs(x[r][i]))
			r = j;
		for (int j = 1; j <= n + 1; j++) std::swap(x[i][j], x[r][j]);
		double tmp = x[i][i];
		for (int j = 1; j <= n + 1; j++) x[i][j]/=tmp;
		for (int j = 1; j <= n; j++) if (i != j) {
			tmp = x[j][i];
			for (int k = 1; k <= n + 1; k++) x[j][k] -= tmp*x[i][k];
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%.3lf", x[i][n + 1]);
		if (i != n) putchar(' ');
	}
}
