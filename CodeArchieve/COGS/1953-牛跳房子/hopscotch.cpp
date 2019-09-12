#include <cstdio>
#define file(x) "hopscotch."#x
const int N = 800, M = 1000000007;
int sum[N*N], c[N][N], n, m, k, f[N][N];
void solve(int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1;
	solve(l, mid);
	for (int i = 1, ss = 0; i <= n; i++) {
		for (int j = mid + 1; j <= r; j++) f[i][j] = ((f[i][j] + ss)%M - sum[c[i][j]] + M)%M;
		for (int j = l; j <= mid; j++) ss = (ss + f[i][j])%M, sum[c[i][j]] = (sum[c[i][j]] + f[i][j])%M;
	}
	for (int i = 1; i <= n; i++) for (int j = l; j <= mid; j++) sum[c[i][j]] = 0;
	solve(mid + 1, r);
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &c[i][j]);
	f[1][1] = 1;
	solve(1, m);
	printf("%d\n", f[n][m]);
}
