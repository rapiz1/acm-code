#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1e6 + 10;
char s[N];
int n, nxt[N], f[N];
long long ans;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%s", &n, s + 1);
	for (int i = 2; i <= n; i++) {
		int p = nxt[i - 1];
		while (p && s[p + 1] != s[i]) p = nxt[p];
		if (s[p + 1] == s[i]) p++;
		nxt[i] = p;
		if (nxt[i]) f[i] = nxt[i];
		if (f[nxt[i]]) f[i] = std::min(f[i], f[nxt[i]]);
		if (f[i]) ans += i - f[i];
	}
	printf("%lld\n", ans);
}
