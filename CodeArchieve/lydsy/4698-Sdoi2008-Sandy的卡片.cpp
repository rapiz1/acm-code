#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1010, L = 110;
int n, len[N], a[N][L], ans, nxt[L];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", len + i);
		for (int j = 1; j <= len[i]; j++) scanf("%d", &a[i][j]);
		for (int j = len[i]; j; j--) a[i][j] -= a[i][j - 1];
		a[i][1] = 1;
	}
	if (n == 1) ans = len[1];
	for (int* s = a[1], cnt = 1; cnt <= len[1]; s++, cnt++) {
		int ll = len[1] - (s - a[1]);
		for (int i = 2, p = 0; i <= ll; i++) {
			while (p && s[p + 1] !=  s[i]) p = nxt[p];
			if (!p || s[p + 1] == s[i]) p++;
			nxt[i] = p;
		}
		int an = 1e9;
		for (int i = 2; i <= n; i++) {
			int* t = a[i], nn = 0;
			for (int j = 1, p = 0; j <= len[i]; j++) {
				while (p && s[p + 1] != t[j]) p = nxt[p];
				if (!p || s[p + 1] == t[j]) p++;
				nn = std::max(nn, p);
				if (p == ll) break;
			}
			an = std::min(an, nn);
		}
		if (an != 1e9) ans = std::max(ans, an);
	}
	printf("%d\n", ans);
}
