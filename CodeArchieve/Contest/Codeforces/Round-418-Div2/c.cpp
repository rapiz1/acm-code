#include <cstdio>
#include <algorithm>
const int N = 1510, C = 26;
int n, b[N][C], ans[N][C];
char a[N];
int main() {
	scanf("%d", &n);
	scanf("%s", a + 1);
	for (int i = 1; i <= n; i++) {
		b[i][a[i] - 'a']++;
		for (int j = 0; j < C; j++) b[i][j] += b[i - 1][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 0; k < C; k++) {
				int m = b[i][k] - b[j - 1][k];
				m = i - j + 1 - m;
				ans[m][k] = std::max(ans[m][k], i - j + 1);
			}
		}
	}
	for (int k = 0; k < C; k++) {
		for (int i = 1; i <= n; i++) ans[i][k] = std::max(ans[i - 1][k], ans[i][k]);
	}
	int q;
	scanf("%d",&q);
	while (q--) {
		int x;
		scanf("%d%s", &x, a);
		printf("%d\n", ans[x][a[0] - 'a']);
	}
}
