#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 1e6 + 10;
using std::max;
typedef long long ll;
int n, k, c[N], prev[N];
ll v[N], f[N], g[N];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <=n ;i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &v[i]), v[i] += v[i-1];
	memset(g, 0xc0, sizeof g);
	for (int i = 1; i <= n; i++) {
		f[i] = max(f[i-1], v[i] + g[c[i]]);
		g[c[i]] = max(g[c[i]], f[i-1]-v[i-1]);
		prev[c[i]] = i;
	}
	printf("%lld\n", f[n]);
}
