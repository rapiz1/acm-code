#include <cstdio>
#include <algorithm>
const int N = 5e5 + 10;
int n, f[N], a[N];
int main() {
	freopen("fuel.in", "r", stdin);
	freopen("fuel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		for (int i = n; i; i--) f[i] = std::max(f[i - 1] + (i == x), f[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = std::max(ans, f[i]);
	printf("%d\n", ans);
}
