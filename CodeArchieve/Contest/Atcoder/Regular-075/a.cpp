#include <cstdio>
const int N = 110, M = 11000;
int n, f[M];
int main() {
	f[0] = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		for (int j = M - 1; j >= x; j--) f[j] |= f[j - x];
	}
	for (int i = M - 1; ~i; i--) if (f[i] && i%10) {
		printf("%d\n", i);
		return 0;
	}
	puts("0");
}
