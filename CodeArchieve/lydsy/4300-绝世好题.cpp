#include <cstdio>
#include <algorithm>
using std::max;
const int N = 1e5 + 10;
int n, g[35];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, k = 0;
		scanf("%d", &x);
		for (int y = x, j = 0; y; y>>=1, j++) if (y&1) k = max(g[j] + 1, k);
		for (int y = x, j = 0; y; y>>=1, j++) if (y&1) g[j] = max(g[j], k);
	}
	int k = 0;
	for (int i = 0; i < 33; i++) k = max(k, g[i]);
	printf("%d", k);
}
