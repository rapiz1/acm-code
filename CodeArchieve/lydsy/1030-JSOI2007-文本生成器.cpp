#include <cstdio>
const int V = 62*110, L = 110, MOD = 1e4 + 7;
int n, m, ch[V][26], fail[V], sz, q[V], h, t, f[L][V];
bool end[V];
char s[L];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		int now = 0;
		for (char* p = s; *p; p++) {
			if (!ch[now][*p - 'A']) ch[now][*p - 'A'] = ++sz;
			now = ch[now][*p - 'A'];
		}
		end[now] = 1;
	}
	for (int i = 0; i < 26; i++) if (ch[0][i]) q[t++] = ch[0][i];
	while (h < t) {
		int x = q[h++];
		if (end[fail[x]]) end[x] = 1;
		for (int i = 0; i < 26; i++) if (ch[x][i]) {
			q[t++] = ch[x][i];
			int p = fail[x];
			while (p && !ch[p][i]) p = fail[p];
			fail[ch[x][i]] = ch[p][i];
		}else ch[x][i] = ch[fail[x]][i];
	}
	f[0][0] = 1;
	for (int i = 0; i < m; i++) for (int j = 0; j <= sz; j++) if (!end[j])
		for (int k = 0; k < 26; k++) f[i + 1][ch[j][k]] = (f[i][j] + f[i + 1][ch[j][k]])%MOD;
	int ans1 = 0, ans2 = 1;
	for (int i = 1; i <= m; i++) ans2 = ans2*26%MOD;
	for (int i = 0; i <= sz; i++) if (!end[i]) ans1 = (ans1 + f[m][i])%MOD;
	printf("%d\n", (ans2 - ans1 + MOD)%MOD);
}
