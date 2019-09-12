#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
const int N = 2e3 + 10;
int n, m, a[N], b[N], c[N], sa[N], rk[N], h[N], mn[15][N];
char s[N];
inline bool cmp(int a, int b, int j) {return rk[a] == rk[b] && rk[a + j] == rk[b + j];}
inline int query(int l, int r) {
	if (l > r) std::swap(l, r);
	l++;
	int k = r - l + 1, p = 0;
	while ((1 << p + 1) <= k) p++;
	int aa = std::min(mn[p][l], mn[p][r - (1 << p) + 1]);
	return aa;
}
inline void solve() {
	n = strlen(s + 1), m = 256;
	s[n + 1] = 'Z' + 1;
	int i, j, p;
	for (i = 1; i <= n; i++) s[i + n + 1] = s[n - i + 1];
	n = n*2 + 1;
	for (i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
	for (j = 0; j <= n; m = p) {
		for (p = 0, i = n - j + 1; i <= n; i++) a[++p] = i;
		for (i = 1; i <= n; i++) if (sa[i] - j > 0) a[++p] = sa[i] - j;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) c[rk[i]]++;
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (i = 1, p = 0; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
		j ? j<<=1:j=1;
	}
	for (p = 0, i = 1; i <= n; h[rk[i++]] = p)
		for(p?p--:0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++);
	for (i = 1; i <= n; i++) mn[0][i] = h[i];
	for (p = 1; p < 15; p++)
		for (i = 1; i <= n; i++) if (i + (1 << p - 1) <= n) mn[p][i] = std::min(mn[p - 1][i], mn[p - 1][i + (1 << p - 1)]);
	int ans = 0, type = 0, pos = 0;
	for (int i = 1; i <= (n - 1)/2; i++) {
		int na = query(rk[i + 1], rk[n - i + 2])*2 + 1;
		if (na > ans) ans = na, type = 1, pos = i;
		na = query(rk[i + 1], rk[n - i + 1])*2;
		if (na > ans) ans = na, type = 0, pos = i;
	}
	if (type == 1) for (i = pos - (ans-1)/2; i <= pos + (ans-1)/2; i++) putchar(s[i]);
	else for (i = pos - ans/2 + 1; i <= pos + ans/2; i++) putchar(s[i]);
	putchar('\n');
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%s", s + 1), solve();
}
