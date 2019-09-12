#include <cstdio>
const int N = 1010;
int n;
double u, v, c[N], d[N], ans;
int main() {
	scanf("%d%lf%lf", &n, &v, &u);
	for (int i = 1; i <= n; i++) scanf("%lf", c + i);
	for (int i = 1; i <= n; i++) scanf("%lf", d + i);
	for (int i = 1; i <= n; i++) for (int j = 0; j < n; j++) ans += u/(c[i] - d[i]*j - v);
	printf("%.3lf\n", ans);
}
