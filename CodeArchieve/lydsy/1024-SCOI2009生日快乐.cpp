#include <cstdio>
#include <algorithm>
#include <cmath>
double dfs(int n, double x, double y) {
	if (n == 1) return exp(fabs(log(x/y)));
	double ans = 1e18;
	for (int i = 1; i < n; i++) 
		ans = std::min(std::max(dfs(i, x*i/n, y), dfs(n - i, x - x*i/n, y)), ans);
	std::swap(x, y);
	for (int i = 1; i < n; i++) 
		ans = std::min(ans, std::max(dfs(i, x*i/n, y), dfs(n - i, x - x*i/n, y)));
	return ans;
}
int main() {
	int n;
	double x, y; scanf("%lf%lf%d", &x, &y, &n);
	printf("%.6lf\n", dfs(n, x, y));
}
