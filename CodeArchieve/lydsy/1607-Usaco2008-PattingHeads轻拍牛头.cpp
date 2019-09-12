#include <cstdio>
const int N = 1e6 + 10;
int n, f[N], a[N], in[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), in[a[i]]++;
	for (int i = 1; i < N; i++) if (in[i])
		for (int j = i; j < N; j += i) f[j] += in[i];
	for (int i = 1; i <= n; i++) printf("%d\n", f[a[i]] - 1); 
}
