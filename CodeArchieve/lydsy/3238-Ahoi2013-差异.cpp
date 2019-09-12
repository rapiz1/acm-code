#include <cstdio>
#include <cstring>
#include <cassert>
const int N = 5e5 + 10;
typedef long long ll;
int n, m, a[N], b[N], c[N], sa[N], rk[N], h[N], top;
char s[N];
struct T{ll v, n;}sk[N];
ll ans;
inline bool cmp(int a, int b, int j) {return rk[a] == rk[b] && rk[a + j] == rk[b + j];}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	m = 256;
	int i, j, p;
	for (i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i], 
		ans += (n + 1ll)*(n - i) - (i + 1ll + n)*(n - i)/2 + (n + 1ll)*(i - 1) - i*(i - 1ll)/2;
	for (j = 0; j <= n; m = p, j ? j<<=1:j=1) {
		for (i = n - j + 1, p = 0; i <= n; i++) a[++p] = i;
		memset(c, 0, sizeof(int)*(m + 1));
		for (i = 1; i <= n; i++) {
			if (sa[i] - j > 0) a[++p] = sa[i] - j;
			c[rk[i]]++;
		}
		for (i = 1; i <= m; i++) c[i] += c[i - 1];
		for (i = n; i; i--) sa[c[rk[a[i]]]--] = a[i];
		for (i = 1, p = 0 ; i <= n; i++) b[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p:++p;
		memcpy(rk, b, sizeof(int)*(n + 1));
	}
	for (p = 0, i = 1; i <= n; h[rk[i++]] = p)
		for (p?p--:0, j = sa[rk[i] - 1]; s[i + p] == s[j + p]; p++);
	ll sum = 0;
	for (i = 1; i <= n; i++) {
		ll cnt = 0;
		if (i > 1) cnt++;
		while (top && sk[top - 1].v >= h[i]) {
			top--;
			cnt += sk[top].n;
			sum -= sk[top].n*sk[top].v;
		}
		sum += h[i]*cnt;
		ans = ans - 2*sum;
		sk[top++] = (T){h[i], cnt};
	}
	printf("%lld\n", ans);
}
