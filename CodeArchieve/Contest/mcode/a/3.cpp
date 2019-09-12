#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
const int N = 1e5 + 10;
const double eps = 1e-6;
int n, st, sc, t[N], c[N], fd;
double mid;
bool check() {
	double hv = sc;
	for (int i = 0; i < n; i++) {
		double dd = c[i]*(mid - t[i])/(st - mid);
		hv -= dd;
	}
	if (hv > -eps) return (fd = 1);
	else return 0;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d%d", &n, &st, &sc);
	double l = 1e9, r = 0;
	for (int i = 0; i < n; i++)  scanf("%d%d", t + i, c + i), l = std::min(l, 1.0*t[i]), r = std::max(r, 1.0*t[i]);
	if (r < st) {
		l = r, r = st;
		while (r - l > eps) {
			mid = (l+r)/2;
			if (check()) l = mid;
			else r = mid;
		}
	}
	else if (l > st) {
		mid = l;
		check();
	}
	else if (l == r && r == st) fd = 1, mid = l;
	if (fd) printf("Possible\n%.4lf", mid);
	else puts("Impossible");
}
