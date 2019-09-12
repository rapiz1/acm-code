#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
const int N = 1e5 + 1;
int a[N][5], rec[1 << 5], n, k, ans;
void dfs(int p, int d, int s) {
	if (d == k) ans = max(ans, s);
	else for (int i = p; i; i = (i-1)&p)
		dfs(p^i, d + 1, s + rec[i]);
}
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(rec, 0, sizeof(rec));
		ans = 0;
		scanf("%d%d",&n, &k);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 5; j++) scanf("%d", &a[i][j]);
			for (int c = 0, s = 0; c < 1 << 5; rec[c] = max(rec[c], s), s = 0, c++)
			 	for (int x = 0; x < 5; x++) s += ((c&(1 << x)) ? 1 : 0)*a[i][x]; 
		}
		dfs(31, 0, 0);
		printf("%d\n", ans);
	} 
}
