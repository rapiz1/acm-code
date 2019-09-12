#include <cstdio>
#include <algorithm>
const int N = 1e6 + 10;
int n, f[N];
char s[N], ss[N], rev[256];
long long ans;
int main() {
	scanf("%d%s", &n, ss + 1);
	rev['#'] = '#', rev['1'] = '0', rev['0'] = '1';
	for (int i = 1 ;i <= n;i++) s[2*i] = ss[i];
	n=n*2 + 1;
	for (int i = 1; i <= n; i++) if (!s[i]) s[i] = '#';
	s[n + 1] = '$';
	for (int i = 1, p = 0, mx = 0; i <= n; i++) {
		if (mx > i) f[i] = std::min(f[2*p - i], mx - i);
		for (;s[f[i] + i] == rev[s[i - f[i]]]; f[i]++);
		ans += f[i]>>1;
	}
	printf("%lld\n", ans);
}
