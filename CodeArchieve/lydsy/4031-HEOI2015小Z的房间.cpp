#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
typedef long long ll;
const ll M = 1e9;
const int N = 110;
int n, m, du[N][N], num[11][11], cnt;
ll a[N][N];
char mm[11][11];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", mm[i] + 1);
	for (int i = 1; i<= n; i++) for (int j = 1; j <= m; j++) if (mm[i][j] == '.') num[i][j] = ++cnt;
	for (int i = 1, x, y; i <= n; i++) for (int j = 1; j <= m; j++) if (num[i][j]) {
		for (int dx = 0; dx <= 1; dx++) for (int dy = 0; dy <= 1; dy++) if (dx + dy && dx*dy == 0)
			if (1 <= i + dx && i + dx <= n && 1 <= j + dy &&  j + dy <= m && num[x = i + dx][y = j + dy]) {
				int u = num[i][j], v = num[x][y];
				du[u][u]++, du[v][v]++, du[u][v]--,du[v][u]--;
			}
	}
	n = cnt - 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = (M + du[i][j])%M;
	bool mk = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			while (a[j][i]) {
				ll tmp = a[i][i]/a[j][i];
				for (int k = 1; k <= n; k++) a[i][k] = (a[i][k] - tmp*a[j][k]%M + M)%M;
				for (int k = 1; k <= n; k++) std::swap(a[j][k], a[i][k]);
				mk^=1;
			}
		}
	}
	ll ans = 1;
	for (int i = 1; i <= n; i++) ans = (ans*a[i][i])%M;
	if (mk) ans = (M - ans)%M;// 'mod' has meaning when ans = 0
	printf("%lld", ans);
}
