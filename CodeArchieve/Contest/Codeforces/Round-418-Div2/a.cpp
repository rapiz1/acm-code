#include <cstdio>
#include <algorithm>
const int N = 110;
int n, m, a[N], b[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d",&n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= m; i++) scanf("%d", b + i);
	std::sort(b +1, b + 1 + m);
	for (int i = 1, j = m; i <= n; i++) if (a[i] == 0) a[i] = b[j--];
	for (int i = 1; i < n; i++) if (a[i] <= a[i + 1]) ;
	else {
		puts("Yes");
		return 0;
	}
	puts("No");
}
