#include <cstdio>
const int N = 15;
int n, cnt[256];
char a[N][N];
inline bool in(int x) {return 1 <= x && x <= n;}
int main() {
	int t;
//	freopen("output", "w", stdout);
	scanf("%d", &t);
	for (int ks = 1; ks <= t; ks++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
		printf("Case %d:\n", ks);
		for (int i = 1; i <= n; i++, putchar('\n')) for (int j = 1; j <= n; j++) if (a[i][j] == '.') {
			for (char c = 'A'; c <= 'Z'; c++) {
				bool f = 1;
				for (int xx = -1; xx <= 1; xx++) for (int yy = -1; yy <= 1; yy++) if (xx*yy == 0 && xx + yy != 0 && in(i + xx) && in(j + yy)) if (a[i + xx][j + yy] == c) f = 0;
				if (!f) continue;
				printf("%c", a[i][j] = c);
				break;
			}
		}
		else putchar(a[i][j]);
	}
}
