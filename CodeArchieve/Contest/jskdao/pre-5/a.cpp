#include <cstdio>
#include <algorithm>
#include <functional>
const int N = 110;
int n, m, a[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	std::sort(a + 1, a + 1 + m, std::greater<int>());
	int tot = 1;
	for (int i = 0; i <= m; i++) {
		tot += a[i];
		if (tot >= n) {
			printf("%d\n", i);
			return 0;
		}
	}
	puts("Impossible");
}
