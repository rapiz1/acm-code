#include <cstdio>
const int N = 1e6 + 10;
int n, f[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j+=i) f[j]++;
		f[i] += f[i - 1];
	}
	printf("%d\n", f[n]);
}
