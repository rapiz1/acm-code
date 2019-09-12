#include <cstdio>
#include <cstring>
const int N = 11, K = 13;
int a[N], sz, f[N][K][2][2], ten[N];
int dfs(int n, int rem, int prev, int con, int lim) {
	if (n <= 0) return con == 1 && rem == 0;
	if (!lim && f[n][rem][prev][con] != -1) return f[n][rem][prev][con];
	int ret = 0, end = lim ? a[n] : 9;
	for (int i = 0; i <= end; i++) {
		ret += dfs(n - 1, (rem + i*ten[n])%K, i == 1, con || (prev && i == 3) , lim && i == end);
	}
	if (!lim) f[n][rem][prev][con] = ret;
	return ret;
}
int solve(int x) {
	a[sz + 1] = 0;
	while (sz) a[sz--] = 0;
	memset(f, -1, sizeof f);
	for(;x;x/=10) a[++sz] = x%10;
	return dfs(sz + 1, 0, 0, 0, 1);
}
int main() {
//	freopen("input", "r", stdin);
	ten[0] = 1;
	for (int i = 1; i < N; i++) ten[i] = ten[i - 1]*10%K;
	for (int n; ~scanf("%d", &n);) printf("%d\n", solve(n));
}
