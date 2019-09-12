#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = 25;
const ll M = 45989;
ll f[N][N], r[N][N], p[N][N];
int n, m, t, a, b;
int main() {
	scanf("%d%d%d%d%d", &n, &m, &t, &a, &b);
	a++, b++;
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		u++, v++;
		f[u][v]++;
		f[v][u]++;
	}
	memcpy(r, f, sizeof(r));
	while (t--) {
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++)
		 		for (int k = 1; k <= n; k++) 
					p[i][j] = (p[i][j] + f[i][k]*r[k][j])%M;
		memcpy(f, p, sizeof(p));
	}
	printf("%lld", f[a][b]);
}
