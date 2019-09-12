#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const double eps = 1e-6;
typedef long long ll;
int n, a[N], b[N], p;
long double mid;
int sgn(double x) {
	if (x > eps) return 1;
	else if (x < -eps) return -1;
	else return 0;
}
inline bool check() {
	double left = mid*p;
	for (int i = 1; i <= n; i++) if (sgn(a[i]*mid - b[i]) > 0) {
		left -= a[i]*mid - b[i];
	}
	return left > eps;
}
int main() {
	freopen("input", "r", stdin);
	scanf("%d%d", &n, &p);
	long double l = 0, r = 0;
 	ll u = 0, s = 0;
	for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i), u += a[i], s += b[i];
	if (p >= u) {
		puts("-1");
		return 0;
	}
	r = (long double)s/(u - p);
	while (r - l > eps) {
		mid = (l + r )/2;
		if (check()) l = mid;
		else r = mid;
	}
	printf("%lf\n", (double)l);
}
