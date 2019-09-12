#include <cstdio>
#include <algorithm>
#include <cstring>
using std::max;
const int N = 60;
int f[N][N][N][N], n, m;
char a[N], b[N];
void solve() {
	memset(f, 0, sizeof f);
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	int ans = 0;
	for (int l1 = n + 1; l1;l1--) {
		for (int r1 = 0; r1 <= n; r1++) { 
			for (int l2 = m + 1; l2; l2--) {
				for (int r2 = 0; r2 <= m; r2++) {
					int& x = f[l1][r1][l2][r2];
					if (l1 <= r1 || l2 <= r2) x = 1;
					if (l1 <= r1) {
						x = max(x, f[l1+1][r1][l2][r2]);
						if (r1) x = max(x, f[l1][r1-1][l2][r2]);
					}
					if (l2 <= r2) {
						x = max(x, f[l1][r1][l2+1][r2]);
						if(r2) x = max(x, f[l1][r1][l2][r2-1]);
					}
					if (r1 && l1 < r1 && a[l1] == a[r1]) x = max(x, f[l1 + 1][r1 - 1][l2][r2] + 2);
					if (r2 && l1 <= r1 && l2 <= r2 && a[l1] == b[r2]) x = max(x, f[l1+1][r1][l2][r2-1] + 2);
					if (r1 && l1 <= r1 && l2 <= r2 && a[r1] == b[l2]) x = max(x, f[l1][r1-1][l2+1][r2] + 2);
					if (r2 && l2 < r2 && b[l2] == b[r2]) x = max(x, f[l1][r1][l2+1][r2-1] + 2);
					ans = max(ans, x);
					printf("f[%d][%d][%d][%d]=%d\n", l1, r1, l2, r2, f[l1][r1][l2][r2]);
				}
			}
		}
	}
	printf("%d\n", ans);
}
int main() {
	freopen("input", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
