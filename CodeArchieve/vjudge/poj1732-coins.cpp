#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 410, M = 41000;
int n, m, f[2][M], q[N], h, t, a[N], c[N];
int main() {
//	freopen("input", "r", stdin);
	while (scanf("%d%d", &n, &m), n && m ) {
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) scanf("%d", c + i);
		for (int i = 1; i <= n; i++) std::swap(a[i], c[i]);//forgive me....
		for (int i = 1; i <= n; i++) {
			int a, c;
			a = ::a[i], c = ::c[i];
			for (int j = 0; j < c; j++) {
				q[h = t = 0] = 0;
				for (int k = 0; c*k + j <= m; k++) {
					while (h < t && f[(i&1)^1][c*q[t - 1] + j] < f[(i&1)^1][c*k + j]) t--;
					q[t++] = k;
					while (h < t && k - q[h] > a) h++;
					if (h < t) f[i&1][c*k + j] |= f[(i&1)^1][c*q[h] + j];
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= m; i++) cnt += f[n&1][i];
		printf("%d\n", cnt);
	}
}
