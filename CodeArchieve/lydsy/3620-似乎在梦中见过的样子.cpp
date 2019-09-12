#include <cstdio>
#include <cstring>
const int L = 15010;
int n, nxt[L], k;
long long ans;
char buf[L << 1];
int main() {
	//freopen("input", "r", stdin);
	scanf("%s%d", buf + 1, &k);
	for (char* s = buf; s == buf || *s; s++) {
		for (int i = 2, p = 0, p2 = 0; s[i]; i++) {
			while (p && s[p + 1] != s[i]) p = nxt[p];
			if (s[p + 1] == s[i]) p++;
			nxt[i] = p;
			while (p2 && s[p2 + 1] != s[i]) p2 = nxt[p2];
			if (s[p2 + 1] == s[i]) p2++;
			while (p2*2 + 1 > i) p2 = nxt[p2];
			if (p2 >= k) ans++;
		}
	}
	printf("%lld\n", ans);
}
