#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
const int N = 310;
const double eps = 1e-8;
int n, m, du[N][N];
double p, q, a[N][N];
bool eq(double x, double y) {return fabs(x - y) <= eps;}
int main() {
	scanf("%d%d%lf%lf", &n, &m, &p, &q);
	while (m--) {
		int u, v;scanf("%d%d",&u,&v);
		du[u][v]++, du[v][u]++;
		du[u][u]++, du[v][v]++;
	}
	for (int i= 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j && du[i][j] && du[j][j])
		a[i][j] = -(1 - p/q)*du[i][j]/du[j][j];
	for (int i = 1; i <= n; i++) a[i][i] = 1;
	a[1][n + 1] = p/q;
	for (int i = 1; i <= n; i++) {
		int r = i;
		for (int j = i + 1; j <= n; j++) if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
		for (int j = 1; j <= n + 1; j++) std::swap(a[i][j], a[r][j]);
		if (eq(a[i][i], 0)) continue;
		double tmp = a[i][i];
		for (int j = 1; j <= n + 1; j++) a[i][j] /= tmp;
		for (int j = 1; j <= n; j++) if (i != j) {
			tmp = a[j][i];
			for (int k = 1; k <= n + 1; k++) a[j][k] -= tmp*a[i][k];
		}
	}
	for (int i = 1; i <= n; i++) printf("%.9lf\n", eq(a[i][n + 1], 0) ? 0 : a[i][n + 1]);
}
