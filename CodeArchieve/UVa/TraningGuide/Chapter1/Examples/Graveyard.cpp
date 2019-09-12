#include <cstdio>
#include <cmath>
#include <algorithm>
const double L = 1e4;
int n, m;
int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		m += n;
		double t0 = L/n, t1 = L/m, ans = 0;
		for (int i = 1; i <= n; i++) {
			int x = floor(t0*i/t1), y = ceil(t0*i/t1);
			ans += std::min(t0*i - t1*x, t1*y - t0*i);
		}
		printf("%.4f\n", ans);
	}
}
