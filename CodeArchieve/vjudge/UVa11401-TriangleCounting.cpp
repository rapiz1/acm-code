#include <cstdio>
const int N = 1e6 + 10;
typedef long long ll;
long long f[N];
int main() {
	for (int i = 3; i < N; i++) {
		ll num = i - i/2 - 1;
		f[i] += num*(i/2 + 1 + i - 1) - num*(i + 1); // x > y > z
//		printf("%d : %lld\n", i, f[i]);
		f[i] += f[i - 1];
	}
	for (int n; scanf("%d", &n), n >= 3;) printf("%lld\n", f[n]);
}
