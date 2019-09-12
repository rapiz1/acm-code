#include <cstdio>
#include <cstring>
const int N = 1010, M = 2009;
int n, t, r[N][N], f[N][N], tot;
char buf[30];
void mul(int a[N][N], int b[N][N]) {
	static int c[N][N];
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= tot; i++) for (int j = 1; j <= tot; j++) for (int k=1; k<=tot; k++)
		c[i][k] = (c[i][k] + a[i][j]*b[j][k])%M;
	memcpy(a, c, sizeof(c));
}
int main(){
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &t);
	tot = n*9;
	for (int i = 1; i <= n; i++) {
		scanf("%s", buf + 1);
		for (int j = 1; j <= n; j++) {
			int l = buf[j] - '0';
			f[i + (l - 1)*n][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) for (int l = 1; l < 9; l++) f[i + (l-1)*n][i + l*n] = 1;
	for (int i = 1; i <= tot; i++) r[i][i] = 1;
	while (t) {
		if (t&1) mul(r, f);
		t>>=1, mul(f, f);
	}
	printf("%d\n", r[1][n]);
}
