#include <cstdio>
#include <cstring>
const int L = 1e6 + 10;
int nxt[L], n, m, cnt, p[L];
char s[L], t[L], res[L];
int main() {
//	freopen("input", "r", stdin);
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	for (int i = 2, p = 0; i <= m; i++) {
		while (p && t[p + 1] != t[i]) p = nxt[p];
		if (t[p + 1] == t[i]) p++;
		nxt[i] = p;
	}
	for (int i = 1; i <= n; i++) {
		int f = p[cnt];
		while (f && s[i] != t[f + 1])  f = nxt[f];
		if (t[f + 1] == s[i]) f++;
		res[++cnt] = s[i];
		p[cnt] = f;
		if (f == m) {
			for (int k = 1; k <= m; k++) res[cnt--] = 0;
		}
	}
	puts(res + 1);
}
