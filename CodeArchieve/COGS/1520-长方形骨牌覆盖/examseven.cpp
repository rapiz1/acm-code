//抄的萌帝代码
#include <cstdio>
#include <cstring>
#define file(x) "examseven." #x
typedef long long ll;
int n, m, r, l = 1, po[11]={1};
ll f[2][int(1e7)];
void dfs(int l, int c, int s0, int s1) {
	if (c >= m) {
		if (c == m) f[l][s1] += f[l^1][s0];
		return;
	} 
	for (int i = 0; i < r - 1; i++) dfs(l, c + 1, s0*r + i, s1*r + (i + 1)%r);//枚举状态
	dfs(l, c + 1, s0*r + r - 1, s1*r);
	dfs(l, c + r, s0*po[r] + po[r] - 1, s1*po[r] + po[r] -1);
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d%d", &r, &n, &m);
	for (int i = 1; i <= m; i++) po[i] = po[i-1]*r;	
	f[0][po[m] - 1] = 1;
	for (int k = 1; k <= n; k++)
		dfs(k&1, 0, 0, 0), 
		memset(f[(k&1)^1], 0, sizeof(f[0]));
	printf("%lld\n", f[n&1][po[m] - 1]);
}
