#include <cstdio>
#include <algorithm>
#include <cstring>
#define file(x) "relays." #x
const int N = 210;
int n, m, a, b, f[N][N], t[N][N], l, li[1010];
void mul(int a[N][N], int b[N][N]) {
	static int c[N][N];
	memset(c, 0x3f, sizeof(c));
	for (int i = 1; i <= l; i++) for (int j = 1; j <= l; j++) for (int k = 1; k <= l; k++)
		c[i][j] = std::min(c[i][j], a[i][k] + b[k][j]);
	for (int i = 1; i <= l; i++) for (int j = 1; j <= l; j++) a[i][j] = c[i][j];
}
inline void lisan(int& x) {
	if (!li[x]) li[x] = ++l;
	x = li[x];
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d%d%d", &n, &m, &a, &b);
	lisan(a), lisan(b);
	memset(f, 0x3f, sizeof(f));
	while (m--) {
		int u, v, w;scanf("%d%d%d", &w, &u, &v);
		lisan(u), lisan(v);
		f[v][u] = f[u][v] = std::min(f[u][v], w);
	}
	memset(t, 0x3f, sizeof(t));
	for (int i = 1; i <= l; i++) t[i][i] = 0;
	while (n) {
		if (n&1) mul(t, f);
		n >>= 1, mul(f, f);
	}
	printf("%d\n", t[a][b]);
}
