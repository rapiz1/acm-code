#include <cstdio>
const int N = 12;
typedef long long ll;
int n, k, tot, va[1000], cnt[1000];
ll f[N][N*N][1000];
void dfs(int p, int s, int cc) {
	if (p > n) {
		va[++tot] = s;
		cnt[tot] = cc;
		return;
	}
	dfs(p + 1, s, cc);
	dfs(p + 2, s|(1<<p - 1), cc + 1);
}
void pt(int x) {
	for (int i = 1; i <= n; i++) printf("%d", x>>i&1);
}
int main() {
	//freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	dfs(1, 0, 0);
	f[0][0][1] = 1;
	for (int i = 1; i <= n + 1; i++) for (int j = 0; j <= k; j++)
		for (int p = 1; p <= tot; p++) if (cnt[p] <= j) for (int q = 1; q <= tot; q++) {
			if (!(va[p]&va[q]) && !(va[p]>>1&va[q]) && !(va[p]<<1&va[q]))
			 	f[i][j][p] += f[i - 1][j - cnt[p]][q];
		}
	printf("%lld\n", f[n + 1][k][1]);
}
