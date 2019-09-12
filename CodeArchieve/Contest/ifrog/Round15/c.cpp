#include <cstdio>
#include <algorithm>
const int N = 3e5 + 10;
int n, k, a[N], ans;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), a[i] ^= 1, a[i] += a[i - 1];
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= i && a[i] - a[j - 1] > k) j++; 
		ans = std::max(ans, i - j + 1);
	}
	printf("%d\n", ans);
}
