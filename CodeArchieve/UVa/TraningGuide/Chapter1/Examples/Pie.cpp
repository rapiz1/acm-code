#include <cstdio>
#include <cmath>
#include <algorithm>
using std::max;
const double EPS = 1e-6;
const int N = 1e4 + 1;
double PI;
int n, f, rad[N];
double l, r, mid;
inline bool check() {
	int s = 0;
	for (int i = 1; i <= n; i++) s += int(PI*rad[i]*rad[i]/mid);
	return s >= f + 1;
}
int main() {
	PI = acos(-1);
	int T;scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &f);
		l = r = 0;
		for (int i = 1; i <= n; i++) scanf("%d", rad + i), r = max(r, PI*rad[i]*rad[i]);
		while (r - l > EPS) {
			mid = (l + r)/2;
			if (check()) l = mid;
			else r = mid;
		}
		printf("%.4f\n", l);
	}
}
