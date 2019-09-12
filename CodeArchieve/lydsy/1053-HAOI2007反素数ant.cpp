#include <cstdio>
const int K = 11, p[K]={2,3,5,7,11,13,17,19,23,29,31};
int n, ans, fac;
void dfs(int pos, int lim, int now, int cnt) {
	if (pos >= K) {
		if (cnt > fac) ans = now, fac = cnt;
		else if (cnt == fac) ans = ans < now ? ans : now;
		return;
	}
	int po = 1;
	for (int i = 0; i <= lim; i++) {
		if ((double)now*po <= n) dfs(pos+1, i, now*po, cnt*(i+1));
		else break;
		if ((double)po*p[pos] > n) break;
		po *= p[pos];
	}
}
int main() {
	scanf("%d", &n);
	dfs(0, 31, 1, 1); 
	printf("%d\n", ans);
}
