#include <cstdio>
#include <cstring>
const int L = 110;
int r[256], c[256];
bool usd[256];
char a[L], b[L];
inline void cnt(char* s, int* d) {
	while (*s) d[*s++]++;
}
int main() {
//	freopen("input", "r", stdin);
	while (scanf("%s%s", b, a) == 2) {
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		memset(usd, 0, sizeof(usd));
		bool f = 1;
		cnt(a, r);
		cnt(b, c);
		for (int i = 'A'; i <= 'Z'; i++) {
			int j;
			for (j = 'A'; j <= 'Z'; j++) if (!usd[j] && r[i] == c[j]) {
				usd[j] = 1;
				break;
			}
			if (j > 'Z') f = 0;
		}
		puts(f ? "YES" : "NO");
	}
}
