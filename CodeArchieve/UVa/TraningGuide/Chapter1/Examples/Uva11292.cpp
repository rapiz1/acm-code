#include <cstdio>
#include <algorithm>
using std::sort;
const int N =2e4 + 10;
int n, m, a[N], b[N];
int main() {
	while (scanf("%d%d", &n, &m) && n && m) {
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
		std::sort(a + 1, a + 1 + n);
		std::sort(b + 1, b + 1 + m);	
		int i, j, r = 0;
		for (i = j = 1; i <= n && j <= m; ++i, ++j) {
			while (j + 1 <= m && a[i] > b[j]) ++j;
			if (a[i] <= b[j]) r += b[j];
			else --i;
		}
		if (i <= n) puts("Loowater is doomed!");
		else printf("%d\n", r);
	}
}
