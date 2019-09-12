#include <cstdio>
#include <algorithm>
#include <cmath>
#define file(x) "gaess."#x
const int N = 100;
const double eps = 1e-8;
int n;
double a[N][N];
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n + 1; j++) scanf("%lf", &a[i][j]);
	for (int i = 1; i <= n; i++) {
		int p = i;
		for (int j = i + 1; j <= n; j++) if (fabs(a[j][i]) > fabs(a[p][i])) p = j;
		for (int j = 1; j <= n + 1; j++) std::swap(a[p][j], a[i][j]);
		if (fabs(a[i][i]) < eps) continue;
		double tmp = a[i][i];
		for (int j = 1; j <= n + 1; j++) a[i][j] /= tmp;
		for (int j = 1; j <= n; j++) if (i != j) {
			double tmp = a[j][i];
			for (int k = 1; k <= n + 1; k++) a[j][k] -= a[i][k]*tmp;
		}
	}
	int imp = 0, ult = 0;
	for (int i = 1; i <= n; i++) {
		int j = 1;
		for(;fabs(a[i][j]) < eps && j <= n + 1; j++);
		if (j > n + 1) ult = 1;
		else if (j == n + 1) imp = 1;
	}
	if (imp) puts("-1");
	else if (ult) puts("0");
	else for (int i = 1; i <= n; i++) {
		if (fabs(a[i][n + 1]) < eps) printf("x%d=0\n", i);
		else printf("x%d=%.2lf\n", i, a[i][n + 1]);
	}
}
