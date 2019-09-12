#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
const int N = 1e3 + 10, S = 1e4 + 10, MOD = 1000000007;
int n, k, f[N][S], a[N], b[N], m;
std::vector<int> fac;
void solve() {
	fac.clear();
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; (double)i*i <= k; i++) 
		if (k%i == 0) fac.push_back(i), fac.push_back(k/i);
	std::sort(fac.begin(), fac.end());
	fac.resize(std::unique(fac.begin(), fac.end()) - fac.begin());
	m = 0;
	for (int i = 1; i <= n; i++) if (std::binary_search(fac.begin(), fac.end(), a[i]))
		b[++m] = a[i];
	memset(f, 0, sizeof f);
	f[0][0] = 1;
	for (int i = 0; i < m; i++) for (int j = 0; j < (int)fac.size(); j++) if (f[i][j]) {
		(f[i + 1][j] += f[i][j])%=MOD;
		if ((double)b[i + 1]*fac[j] <= k) {
			int t = std::lower_bound(fac.begin(), fac.end(), b[i + 1]*fac[j]) - fac.begin();
			if (t == (int)fac.size() || fac[t] != b[i + 1]*fac[j]) continue;
			else (f[i + 1][t] += f[i][j])%=MOD;
		}	
	}
	printf("%d\n", f[m][(int)fac.size() - 1]);
}
int main() {
//	freopen("input", "r", stdin);
	int t; scanf("%d", &t);
	while (t--) solve();
}
