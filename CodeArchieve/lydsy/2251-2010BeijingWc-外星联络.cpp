#include <cstdio>
#include <cstring>
#include <cassert>
const int N = 6010;
int n, m, a[N], b[N], c[N], sa[N], rk[N], h[N];
char s[N];
inline bool cmp(int a, int b, int j) {return rk[a] == rk[b] && rk[a + j] == rk[b + j];}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%s", &n, s + 1);
	m = 256;
	int i, j, p;
	for (i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
	for (j = 0; j <= n; m = p, j?j<<=1:j=1) {
		for (i = n - j + 1, p = 0; i <= n; i++) a[++p] = i;
		for (i = 1; i <= n; i++) if (sa[i] - j > 0) a[++p] = sa[i] - j;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) c[rk[i]]++;
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (i = 1, p = 0; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
	}
	for (p = 0, i = 1; i <= n; h[rk[i++]] = p)
		for(p?p--:0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++);
	for (i = 1; i <= n; i++)
		for (int j = h[i] + 1; sa[i] + j - 1 <= n; j++) {
			int r = i, l = i;
			while (l >= 1 && h[l] >= j) l--;
			while (r + 1 <= n && h[r + 1] >= j) r++;
			if (r - l + 1 > 1) printf("%d\n", r - l + 1);
		}
}
