#include <cstdio>
const int N = 1e5 + 10;
int b, n, z, ot;
int main() {
	scanf("%d%d", &b, &n);
	scanf("%d", &z);
	for (int i = 2; i <= n; i++) {
		int x;scanf("%d", &x);
		ot += x;
	}
	if (b > z) printf("%lf", (double)z/b);
	else printf("%lf", (b - 1 + (z - b + 1.0)/(ot + z - b + 1))/b);
}
