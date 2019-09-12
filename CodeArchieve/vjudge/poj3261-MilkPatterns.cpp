#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 2e4 + 10;
int n, m, u, sa[N], rk[N], a[N], b[N], s[N], c[N], h[N];
inline bool cmp(int a, int b, int k) {return rk[a] == rk[b] && rk[a + k] == rk[b + k];}
inline bool check(int now) {
	int ans = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (h[i] < now) ans = std::max(ans, cnt), cnt = 0;
		cnt++;
	}
	return std::max(ans,cnt) >= u;
}
int main() {
	scanf("%d%d", &n, &u);
	int i, j, p;
	for (i = 1; i <= n; i++) scanf("%d", s + i), m = std::max(m,s[i]), sa[i] = i, rk[i] = s[i];
	for (j = 0; j <= n; m = p) {
		for (i = n - j + 1, p = 0; i <= n; i++) a[++p] = i;
		for (i = 1; i <= n; i++) if (sa[i] - j > 0) a[++p] = sa[i] - j;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) c[rk[i]]++;
		for (i = 1; i <= n; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (i = 1, p = 0; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
		j ? j<<=1:j=1;
	}
	for (i = 1, p = 0; i <= n; h[rk[i++]]=p)
		for(p?p--:0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++);
	int l = 0, r = n;
	while (l < r) {
		int mid = l + r + 1>> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
}
