#include <cstdio>
#include <algorithm>
const int N = 3e5 + 10;
int n, a[N], b[N];
bool build(int o, int l, int r, int p) {
	b[o] = a[p];
	if (l == r) return 1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	std::sort(a + 1, a + 1 + n);
	if (build(1, 1, n, 1)) {
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d ", b[i]);
	}
	else puts("NO");
}
