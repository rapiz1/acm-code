#include <cstdio>
#include <cmath>
int ks, n;
int main() {
	while (scanf("%d", &n) && n >= 0) {
		printf("Case %d: %d\n", ++ks, n ? (int)ceil(log2(n)) : 0);
	}
}
