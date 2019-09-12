#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 100010, K = 16;
int n, k, f[1 << K], s[N], c[K];
ll ans;
int find(int d, int tar) {
	int l = d, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (s[mid] - s[d] <= tar) l = mid;
		else r = mid - 1;
	}
	return l;
}
int main() {
	freopen("nochange.in", "r", stdin);
	freopen("nochange.out", "w", stdout);
	scanf("%d%d", &k, &n);
	for (int i = 0; i < k; i++) scanf("%d", c + i), ans += c[i];
	for (int i = 1; i <= n; i++) scanf("%d", s + i), s[i] += s[i - 1];
	for (int i = 0; i < 1 << k; i++) {
		ll na = 0;
		for (int j = 0; j < k; j++) if (i>>j&1) {
			na += c[j];
			int pos = find(f[i^(1<<j)], c[j]);
			f[i] = std::max(f[i], pos);
		}
		if (f[i] == n) ans = std::min(ans, na);
	}
	ll sum = 0;
	for (int i = 0; i < k; i++) sum += c[i];
	printf("%lld\n", sum >= s[n] ? sum - ans : -1);
}
