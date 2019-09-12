#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7, S = 1e5 + 10, D = 11;
int d, m, f[S][D];
ll s;
int main() {
	cin >> s >> m >> d;
	for (int i = 1; i <= m; i++) f[i][i] = 1;
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= m; j++) if (j <= i) {
			for (int k = max(j - d, 1); k <= min(j + d, m); k++) {
				f[i][j] = (f[i - j][k] + f[i][j])%MOD;
			}
		}
		for (int j = 1; j <= m; j++) printf("%d ", f[i][j]);
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) ans = (ans + f[s][i])%MOD;
	cout << ans;
}
