#include <cstdio>
#include <vector>
#include <cstring>
const int N = 1e5 + 10;
std::vector<int> f[N], q1, q2;
int fail[N], nxt[N][26], n, m;
bool inq[N];
char s[N], t[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 0; i <= n; i++) f[i].resize(m);
	for (int i = 2, p = 0; i <= m; i++) {
		while (p && t[i] != t[p + 1]) p = fail[p];
		if (t[i] == t[p + 1]) p++;
		fail[i] = p;
	}
	for (int j = 0; j < 26; j++) nxt[0][j] = j == t[1] - 'a';
	for (int i = 1; i < m; i++) {
		nxt[i][t[i + 1] - 'a'] = i + 1;
		for (int j = 0; j < 26; j++) if (!nxt[i][j]){
			nxt[i][j] = nxt[fail[i]][j];
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) f[i][j] = -2e9;
	f[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (f[i][j] >= 0) {
			for (int c = 0; c < 26; c++) if (s[i + 1] == '?' || s[i + 1] - 'a' == c) {
				int p = nxt[j][c], x = 0;
				if (p == m) p = fail[p], x = 1;
				f[i + 1][p] = std::max(f[i + 1][p], f[i][j] + x);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) ans = std::max(ans, f[n][i]);
	printf("%d\n", ans);
}
