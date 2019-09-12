#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 2010;
int n, f[N];
char a[N], s[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) a[2*i] = s[i];
	n = 2*n + 1;
	for (int i = 1; i <= n; i++) if (!a[i]) a[i] = '#';
	a[0] = '$';
	int ans = 0;
	for (int i = 1, mx = 0, id = 0; i <= n; i++) {
		if (i <= mx) f[i] = std::min(mx - i, f[2*id - i]);
		else f[i] = 1;
		for(;a[i + f[i]] == a[i - f[i]]; f[i]++);
		ans = std::max(ans, f[i]);
	}
	printf("%d\n", ans - 1);
}
