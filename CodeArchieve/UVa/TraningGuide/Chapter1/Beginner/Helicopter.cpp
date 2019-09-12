#include <cstdio>
#include <cmath>
#include <algorithm>
int a[10];
inline double calc() {
	double x = a[1] + a[2] + a[3] - a[5] - a[6] - a[7];
	double y = a[1] + a[8] + a[7] - a[3] - a[4] - a[5];
	return sqrt(x*x + y*y);
}
int main() {
	while (1) {
		double ans = 1e200;
		for (int i = 1; i <= 8; i++) scanf("%d", a + i);
		bool ls = 1;
		for (int i = 1; i <= 8; i++) if (a[i] != 0) ls = 0;
		if (ls) break;
		for (int i = 1; i <= 40320; i++, std::next_permutation(a + 1, a + 1 + 8)) ans = std::min(ans, calc()); 
		printf("%.3lf\n", ans);
	}
}
