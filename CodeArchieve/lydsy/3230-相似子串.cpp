#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
const int N = 2e5 + 10;
int n, m, q,  a[N], b[N], c[N], sa[N], rk[N], h[23][N], start[N][2], end[N][2];
long long ans[N], sub[N];
char s[N];
inline bool cmp(int a, int b, int j) {return rk[a] == rk[b] && rk[a + j] == rk[b + j];}
inline long long query(int l, int r) {
	if (l == r) return n - l + 1;
	l = rk[l], r = rk[r];
	if (l > r) std::swap(l, r);
	l++;
	int k = r - l + 1, p = 0;
	while ((1 << p + 1) <= k) p++;
	return min(h[p][l], h[p][r - (1 << p) + 1]);
}
void build() {
	m = 256;
	int i, j, p;
	memset(rk, 0, sizeof(rk));
	for (i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
	for (j = 0; j <= n; m = p, j?j<<=1:j=1){
		for (i = n - j + 1, p = 0; i <= n; i++) a[++p] = i;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) {
			c[rk[i]]++;
			if (sa[i] - j > 0) a[++p] = sa[i] - j;
		}
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (p = 0, i = 1; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
	}
	for (p = 0, i = 1; i <= n; h[0][rk[i++]] = p)
		for (p?p--:0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++);
	for (i = 1; i < 23; i++) for (j = 1; j <= n; j++) if (j + (1 << i - 1) <= n)
		h[i][j] = min(h[i - 1][j], h[i - 1][j + (1 << i - 1)]);
	for (i = 1; i <= n; i++) sub[i] = sub[i - 1] + n - sa[i] + 1 - h[0][i];
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d%s", &n, &q, s + 1);
	build();
	for (int i = 1; i <= q; i++) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		int px = std::lower_bound(sub + 1, sub + n + 1, x) - sub, py = std::lower_bound(sub + 1, sub + 1 + n, y) - sub;
		if (px > n || py > n) {
			ans[i] = -1;
			continue;
		}
		x = x - sub[px - 1] + h[0][px], y = y - sub[py - 1] + h[0][py];
		px = sa[px], py = sa[py];
		start[i][0] = px, start[i][1] = py, end[i][0] = px + x - 1, end[i][1] = py + y - 1;
		long long pre = min(query(px, py), min(x, y));
		ans[i] += pre*pre;
	}
	std::reverse(s + 1, s + 1 + n);
	build();
	for (int i = 1; i <= q; i++) if (ans[i] != -1) {
		long long suf = min(query(n - end[i][0] + 1, n - end[i][1] + 1), (long long)min(end[i][0] - start[i][0] + 1, end[i][1] - start[i][1] + 1));
		ans[i] += suf*suf;
	}
	for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}
//子串个数会爆int，输入询问同理
