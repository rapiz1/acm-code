#include <cstdio>
#include <algorithm>
const int MOD = 1e9 + 7, N = 3e5 + 10;
typedef long long ll;
int n, x[N], ans, p2[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	p2[0] = 1;
	for (int i = 1; i <= n; i++) p2[i] = p2[i - 1]*2%MOD;
	for (int i = 1; i <= n; i++) scanf("%d", x + i);
	std::sort(x + 1, x + 1 + n);
	for (int i = 1; i <= n; i++) {
		ans = (ans + (p2[i - 1] - 1ll)*x[i]%MOD)%MOD;
	}
	std::reverse(x + 1, x + 1 + n);
	for (int i = 1; i <= n; i++) {
		ans = (ans - (p2[i - 1] - 1ll)*x[i]%MOD + MOD)%MOD;
	}
	printf("%d\n", ans);
}
