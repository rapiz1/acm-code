#include <cstdio>
#include <cstring>
const int L = 200010;
int n, n1 ,m, a[L], b[L], c[L], sa[L], rk[L];
char s[L];
inline bool cmp(int a, int b, int j) {return rk[a] == rk[b] && rk[a + j] == rk[b + j];}
int main() {
	scanf("%s", s + 1);
	int i, j, p;
	n1 = strlen(s + 1);
	for (i = 1; i <= n1; i++) s[i + n1] = s[i];
	n = n1<<1;
	for (i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
	m = 256;
	for (j = 0; j <= n; m = p, j?j<<=1:j=1) {
		for (i = n - j + 1, p = 0; i <= n; i++) a[++p] = i;
		for (i = 1; i <= n; i++) if (sa[i] - j > 0) a[++p] = sa[i] - j;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) c[rk[i]]++;
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (i = 1, p = 0; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p:++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
	}
	for (i = 1; i <= n; i++) if (sa[i] <= n1) putchar(s[sa[i] + n1 - 1]);
}
