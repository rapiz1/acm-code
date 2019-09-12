#include <cstdio>
#include <cstring>
const int N = 310, M = 1e9;
int n, f[N][N];
char s[N];
int main() {
	while(scanf("%s", s + 1) == 1) {
		memset(f, 0, sizeof f);
		n = strlen(s + 1);
		for (int i = 1; i <= n; i++) f[i][i] = 1; 
		for (int l = 2; l <= n; l++)
			for (int i = 1; i <= n; i++) {
				int j = i + l - 1;
				if (j <= n && s[i] == s[j])
				for (int k = i + 1; k < j; k++) if (s[i] == s[k - 1] && s[k] == s[j - 1])
					f[i][j] = (f[i][j] + f[i][k - 1]*1ll*f[k][j - 1])%M;
	//			printf("f[%d][%d]:%d\n", i, j, f[i][j]);
			}
		printf("%d\n", f[1][n]);
	}
}
