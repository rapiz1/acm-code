#include <cstdio>
#include <cstring>
const int N = 9;
int f[N][2], a[N], sz;
int dfs(int n, int prev, int lim) {
	if (n <= 0) return 1;
	if (!lim && f[n][prev] != -1) return f[n][prev];
	int end = lim ? a[n] : 9, ret = 0;
	for (int i = 0; i <= end; i++) {
		if (i == 4) continue;
		if (prev && i == 2)  continue;
		ret += dfs(n - 1, i == 6, lim && i == end);
	}
	if (!lim) f[n][prev] = ret;
	return ret;
}
int calc(int x) {
	if (!x) return 1;
	memset(f, -1, sizeof f);
	while (sz) a[sz--] = 0;
	for (int i = x; i; i/=10) a[++sz] = i%10;
	return dfs(sz + 1, 0, 1);
}
int main() {
//	freopen("input", "r", stdin);
	while (1) {
		int n, m;
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
	 	printf("%d\n", calc(m) - calc(n - 1));
	}
}
