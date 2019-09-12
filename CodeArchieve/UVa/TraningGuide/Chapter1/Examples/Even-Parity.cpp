#include <cstdio>
#include <algorithm>
using std::min;
const int N = 16;
int n, a[N][N], b[N][N];
bool inline in(int x) {return x <= n && x >= 1;}
int main() {
//	freopen("input", "r", stdin);
	int T;scanf("%d", &T);
	for (int ks = 1; ks <= T; ks++) {
		scanf("%d", &n);
		int r = n*n + 1;
		for (int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
		for (int i = 0; i < 1 << n; i++) {
			for (int j = 0; j < n; j++) b[1][j + 1] = (i >> j)&1;
			for (int k = 1; k < n; k++) {
				for (int j = 1; j <= n; j++) {
					int s = 0;
					if (k > 1) s ^= b[k - 1][j];
					if (j > 1) s ^= b[k][j - 1];
					if (j + 1 <= n) s ^= b[k][j + 1];
					b[k + 1][j] = s;
				}
			}
			bool f = 1;
			int t = 0;
			for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
				t += a[i][j] != b[i][j];
				if (a[i][j] == 1 && b[i][j] == 0) f = 0;
			}
			if (!f) continue;
			for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
				int s = 0;
				for (int xx = -1; xx <= 1; xx += 2) for (int yy = -1; yy <= 1; yy += 2)
				 	if (xx*yy == 0 && xx + yy != 0 && in(i + xx) && in(j + yy)) s ^= b[i + xx][j + yy];
				if (s) f = 0;
			}
			if (!f) continue;
			r = min(t, r);
		}
		if (r == n*n + 1) r = -1;
		printf("Case %d: %d\n", ks, r);
	}
}
