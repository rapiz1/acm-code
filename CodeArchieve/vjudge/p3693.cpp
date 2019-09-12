#include <cstdio>
#include <algorithm>
const int N = 1e5 + 10, K = 21;
int n, m, a[N][K], cnt[K], f[1 << K];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		x--;
		a[i][x]++;
		cnt[x]++;
	}
	for (int i = 1; i <= n; i++) for (int j = 0; j < m; j++) a[i][j] += a[i - 1][j];
	for (int i = 1; i <= n; i++) for (int j = 0; j < m; j++) a[i][j] = i - a[i][j];
	f[0] = 0;
	for (int s = 1; s < 1 << m; s++) {
		f[s] = n;
		int tot = 0;
		for (int i = 0; i < m; i++) if (s>>i&1) tot += cnt[i];
		for (int i = 0; i < m; i++) if (s>>i&1) {
			f[s] = std::min(f[s], f[s&~(1<<i)] + a[tot][i] - a[tot - cnt[i]][i]);
		}
	} 
	printf("%d\n", f[(1 << m) - 1]);
}
