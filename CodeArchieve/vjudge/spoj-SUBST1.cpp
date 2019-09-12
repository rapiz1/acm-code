#include <cstdio>
#include <cstring>
const int N = 5e4 + 10;
int n, m, a[N], b[N], c[N], sa[N], rk[N], h[N];
char s[N];
inline bool cmp(int a, int b, int k) {return rk[a] == rk[b] && rk[a + k] == rk[b + k];}
inline int solve() {
	n = strlen(s + 1);
	m = 256;
	memset(sa, 0, sizeof(sa));
	memset(rk, 0, sizeof(rk));
	int i, j, p;
	for (i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
	for (j = 0; j <= n; m = p) {
		for (p = 0, i = n - j + 1; i <= n; i++) a[++p] = i;
		for (i = 1; i <= n; i++) if (sa[i] - j > 0) a[++p] = sa[i] - j;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) c[rk[i]]++;
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (p = 0, i = 1; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
		j?j<<=1:j=1;
	} 
	for (p = 0, i = 1; i <= n; h[rk[i++]] = p)
		for (p?p--:0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++); 
	int ans = 0;
	for (i = 1; i <= n; i++) ans += n - sa[i] + 1 - h[i];
	return ans;
}
int main() {
	freopen("input", "r", stdin);
	int ks;scanf("%d", &ks);
	while (ks--) scanf("%s", s + 1), printf("%d\n", solve());
}
