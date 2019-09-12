#include <cstdio>
#include <utility>
#include <algorithm>
const int N = 1010, M = 1010;
int n, m, a[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (a[n] <= r) {
			printf("%d", std::max(a[n], l));
			return 0;
		}
	}
	puts("-1");
}
