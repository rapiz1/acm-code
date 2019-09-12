#include <cstdio>
const int N = 1e5 + 10;
typedef long long ll;
ll n, m, f[N], ans;
int main() {
	scanf("%lld%lld", &n, &m);
	ll w = n < m ? n : m;
	for (int i = w; i; i--) {
		f[i] = (n/i)*(m/i);
		for (int j = i + i; j <= w; j += i) f[i] -= f[j];
		ans += f[i]*i;
	}
	printf("%lld\n", ans*2 - n*m);
}
