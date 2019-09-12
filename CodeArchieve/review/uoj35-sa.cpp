#include <cstdio>
#include <cstring>
const int N = 1e5 + 10;
int n, m = 256, rk[N], sa[N], h[N], a[N], b[N], c[N];
char s[N];
bool cmp(int i, int j, int k) {return rk[i] == rk[j] && rk[i + k] == rk[j + k];}
int main() {
//	freopen("input", "r", stdin);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int i, j, p;
	for (i =  1; i <= n; i++) rk[i] = s[i], sa[i] = i; 
	for(j = 0; j <= n; m = p) {
		for (i = n - j + 1, p = 0; i <= n; i++) a[++p] = i;
		for (i = 1; i <= n; i++) if (sa[i] - j > 0) a[++p] = sa[i] - j;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) c[rk[i]]++;
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (int i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (i = 1, p = 0; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
		j?j<<=1:j=1;
	}
	for(i = 1, p = 0; i <= n; h[rk[i++]] = p)
		for (p ? p-- : 0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++);
	for (int i = 1; i <= n; i++) printf("%d%c", sa[i], " \n"[i == n]);
	for (int i = 2; i <= n; i++) printf("%d%c", h[i], " \n"[i == n]);
}
