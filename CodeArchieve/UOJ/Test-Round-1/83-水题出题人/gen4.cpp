#include <cstdio>
#include <cstdlib>
#include <vector>
const int L = 1e9, N = 3e4 + 10;
int a[N], n, k;
int main(int argc, char** argv) {
	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &k);
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) printf("%d ", (n - i)/k);
}
