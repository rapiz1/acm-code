#include <cstdio>
int n;
double ans;
int main() {
	scanf("%d", &n);
	ans = 1;
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), ans *= x;
	ans /= 256;
	printf("%d\n", int(ans + 1e-8));
}
