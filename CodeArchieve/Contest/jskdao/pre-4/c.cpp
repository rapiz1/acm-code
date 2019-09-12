#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
typedef std::pair<double, double> pa;
const double eps = 1e-8;
int n;
std::vector<pa> f;
int sgn(double x) {
	if (x > eps) return 1;
	else if (x < eps) return -1;
	else return 0;
}
int main() {
	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		double x1, y1, x2, y2;
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		double k = 0, b;
		if (sgn(x2 - x1)) k = (y2 - y1)/(x2 - x1);
		b = x2 - k*x1;
		f.push_back(pa(k, b));
	}
	std::sort(f.begin(), f.end());
	pa ans;
	for (int i = 0, j; i < (int)f.size(); i = j + 1) {
		int cc = 0;
		for (j = i; j < (int)f.size(); j++) {
			if (!sgn(f[i].first - f[j].first) && !sgn(f[i].second - f[j].second)) cc++;
			else break;
		}
		if (cc >= n/2.0) {
			ans = f[i];
			break;
		}
	}
	printf("0\n%.10lf\n%.10lf\n%.10lf", ans.first, ans.second, ans.second);
}
