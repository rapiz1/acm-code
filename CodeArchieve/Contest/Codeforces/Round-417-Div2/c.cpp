#include <cstdio>
#include <algorithm>
const int N = 1e5 + 10, S = 1e9 + 10;
typedef long long ll;
int n, s, a[N];
ll b[N];
ll calc(int k) {
	ll s = 0;
	for (int i = 1; i <= n; i++) b[i] = a[i] + (ll)i*k;
	std::sort(b + 1, b + 1 + n);
	for (int i = 1; i <= k; i++) s += b[i];
	return s;
}
int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1)/2;
		if (calc(mid) <= s) l = mid;
		else r = mid - 1;
	}
	printf("%d %d\n", l, (int)calc(l));
}
