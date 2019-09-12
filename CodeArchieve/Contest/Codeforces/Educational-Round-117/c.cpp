#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1e5 + 10;
char a[N], b[N];
int n, m, f1[N], f2[N], ans, as, ae;
int main() {
//	freopen("input", "r", stdin);
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);
	ans = 0;
	memset(f1, 0x3f, sizeof(f1));
	for (int i = 1, j = 1; i <= m; i++, j++) {
		while (j <= n && a[j] != b[i]) j++;
		if (j <= n && a[j] == b[i]) {
			f1[i] = j;
			if (ans < i) as = i + 1, ae = m, ans = i;
		}
		else break;
	}
	for (int i = m, j = n; i >= 1; i--, j--) {
		while (j >= 1 && a[j] != b[i]) j--;
		if (j >= 1 && a[j] == b[i]) {
			f2[i] = j;
			if (ans < m - i + 1) as = 1, ae = i - 1, ans = m - i + 1;
		}
		else break;
	}
	for (int i = 1, j = 1; i <= m; i++) {
		while (j <= m && f1[i] >= f2[j]) j++;
		if (j > m) break;
		if (ans < m - (j - i - 1)) as = i + 1, ae = j - 1, ans = m - (j - i - 1);
	}
	if (ans) for (int i = 1; i <= m; i++) if (i < as || i > ae) putchar(b[i]); else;
	else putchar('-');
//	printf("%d", ans);
}
