#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
const int N = 110, L = N*1010;
int u, n, m, bl[L], a[L], b[L], c[L], sa[L], rk[L], h[L], s[L], sk[L], top;
bool in[L];
char buf[L];
std::vector<int> sol;
inline bool cmp(int a, int b, int j) {return rk[a] == rk[b] && rk[a + j] == rk[b + j];}
inline bool check(int now) {
	sol.clear();
	top = 0;
	int i, na, ans = 0;
	for (i = 1, na = 0; i <= n; i++) {
		if (h[i] < now) {
			if (top && na > u/2]) sol.push_back(sk[top - 1]);
			while (top) {
				--top;
				in[bl[sk[top]]] = 0;
			}
			na = 0;
		}
		sk[top++] = sa[i];
		na += bl[sa[i]] && !in[bl[sa[i]]];
		in[bl[sa[i]]] = 1;
		ans = std::max(ans, na);
	}
	if (top && na > u/2) sol.push_back(sk[top - 1]);
	while (top) {
		--top;
		in[bl[sk[top]]] = 0;
	}
	return ans > u/2;
}
inline void solve() {
	memset(rk, 0, sizeof(rk));
	memset(s, 0, sizeof(s));
	memset(bl, 0, sizeof(bl));
	int i, j, p, l = 0, r = 0;
	n = 0;
	m = 30 + u;
	for (i = 1; i <= u; i++) {
		scanf("%s", buf);
		r = std::max(r, (int)strlen(buf));
		for (char* c = buf; *c; c++) s[++n] = *c - 'a' + 1, bl[n] = i;
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
		for (p = 0, i = 1; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
		j?j<<=1:j=1;
	}
	for (p = 0, i = 1; i <= n; h[rk[i++]] = p)
		for (p?p--:0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++);
	while (l < r) {
		int mid = l + r + 1>> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	if (l) {
		check(l);
		for (i = 0; i < sol.size(); i++)
			if (bl[sol[i]] && bl[sol[i] + l - 1] == bl[sol[i]]){
				for (j = 1; j <= l; j++) putchar(s[sol[i] + j - 1] + 'a' - 1);
				putchar('\n');
			}
	}
	else puts("?");
}
int main() {
//	freopen("input2", "r", stdin);
	bool f = 1;
	while (scanf("%d", &u), u) f?f=0:putchar('\n'), solve();
}
