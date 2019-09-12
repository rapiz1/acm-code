#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 3e5 + 10;
int n, f[N];
char s[N], ss[N];
struct L{int l, r;
	bool operator<(const L& b)const {return l < b.l;}
}st[N];
int main() {
//	freopen("input", "r", stdin);
	while (scanf("%s", ss + 1) == 1) {
		memset(f, 0, sizeof f);
		memset(s, 0, sizeof s);
		n = strlen(ss + 1);
		for (int i = 1; ss[i]; i++) s[2*i] = ss[i], s[2*i-1]='#';
		n = 2*n + 1;
		s[n] = '#';
		s[n + 1] = '$';
		for (int i = 1, p = 0, mx = 0; i <= n; i++) {
			if (mx > i) f[i] = std::min(f[2*p - i], mx - i);
			while (s[i + f[i]] == s[i - f[i]]) f[i]++;
			if (i + f[i] > mx) mx = f[i] + i, p = i;
			st[i] = (L){i - f[i] + 1, i + f[i] - 1};
		}
		std::sort(st + 1, st + 1 + n);
		int ans = 0;
		for (int i = 0, j = 0, k = 0; st[i].r < n; i = k) {
			while (j + 1 <= n && st[j + 1].l <= st[i].r + 1) {
				if (st[++j].r > st[k].r) k = j;
			}
			ans++;
		}
		printf("%d\n", ans-1);
	}
}
