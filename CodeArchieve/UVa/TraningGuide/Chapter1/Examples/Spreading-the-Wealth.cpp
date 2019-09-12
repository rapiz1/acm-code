#include <cstdio>
#include <algorithm>
typedef long long ull;
const int N =1e6 + 10;
int n;
ull a[N], x[N], s, r;
inline ull abs(ull x) {return x > 0 ? x : -x;}
int main() {
//	freopen("input", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		r = s = 0;
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), s += a[i];
		ull t = s/n;
		for (int i = 1; i < n; i++) x[i + 1] = x[i] + a[i] - t;
		std::sort(x + 1, x + 1 + n);
		for (int i = 1; i <= n; i++) r += abs(x[n/2] - x[i]);
		printf("%lld\n", r);
	}
}
