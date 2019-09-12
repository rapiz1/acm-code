#include <cstdio>
int main() {
	long long n;
	while (scanf("%lld", &n) == 1) {
		int x = 0;
		while (n) ++x, n>>=1;
		printf("%d\n", x);
	}
}
