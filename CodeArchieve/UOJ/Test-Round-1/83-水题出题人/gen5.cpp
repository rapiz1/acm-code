#include <cstdio>
int n = 1000;
void go(int n) {
	for (int i = 1; i <= n; i++) printf("%d ", n - i);
}
int main() {
	printf("%d\n", n);
	go(n);
	return 0;
	int k = 5;
	for (int i = 1; i <= k; i++) {
		go(n/k);
	}
}
