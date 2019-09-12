#include <cstdio>
const int N = 1 << 20 | 1;
int n, a[N], rk;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		rk += a[i] <= a[1];
	}
	int ans = 0;
	for (;rk!=1;rk>>=1) ans++;
	printf("%d\n", ans);
}
