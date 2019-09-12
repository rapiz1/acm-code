#include <cstdio>
#include <cstring>
#include <vector>
const int N = 1e5 + 10, M = 1e9 + 9, U = 1000;
int f[2][1000], pos[1000], n;
bool pri[1000];
std::vector<int> pp;
int main() {
	freopen("threeprime.in", "r", stdin);
	freopen("threeprime.out", "w", stdout);
	memset(pos, -1, sizeof pos);
	memset(pri, 1, sizeof pri);
	scanf("%d", &n);
	if (n < 3) {
		puts("0");
		return 0;
	}
	for (int i = 2; i < U; i++) if (pri[i])
		for (int j = i + i; j < U; j += i) pri[j] = 0;
	for (int i = 100; i < U; i++) if (pri[i]) pp.push_back(i), f[3&1][pos[i] = pp.size() - 1] = 1;
	for (int i = 4; i <= n; i++) {
		int k = i&1;
		for (int j = 0; j < (int)pp.size(); j++) {
			f[k][j] = 0;
			int a = pp[j]/10%10, b = pp[j]%10;
			for (int c = 0, x; c < 10; c++) if (pos[x = a*100 + b*10 + c] != -1)
				f[k][j] = (f[k][j] + f[k^1][pos[x]])%M;
		}
	}
	int ans = 0;
	for (int j = 0; j < (int)pp.size(); j++) ans = (ans + f[n&1][j])%M;
	printf("%d\n", ans);
}
