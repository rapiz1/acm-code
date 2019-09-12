#include <cstdio>
#include <cassert>
#include <cmath>
typedef long long ll;
ll n, m, ans;
int main() {
//	freopen("input", "r", stdin);
	scanf("%lld%lld", &n, &m);
	if (n == 1) {
		printf("%lld\n", (ll)sqrt(m));
		return 0;
	}
	/*
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		ll x = (ll)i*j, y = sqrt(x)+0.5;
		if (y*y == x) ans++;
	}
	*/
	for (int i = 1; i <= n; i++) {
		ll x = 1;
		for (int j = 2, y = i; j <= y; j++) if (y%j ==0) {
			int c = 0;
			while (y%j==0) y/=j, c++;
			if (c&1) x *= j;
		}
		int sy = sqrt(m/x) + 1e-8;
		ans += sy;
	}
	printf("%lld\n", ans);
}
