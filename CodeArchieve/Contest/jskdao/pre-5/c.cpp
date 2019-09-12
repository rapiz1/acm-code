#include <cstdio>
#include <cstring>
const int N = 5e4 + 10;
int n, m, s[N], t[N], c[N], b[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d",s + i);
	scanf("%d", &m);
	while (m--) {
		int k; scanf("%d", &k);
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		for (int i = 1; i <= k; i++) scanf("%d", t + i), b[t[i]]++;
		for (int i = 1; i <= k; i++) c[s[i]]++;
		int diff = 0, ans = 0 ;
		for (int i = 1; i <= n; i++) diff += b[i] != c[i];
		if (!diff) ans++;
		for (int i = 2; i + k - 1 <= n; i++) {
			if (c[s[i - 1]] == b[s[i - 1]]) diff++;
			c[s[i - 1]]--;
			if (c[s[i - 1]] == b[s[i - 1]]) diff--;
			if (c[s[i + k -1]] == b[s[i + k - 1]]) diff++;
			c[s[i + k - 1]]++;
			if (c[s[i + k -1]] == b[s[i + k - 1]]) diff--;
			if (!diff) ans++;
		}
		printf("%d\n", ans);
	}
}
