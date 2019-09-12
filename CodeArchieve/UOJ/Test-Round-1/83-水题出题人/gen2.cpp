#include <cstdio>
int n = 1990;
int main() {
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) printf("%d ", i == n - 521);
}
