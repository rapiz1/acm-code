#include <cstdio>
#include <vector>
const int N = 1e5, MOD = 1e9 + 7, C = 3010;
int n, c[C][C], phi[N];
std::vector<int> pri;
int main() {
//	freopen("input", "r", stdin);
	for (int i = 0; i < C ;i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1])%MOD;
	}
//	pri.push_back(phi[1] = 1);
	phi[1] = 1;
	for (int i = 2; i < N; i++) if (!phi[i]) {
		pri.push_back(i);
		for (int j = i; j < N; j += i) {
			if (!phi[j]) phi[j] = j;
			phi[j] = phi[j]/i*(i - 1);
		}
	}
//	printf("%d\n", (int)pri.size());
	int q; scanf("%d", &q);
	while (q--) {
		int m, a, d, ans = 1;
		scanf("%d%d%d", &m, &a, &d);
		for (int i = 0; i < m; i++) {
			int s = c[i + a + d][d - 1];
			for (int j = 1, pp = phi[pri[i]]; j <= i + a + 1; j++) {
				s = (s + (long long)c[i + a + d - j][d - 1]*pp)%MOD;
				pp = (long long)pp*pri[i]%MOD;
			}
			ans = (long long)ans*s%MOD;
		}
		printf("%d\n", ans);
	}
}
