#include <cstdio>
#include <cstring>
char buf[600];
bool ex[256];
int main() {
//	freopen("input", "r", stdin);
	scanf("%s", buf + 1);
	int n = strlen(buf + 1);
	for (int i = 1; i <= n; i++) {
		int x = buf[i] - 'a';
		for (int j = 0; j < x; j++) if (!ex[j]) {
			puts("NO");
			return 0;
		}
		ex[x] = 1;
	}
	puts("YES");
}
