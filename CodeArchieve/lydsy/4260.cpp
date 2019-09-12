#include <cstdio>
#include <algorithm>
const int N = 4e5 + 10, S = N*40;
int n, a[N], top, ch[S][2], xs[2][N], ans;
int find(int x) {
	int ret = 0;
	for (int i = 31, p = 0; ~i; i--) {
		int t = (x>>i)&1;
		t ^= 1;
		if (ch[p][t]) {
			p = ch[p][t];
			ret |= 1 << i;
		}
		else p = ch[p][t^1];
	}
	return ret;
}
void insert(int x) {
	int p = 0;
	for (int i = 31; ~i; i--) {
		int t = (x>>i)&1;
		if (!ch[p][t]) ch[p][t] = ++top;
		p = ch[p][t];
	}
}
void work(int* g) {
	for (;~top;top--) ch[top][0] = ch[top][1] = 0;
	top=0;
	insert(0);
	for (int i = 1, x = 0; i <= n; i++) {
		x ^= a[i];
		g[i] = std::max(g[i - 1], find(x));
		insert(x);
	}
}
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	work(xs[0]);
	std::reverse(a + 1, a + 1 + n);
	work(xs[1]);
	for (int i = 1; i < n; i++)
		ans = std::max(ans, xs[0][i] + xs[1][n - i]);
	printf("%d\n", ans);
}
