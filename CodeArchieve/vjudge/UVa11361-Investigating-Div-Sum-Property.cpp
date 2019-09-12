#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 11, K = 110;
typedef long long ll;
int f[N][K][K], num[N];
ll po[12];
char s[N];
int dfs(int p, int k1, int k2, int k) {
	if (!p) return k1 == 0 && k2 == 0;
	int ans = 0;
	for (int i = 0; i < num[p]; i++) 
		ans += f[p - 1][(k1 - i%k + k)%k][(k2 - i*po[p -  1]%k + k)%k];
	ans += dfs(p - 1, (k1 - num[p]%k + k)%k, (k2 - num[p]*po[p - 1]%k + k)%k, k);
	return ans;
}
int solve(int x, int p) {
	memset(f, 0, sizeof f);
	memset(num, 0, sizeof num);
	for (int i = 1, j = x; i <= 10 && j; i++, j/=10) num[i] = j%10;
	f[0][0][0] = 1;
	for (int i = 1; i <= 10; i++)
		for (int j = 0; j < p; j++)
			for (int k = 0; k < p; k++) {
				for (int n = 0; n <= 9; n++)
					f[i][j][k] += f[i - 1][(j - n%p + p)%p][(k - (po[i - 1]*n)%p + p)%p];
			}
	return dfs(10, 0, 0, p);
}
int main() {
//	freopen("input", "r", stdin);
	po[0] = 1;
	for (int i = 1; i <= 10; i++) po[i] = po[i - 1]*10;
	int T;scanf("%d", &T);
	for (int l, r, k;scanf("%d%d%d", &l, &r, &k), T--;) {
		if (k >= 100) {
			puts("0");
			continue;
		}
		printf("%d\n", solve(r, k) - solve(l - 1, k));
	}
}
