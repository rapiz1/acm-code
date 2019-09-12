#include <cstdio>
const int M = 1e9 + 7;
int qpow(int x, int r, int M) {
	if (!x) return 1;
	int y = 1;
	while (r) {
		if (r&1) y = (long long)y*x%M;
		x = (long long)x*x%M, r >>= 1;
	}
	return y;
}
int main() {
	int x; scanf("%d", &x);
	printf("%d\n", qpow(3, qpow(3, x, M - 1), M));
}
