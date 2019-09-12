#include <cstdio>
#include <cstring>
const int N = 100;
int n, a[N][N];
bool b[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++, putchar('\n')) {
		for (int j = 1; j <= n; j++) {
			memset(b, 0, sizeof b);
			for (int k = 1; k < i; k++) b[a[k][j]] = 1;
			for (int k = 1; k < j; k++) b[a[i][k]] = 1;
			for (int k = 1; k < N; k++) if (!b[k]) {
				a[i][j] = k;
				break;
			}
			printf("%2d ", a[i][j]);
		}
	}
}
