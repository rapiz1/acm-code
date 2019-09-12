#include <cstdio>
#include <algorithm>
#include <cstring>
const int L = 1e5 + 10;
int n, m, f[L], p[L];
char s[L], ss[L];
inline bool isplalin(int l, int r) {
	return p[l + r] - 1 >= r - l + 1;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) ss[2*i] = s[i];
	m = 2*n + 1;
	for (int i = 1; i <= m; i++) if (!ss[i]) ss[i] = '#';
	ss[0] = '$';
	for (int i = 1, mx = 0, id = 0; i <= m; i++) {
		if (mx > i && id) p[i] = std::min(mx - i, p[id*2 - i]);
		else p[i] = 1;
		while (p[i] <= i && ss[i + p[i]] == ss[i - p[i]]) p[i]++;
		if (i + p[i] > mx) mx = i + p[i], id = i;
	}
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = 1e9;
		for (int j = 0; j <= i; j++) if (isplalin(j + 1, i))
			f[i] = std::min(f[i], f[j] + 1);
	}
	printf("%d\n", f[n]);
}
