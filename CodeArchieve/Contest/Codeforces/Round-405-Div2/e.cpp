#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 100;
int n, f[N][3];
char s[N];
using std::min;
int main() {
	freopen("input", "r", stdin);
	memset(f, 0x3f, sizeof(f));
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'V') s[i] = 1;
		else if (s[i] == 'K') s[i] = 2;
		else s[i] = 0;
	}
	s[0] = 9;
	f[1][s[1]] = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 0) f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2]));
		if (s[i] == 2 && s[i - 1] == 0)  {
			f[i][0] = min(f[i][0], min(f[i - 2][0], f[i - 2][2]) + 1);
			if (i - 2 < 1) f[i][0] = min(f[i][0], 1);
		}
		if (s[i] == 1) f[i][0] = min(f[i][0], f[i - 1][0] + 1);
		if (s[i] == 1) f[i][1] = min(f[i][1], min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])));
		if (s[i] == 2 && s[i - 1] == 1) {
			f[i][1] = min(f[i][1], min(f[i - 2][0], f[i - 2][2]) + 1);
			if (i - 2 < 1) f[i][1] = min(f[i][1], 1);
		}
		if (s[i] == 0) f[i][1] = min(f[i][1], f[i - 1][1] + 1);
		if (s[i] == 2) f[i][2] = min(f[i][2], min(f[i - 1][0], f[i - 1][2]));
		else f[i][2] = min(f[i][2], f[i - 1][2] + 1);
	}
	printf("%d\n", min(f[n][0], min(f[n][1], f[n][2])));
}
