#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
const int N = 2e5 + 10;
int n, m, a[N], b[N], c[N], sa[N], rk[N], h[N], ans[N], val[N << 2];
char s[N];
std::vector<int> vec[N];
inline bool cmp(int a, int b, int j) {return rk[a] == rk[b] && rk[a + j] == rk[b + j];}
int q1, q2, q3;
void change(int o, int l, int r) {
	if (q1 <= l && r <= q2) val[o] = std::min(val[o], q3);
	else {
		int mid = l + r >> 1;
		if (mid >= q1) change(o<<1, l, mid);
		if (mid + 1 <= q2) change(o<<1|1, mid + 1, r);
	}
}
void get(int o, int l, int r, int nv) {
	nv = std::min(nv, val[o]);
	int mid = l + r >> 1;
	if (l == r) ans[l] = nv;
	else get(o<<1, l, mid, nv), get(o<<1|1, mid+1, r, nv);
}
int main() {
// 	freopen("input", "r", stdin);
	scanf("%s", s + 1);
	int i, j, p;
	for (i = 1; s[i]; i++) n++, sa[i] = i, rk[i] = s[i];
	m = 256;
	for (j = 0; j <= n; m = p, j?j<<=1:j=1) {
		for (i = n - j + 1, p = 0; i <= n; i++) a[++p] = i;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) {
			c[rk[i]]++;
			if (sa[i] > j) a[++p] = sa[i] - j;
		}
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (i = 1, p = 0; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
	}
	for (i = 1, p = 0; i <= n; h[rk[i++]] = p)
		for (p?p--:0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++);
	memset(ans, 0x3f, sizeof(ans));
	memset(val, 0x3f, sizeof(val));
	for (i = 1; i <= n; i++) {
		int u = std::max(h[i], h[i + 1]);
		vec[sa[i] + u].push_back(sa[i]);
		if (sa[i] + u <= n) {
			//for (j = sa[i]; j <= n; j++) ans[j] = std::min(ans[j], std::max(j - sa[i] - u, 0) + u + 1);
			q1 = sa[i], q2 = sa[i] + u, q3 = u + 1;
			change(1, 1, n);
		}
	}
	get(1, 1, n, 1e9);
	int mx = -1e9;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < vec[i].size(); j++) mx = std::max(vec[i][j], mx);
		printf("%d\n", std::min(i - mx + 1, ans[i]));
	}
}
