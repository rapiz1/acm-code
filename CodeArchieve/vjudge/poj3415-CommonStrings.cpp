#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 2e5 + 10;
int n, n1, k, m, a[N], b[N], c[N], sa[N], rk[N], h[N], top;
long long ans;
struct T{long long v, num;}sk[N];
char s[N];
inline bool cmp(int a, int b, int l) {return rk[a + l] == rk[b + l] && rk[a] == rk[b];}
inline int baoli() {
	int s = 1, ret = 0;
	for (int i = 1; i <= n; i++) {
		if (h[i] < k) s = i;
		for (int j = s; j <= i; j++) if ((sa[j] <= n1)^(sa[i] <= n1)){
			int mn = 1e9;
			for (int p = j + 1; p <= i; p++) mn = std::min(mn, h[p]);
			ret += mn - k + 1;
		}
	}
	return ret;
}
inline long long solve() {
	memset(rk, 0, sizeof(rk));
	memset(sa, 0, sizeof(sa));
	ans = top = 0;
	scanf("%s", s + 1);
	n = n1 = strlen(s + 1);
	s[++n] = 'Z' + 1;
	m = 256;
	scanf("%s", s + n + 1);
	n += strlen(s + n + 1);
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
		j?j<<=1:j=1;
	}
	for (i = 1, p = 0; i <= n; h[rk[i++]] = p)
		for (p?p--:0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++);
	long long sum = 0;
	for (i = 1; i <= n; i++) {
		if (h[i] < k) {
			top = sum = 0;
			continue;
		}
		long long cnt = 0;
		if (sa[i - 1] <= n1) cnt++;
		while (top > 0 && sk[top].v >= h[i])
			cnt += sk[top].num, sum -= sk[top].num*(sk[top].v - k + 1), top--;
		sum += cnt*(h[i] - k + 1);
		sk[++top] = (T){h[i], cnt};
		if (sa[i] > n1 + 1) ans += sum;
	}
	top = sum = 0;
	for (i = 1; i <= n; i++) {
		if (h[i] < k) {
			top = sum = 0;
			continue;
		}
		long long cnt = 0;
		if (sa[i - 1] > n1 + 1) cnt++;
		while (top > 0 && sk[top].v >= h[i])
			cnt += sk[top].num, sum -= sk[top].num*(sk[top].v - k + 1), top--;
		sum += cnt*(h[i] - k + 1);
		sk[++top] = (T){h[i], cnt};
		if (sa[i] <= n1) ans += sum;
	}
	return ans;
}
int main() {
//	freopen("input", "r", stdin);
	while (scanf("%d", &k), k) printf("%lld\n", solve());
}
