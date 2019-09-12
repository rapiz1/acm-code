#include <cstdio>
#include <algorithm>
#include <cstring>
const int V = 21*20;
int n, k, sz, ch[V][3], f[1010][V], end[V], q[V], h, t, fail[V], ans;
char s[20];
inline void up(int& a, int b) {a = a > b ? a : b; ans = ans > a ? ans : a;}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		int now = 0;
		for (char* p = s; *p; p++) {
			if (!ch[now][*p - 'A']) ch[now][*p - 'A'] = ++sz;
			now = ch[now][*p - 'A'];
		}
		end[now]++;
	}
	for (int i = 0; i < 3; i++) if (ch[0][i]) q[t++] = ch[0][i];
	while (h < t) {
		int x = q[h++];
		end[x] += end[fail[x]];
		for (int i = 0; i < 3; i++) if (ch[x][i]) {
			q[t++] = ch[x][i];
			int p = fail[x];
			while (p && !ch[p][i]) p = fail[p];
			fail[ch[x][i]] = ch[p][i];
		} else ch[x][i] = ch[fail[x]][i];
	}
	memset(f, 0xc0, sizeof(f));
	f[0][0] = 0;
	for (int i = 0; i < k; i++) for (int j = 0; j <= sz; j++)
		for (int c = 0; c < 3; c++)
			up(f[i + 1][ch[j][c]], f[i][j] + end[ch[j][c]]);
	printf("%d\n", ans);
}
