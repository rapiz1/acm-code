#include <cstdio>
#include <algorithm>
const int N = 1e3 + 10;
const double EPS = 1e-8;
int n;
double l, r, a[N], b;
inline bool check() {
	bool f = 1;
	for (int i = 3; i <= n; i++) {
		a[i] = 2*a[i - 1] - a[i - 2] + 2;
		if (a[i] < 0) f = 0;
	}
	if (f) b = a[n];
	return f;
}
int main() {
//	freopen("input", "r", stdin);
	while (scanf("%d%lf", &n, &a[1]) == 2) {
		l = 0, r = 1e5;
		while (r - l > EPS) {
			a[2] = (l+r)/2;
			if (check()) r = a[2];
			else l = a[2];
		}
		printf("%.2lf\n", b);
	}
}
