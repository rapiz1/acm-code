#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
const int N = 1010, M = 51;
int n, m, cnt[N][4];
inline int c2i(char x) {
	switch(x) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
}
char s[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m; i++) {
			scanf("%s", s + 1);
			for (int j = 1; j <= n; j++) cnt[j][c2i(s[j])]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int r = 0, d = 0;
			for (int j = 0; j < 4; j++) r += cnt[i][j], d = max(d, cnt[i][j]);
			for (int j = 0; j < 4; j++) if (cnt[i][j] == d) {
				char ch;
				switch (j) {
					case 0: ch = 'A';break;
					case 1: ch = 'C';break;
					case 2: ch = 'G';break;
					case 3: ch = 'T';break;
				}
				putchar(ch);
				break;
			}
			ans += r - d;
		}
		printf("\n%d\n", ans);
	}
}
