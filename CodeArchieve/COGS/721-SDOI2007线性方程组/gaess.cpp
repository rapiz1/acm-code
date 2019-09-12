#include<cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define file(x) "gaess."#x
const int N = 60;
const double EPS = 1e-8;
int n;
double a[N][N];
inline bool eq(double x, double y) {return fabs(x - y) <= EPS;}
void check() {
	int flag = 1;
	for (int j = 1; j <= n; j++) {
		bool alo = 1;
		for (int k = 1; k <= n; k++) if (!eq(a[j][k], 0)) alo = 0;
		if (alo) {
			if (eq(a[j][n + 1], 0)) flag = 0;
			else {
				flag = -1;
				break;
			}
		}
	}
	if (flag != 1) {
		printf("%d\n", flag);
		exit(0);
	}
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1;  j <= n + 1; j++) scanf("%lf", &a[i][j]);
	for (int i = 1; i <= n; i++) {
		int r = i;
		for (int j = i + 1; j <= n; j++) if (fabs(a[j][i]) > fabs(a[r][i]))
			r = j;
		for (int j = 1; j <= n + 1; j++) std::swap(a[i][j], a[r][j]);
		if (eq(a[i][i], 0)) continue;
		double tmp = a[i][i];
		for (int j = 1; j <= n + 1; j++) a[i][j]/=tmp;
		for (int j = 1; j <= n; j++) if (i != j) {
			tmp = a[j][i];
			for (int k = 1; k <= n + 1; k++) a[j][k] -= tmp*a[i][k];
		}
	}
	check();
	for (int i = 1; i <= n; i++) {
		printf("x%d=", i);
		if (eq(a[i][n + 1], 0)) printf("0\n");
		else printf("%.2lf\n", a[i][n + 1]);
	}
}
