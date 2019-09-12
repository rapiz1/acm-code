#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
using std::min;
const int N = 2e4 + 10;
int n, m, s[N], sa[N], rk[N], h[N];
inline bool cmp(int a, int b, int l) {return rk[a] == rk[b] && rk[a + l] == rk[b + l];}
bool check(int now) {
	static int mn, mx;
	mn = 1e9, mx = 0;
	for (int i = 1; i <= n; i++) {
		if (h[i] < now) {
			if (mx - mn > now) return 1;
			mn = 1e9, mx = 0;
		}
		mn = min(sa[i], mn), mx = max(mx, sa[i]);
	}
	return mx - mn > now;
}
int solve() {
	static int c[N], a[N], b[N];
	memset(sa, 0, sizeof(sa));
	memset(rk, 0, sizeof(rk));
	int i, j, p;
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
	int l = 0, r = n;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	l++;
	return l >= 5 ? l : 0;
}
int main() {
	while (scanf("%d", &n) == 1 && n) {
		m = 0;
		for (int i = 1; i <= n; i++) scanf("%d", s + i);
		for (int i = n; i; i--) s[i] = s[i] - s[i - 1] + 90, m = max(m, s[i]);
		printf("%d\n", solve());
		memset(s, 0, sizeof(int)*(n + 1));
	}
}
