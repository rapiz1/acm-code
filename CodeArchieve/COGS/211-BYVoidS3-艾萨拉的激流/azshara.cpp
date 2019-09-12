#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
#define file(x) "azshara."#x
const int W = 1010, L = 10000;
typedef long long ll;
int n, m, a[L][W];
int f[L][W], ans;
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	memset(f, 0xc0 ,sizeof(f));
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	for (int i = 1; i <= m; i++) f[1][i] = a[1][i];
	for (int i = 2; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] != -1)
		f[i][j] = max(f[i][j], max(f[i - 1][j], max(f[i - 1][j - 1], f[i - 1][j + 1])) + a[i][j]);
	for (int i = 1; i <= m; i++) ans = max(ans, f[n][i]);
	printf("%d", ans);
}
