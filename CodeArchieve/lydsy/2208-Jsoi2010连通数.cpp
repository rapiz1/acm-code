#include <cstdio>
#include <bitset>
const int N = 2010;
int n, ans;
std::bitset<N> f[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1, x; j <= n; j++) scanf("%1d", &x), f[i][j] = x;
	for (int i = 1; i <= n; i++) f[i][i] = 1;
	for (int i = 1; i <= n; i++) //update adjacent matrix from i th point
		for (int j = 1; j <= n; j++) 
			if (f[j][i]) f[j] |= f[i];
	for (int i = 1; i <= n; i++) ans += f[i].count();
	printf("%d\n", ans);
}
