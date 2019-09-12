#include <cstdio>
typedef long long ll;
const int N = 1010;
int a[N], b[N], n, m;
ll ans = 1e18;
int main() {
	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", b + i);
	for (int i = 1; i + n - 1 <= m; i++) {
		ll di = 0;
		for (int k = i; k <= i + n - 1; k++)
		 	di += (a[k - i + 1] - b[k])*(a[k - i + 1] - b[k]);
		if (di < ans) ans = di;
	}
	printf("%lld\n", ans);
}
