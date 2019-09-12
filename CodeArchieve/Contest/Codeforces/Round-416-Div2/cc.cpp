#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
const int N = 5e3 + 10;
int n, a[N], f[N], be[N], ans, mx[N], mn[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	memset(mn, 0x3f, sizeof mn);
	for (int i = 1; i <= n; i++) 
		scanf("%d", a + i), mx[a[i]] = std::max(mx[a[i]], i),
			mn[a[i]] = std::min(mn[a[i]], i);
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		memset(be, 0, sizeof be);
		int l = i, r = i, now = a[i];
		be[a[i]] = 1;
		for (int j = i; j; j--) {
			l = std::min(l, mn[a[j]]);
			r = std::max(r, mx[a[j]]);
			if (!be[a[j]]) {
				be[a[j]] = 1;
				now ^= a[j];
			}
			if (l >= j && r <= i) f[i] = std::max(f[i], f[j - 1] + now);
		}
	}
	printf("%d\n", f[n]);
}
