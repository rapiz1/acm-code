#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int f[N], n;
char s[N], ss[N];
int main() {
//	freopen("input", "r", stdin);
	while (scanf("%s", ss + 1) == 1) {
		memset(f, 0, sizeof f);
		memset(s, 0, sizeof s);
		for (int i = 1; ss[i]; i++) s[2*i] = ss[i];
		n = strlen(ss + 1)*2 + 1;
		s[n + 1] = '*';
		for (int i = 1; i <= n; i++) if (!s[i]) s[i] = '#';
		int ans = 0;
		for (int i = 1, p = 0, mx = 0; i <= n; i++) {
			if (mx > i) f[i] = min(f[p*2 - i], mx - i);
			while (s[i + f[i]] == s[i - f[i]]) f[i]++;
			if (i + f[i] > mx) mx = f[i] + i, p = i;
			ans = max(ans, f[i]);
		}
		printf("%d\n", ans - 1);
	}
}
