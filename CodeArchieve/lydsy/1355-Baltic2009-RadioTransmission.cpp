#include <cstdio>
#include <cstring>
const int L = 1e6 + 10;
int n, nxt[L];
char s[L];
int main() {
	scanf("%d%s", &n, s + 1);
	for (int i = 2, p = 0; i <= n; i++) {
		while (p && s[p + 1] != s[i]) p = nxt[p];
		if (s[p + 1] == s[i]) p++;
		nxt[i] = p;
	}
	printf("%d\n", n - nxt[n]);
}
