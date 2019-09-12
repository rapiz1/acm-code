#include <cstdio>
#include <cstring>
const int N = 2e5 + 10;
int n, m, sa[N], h[N], rk[N], a[N], b[N], c[N], ans, pos, n1;
char s[N];
inline bool cmp(int a, int b, int k) {return rk[a] == rk[b]&&rk[a + k] == rk[b + k];}
int main() {
//	freopen("input", "r", stdin);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	n1 = n;
	s[++n] = 'Z';
	scanf("%s", s + n + 1);
	n += strlen(s + n + 1);
	m = 256;
	int i, j, p;
	for (i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
	for (j = 0; j <= n; m = p) {
		for (i = n - j + 1, p = 0; i <= n; i++) a[++p] = i;
		for (i = 1; i <= n; i++) if (sa[i] - j > 0) a[++p] = sa[i] - j; 
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) c[rk[i]]++;
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (p = 0, i = 1; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p:++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
		j?j<<=1:j=1;
	}
	for (p = 0, i = 1; i <= n; h[rk[i++]] = p)
		for(p?p--:0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++);
	for (i = 2; i <= n; i++) if ((sa[i - 1] <= n1)^(sa[i] <= n1))
		if (h[i] > ans) ans = h[i];
	printf("%d\n", ans);
}
