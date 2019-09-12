#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
const int N = 1e6 + 10;
typedef long long ll;
int n;
ll s[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		s[i] = s[i-1]+x;
	}
	ll t = s[n]/n;
	for (int i = 1; i <= n; i++) s[i] = i*t - s[i];
	std::sort(s + 1, s + 1 + n);
	ll ans = 0;
	for (int i = 1; i <=n; i++) ans += abs(s[(n+1)/2] - s[i]);
	printf("%lld\n", ans);
}
