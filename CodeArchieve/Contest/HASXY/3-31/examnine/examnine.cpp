#include <cstdio>
#define file(x) "examnine."#x
const int N = 21;
typedef unsigned int uint;
int n, m, a[N][N];
uint f[1 << N | 1], ans;
int main() {
	freopen(file(in), "r", stdin);	
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i][0]);
		for (int j = 1; j <= a[i][0]; j++) scanf("%d", &a[i][j]), a[i][j]--;
	}
	f[0] = 1;
	for (int s = 0; s < 1 << m; s++) {
		int p = __builtin_popcount(s);
		for (int i = 1; i <= a[p][0]; i++) if (s&(1 << a[p][i]))
			f[s] += f[s&~(1 << a[p][i])];
		if (p == n) ans += f[s];
	}
	printf("%u", ans);
}
