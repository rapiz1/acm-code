#include <cstdio>
#include <algorithm>
const int N = 110;
int n, a[N], w, b[N], c[N];
int cmp(int i, int j) {return a[i] > a[j];}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), w -= (a[i] + 1)/2, c[i] = (a[i] + 1)/2;
	if (w < 0) {
		puts("-1");
	}
	else {
		for (int i = 1; i <= n; i++) b[i] = i;
		std::sort(b + 1, b + 1 + n, cmp);
		for (int i = 1; i <= n && w > 0; i++) {
			int k = b[i], t = std::min(a[k] - c[k], w);
			w -= t;
			c[k] += t;
		}
		for (int i = 1; i <= n; i++) printf("%d ", c[i]);
	}
}
