#include <cstdio>
const int N = 1e4 + 10;
int n, m ,a[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1, l, r, x; i <= m; i++) {
		scanf("%d%d%d", &l, &r, &x);
		int c = 0;
		for (int j = l; j <= r; j++) c += a[j] <= a[x];
		puts(c == x - l + 1 ? "Yes" : "No");
	}
}
