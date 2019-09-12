#include <cstdio>
#include <algorithm>
const int N = 2e5 + 10;
typedef long long ll;
typedef std::pair<ll, int> pa;
int n, a[N], k;
ll f[N], g[N], ans;
void solve(int l, int r) {
	if (l == r) {
		ans += a[l] >= 0;
		return;
	}
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);
	f[mid] = -a[mid];
	for (int i = mid - 1; i >= l; i--) f[i] = f[i + 1] - a[i];
	std::sort(f + l, f + mid + 1);
	g[mid] = 0;
	for (int i = mid + 1; i <= r; i++) {
		g[i] = g[i - 1] + a[i];
		ans += std::upper_bound(f + l, f + mid + 1, g[i]) - (f + l);
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), a[i] -= k;
	solve(1, n);
	printf("%lld\n", ans);
}
