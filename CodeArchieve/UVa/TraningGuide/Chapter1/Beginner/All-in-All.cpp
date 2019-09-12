#include <cstdio>
#include <cstring>
const int L = 1e5 + 10;
int m, n;
char a[L], b[L];
int main() {
	while (scanf("%s%s", b, a) == 2) {
		n = strlen(a);
		m = strlen(b);
		int i, j;
		for (j = i = 0; i < n && j < m; i++) if (a[i] == b[j]) j++;
		puts(j == m ? "Yes" : "No");
	}
}
