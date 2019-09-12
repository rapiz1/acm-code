#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
const int N = 1e3 + 10, M = 2e3 + 10;
int n, m, ans;
char s[N];
std::bitset<N> bits[M];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i<= m; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= n; j++) bits[i][j] = s[j] == '1';
		int d;scanf("%d", &d);
		bits[i][n + 1] = d;
	}
	for (int i = 1; i <= n; i++) {
		int r = i;
		for (;r <= m && !bits[r][i]; r++);
		if (r > m) {
			puts("Cannot Determine");
			return 0;
		}
		ans = std::max(ans, r);
		std::swap(bits[i], bits[r]);
		for (int j = 1; j <= m; j++) if (i != j && bits[j][i]) bits[j] ^= bits[i];
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) puts(bool(bits[i][n + 1]) ? "?y7M#" : "Earth");
}
