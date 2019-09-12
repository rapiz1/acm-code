#include <cstdio>
#include <algorithm>
int n, mid, prev;
double a, b;
inline bool check() {
	return int((prev + double(mid))/(n + mid)*10 + 0.5)/10.0 <= b;
}
int main() {
	freopen("film.in", "r", stdin);
	freopen("film.out", "w", stdout);
	while (scanf("%lf%lf%d", &a, &b, &n) == 3) {
		int l = 0, r = 1e8;
		prev = std::min((a + 0.05 - 1e-8), 10.0)*n;
		while (l < r) {
			mid = (l + r) >> 1;
//			printf("%d %d %d\n", l, mid, r);
			if (check()) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
}
