#include <cstdio>
#include <cstring>
const int L = 25;
int n, m, k, nxt[L], ans;
char s[L];
struct M{
	int a[L][L], n, m;
	void init(int x) {
		for (int i = 1; i <= x; i++) a[i][i] = 1;
	}
}a, b;
void mul(M& a, const M& b) {
	static M c;
	memset(&c, 0, sizeof(c));
	c.n = a.n, c.m = b.m;
	for (int i = 1; i <= a.n; i++) for (int j = 1; j <= b.m; j++)
		for (int k = 1; k <= a.m; k++) c.a[i][j] = (c.a[i][j] + a.a[i][k]*b.a[k][j])%(::k);
	memcpy(&a, &c, sizeof(c));
}
int main() {
//	freopen("bzoj_1009.in", "r", stdin);
//	freopen("bzoj_1009.out", "w", stdout);
	scanf("%d%d%d%s", &n, &m, &k, s + 1);
	for (int i = 2; i <= m; i++){
		int p = nxt[i - 1];
		while (p && s[p + 1] != s[i]) p = nxt[p];
		if (s[p + 1] == s[i]) p++;
		nxt[i] = p;
	}
	for (int i = 0 ; i < m; i++) for (int j = 0; j <= 9; j++) {
		int p = i;
		char c = j + '0';
		while (p && s[p + 1] != c) p = nxt[p];
		if (s[p + 1] == c) p++;
		b.a[i + 1][p + 1]++;
	}
	b.n = b.m = m;
	a.n = 1, a.m = m;
	a.a[1][1] = 1;
	while (n) {
		if (n&1) mul(a, b);
		n >>= 1, mul(b, b);
	}
	for (int i = 1; i <= m;	i++) ans = (ans + a.a[1][i])%k;
	printf("%d\n", ans%k);
}
