#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 5e3 + 10;
typedef long long ll;
int n, m;
ll f[N], a[N], g[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), a[i] = a[i - 1] + x;
	if (m >= n) {
		printf("%lld\n", a[n]);
		return 0;
	}
	memset(g, 0xc0, sizeof g);
	memset(f, 0xc0, sizeof f);
	g[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[0] = 0;
		for (int j = 1; j <= std::min(m, i); j++) {
			f[j] = std::max(g[j - 1] + a[i], f[j]);
		}
		for (int j = 0; j <= std::min(m, i); j++) g[j] = std::max(g[j], f[j] - a[i]);
	}
	printf("%lld\n", f[m]);
}
