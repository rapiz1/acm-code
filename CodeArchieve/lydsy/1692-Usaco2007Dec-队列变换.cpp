#include <cstdio>
#include <cstring>
const int N = 6e4 + 10;
int n, n1, m, a[N], b[N], c[N], sa[N], rk[N];
char s[N], ans[N];
inline bool cmp(int a, int b, int j) {return rk[a] == rk[b] && rk[a + j] == rk[b + j];}
int main() {
	scanf("%d", &n);
	n1 = n;
	int i, j, p;
	for (i = 1; i <= n; i++) scanf("%s", s + i);
	for (i = 1; i <= n; i++) s[2*n - i + 2] = s[i];
	s[++n] = 1;
	n += n - 1;
	m = 256;
	for (i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
	for (j = 0; j <= n; m = p, j ? j<<=1:j=1){
		for (i = n - j + 1, p = 0; i <= n; i++) a[++p] = i;
		for (i = 1; i <= n; i++) if (sa[i] - j > 0) a[++p] = sa[i] - j;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) c[rk[i]]++;
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (i = 1, p = 0; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
	}
	for (i = 1, j = n1, p = 0; i <= j;)
		ans[p++] = rk[i] < rk[n1 + 1 + (n1 - j + 1)] ? s[i++] : s[j--];
	for (i = 0; i < p; i++) {
		if (i && i%80 == 0) putchar('\n'); 
		putchar(ans[i]);
	}
}
