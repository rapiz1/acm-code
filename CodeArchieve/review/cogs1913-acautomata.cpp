#include <cstdio>
#include <cctype>
#define file(x) "ACautomata."#x
const int L = 60, N = 11, V = N*L, C = 'z' - 'a' + 1;
int n, ch[V][C], cnt[V], q[V], h, t, fail[V], top;
char s[N][L];
int find(char* s) {
	int p = 0;
	for (;*s; s++) {
		int c = *s - 'a';
		if (!ch[p][c]) ch[p][c] = ++top;
		p = ch[p][c];
	}
	return p;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", s[i]), find(s[i]);
	for (int i = 0; i < C; i++) if (ch[0][i]) q[t++] = ch[0][i];
	while (h < t) {
		int u = q[h++];
		for (int c = 0; c < C; c++) if (ch[u][c]) {
			q[t++] = ch[u][c];
			int p = fail[u];
			for (;p && !ch[p][c]; p = fail[p]);
			fail[ch[u][c]] = ch[p][c];
		}
		else ch[u][c] = ch[fail[u]][c];
	}
	int c;
	do c = getchar(); while (!isalpha(c));
	int p = 0;
	for(;isalpha(c); c = getchar()) cnt[p = ch[p][c - 'a']]++;
	for (int i = t; ~i; i--) cnt[fail[q[i]]] += cnt[q[i]];
	for (int i = 1; i <= n; i++) printf("%s %d\n", s[i], cnt[find(s[i])]);
}
