#include <cstdio>
#include <algorithm>
#include <bitset>
const int N = 1e5 + 10;
typedef  long long ll;
int n, a[N], m;
ll f[N];
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), f[i] = 1e18;
	f[1]=0;
	for (int i = 2; i <= n; i++) for (int j = i-1; j >= 1 && a[i] - a[j] <= 30; j--)
		f[i]= std::min(f[i], f[j] + m + (1ll<<a[i] - a[j]));
	printf("%lld\n", f[n]);
}
int main() {
//	freopen("input", "r", stdin);
	int t ;scanf("%d", &t);
	while (t--) solve();
}
