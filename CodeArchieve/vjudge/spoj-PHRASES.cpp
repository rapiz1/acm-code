#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
const int N = 11, L = 10010*N;
int n, m, u, a[L], b[L], c[L], sa[L], rk[L], h[L], sk[L], top, mx[N], mn[N], bl[L];
char s[L];
inline bool cmp(int a, int b, int j) {return rk[a] == rk[b] && rk[a + j] == rk[b + j];}
int succ = 0;
inline void clear(int now) {
	int i;
	for (i = 0; i < top; i++) {
		int x = sk[i];
		mn[bl[x]] = std::min(mn[bl[x]], x);
		mx[bl[x]] = std::max(mx[bl[x]], x);
	}
	int cc = 0;
	for (i = 1; i <= u; i++) cc += mx[i] - mn[i] >= now;
	if (cc == u) succ = 1;
	while (top) {
		int x = bl[sk[--top]];
		mn[x] = 0x3f3f3f3f, mx[x] = 0;
	}
}
inline bool check(int now) {
	succ = 0;
	memset(mn, 0x3f, sizeof(mn));
	for (int i = 1; i <= n; i++) {
		if (h[i] < now) clear(now);
		sk[top++] = sa[i];
	}
	clear(now);
	return succ;
}
inline void solve() {
	memset(rk, 0, sizeof(rk));
	memset(bl, 0, sizeof(bl));
	memset(s, 0, sizeof(s));
	scanf("%d", &u);
	int i, j, p, l = 0, r = 0;
	n = 0, m = 256;
	for (i = 1; i <= u; i++) {
		scanf("%s", s + n + 1);
		int n1 = strlen(s + n + 1);
		r = std::max(r, n1);
		for (j = 1; j <= n1; j++) bl[++n] = i, s[n] = s[n] - 'a' + 1;
		s[++n] = 30 + i;
	}
	for (i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
	for (j = 0; j <= n; m = p) {
		for (i = n - j + 1, p = 0; i <= n; i++) a[++p] = i;
		for (i = 1; i <= n; i++) if (sa[i] - j > 0) a[++p] = sa[i] - j;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) c[rk[i]]++;
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (i = 1, p = 0; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
		j ? j<<=1 : j=1;
	}
	for (i = 1, p = 0; i <= n; h[rk[i++]] = p)
		for (p?p--:0, j = sa[rk[i] - 1]; s[j + p] == s[i + p]; p++);
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
}
int main() {
//	freopen("input", "r", stdin);
	int ks;scanf("%d", &ks);
	while (ks--) solve();
}
