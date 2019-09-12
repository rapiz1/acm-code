#include <cstdio>
#include <cstring>
const int N = 1e6 + 10;
typedef long long ll;
int n, nxt[N], a, b, L, R, w[N], m;
char s[N], t[N];
int main() {
	//freopen("input", "r", stdin);
	scanf("%d%d%d%d%d%s", &n, &a, &b, &L, &R, t + 1);
	w[0] = b - a;
	for (int i = 1; i <= n; i++) {
		w[i] = (w[i - 1] + a)%n;
		if (w[i] <= R && w[i] >= L) s[i] = w[i]%2 ? 'T' : 'A';
		else s[i] = w[i]%2 ? 'C' : 'G';
	}
	m = strlen(t + 1);
	for (int i = 2; i <= m; i++) {
		int p = nxt[i - 1];
		while (p && t[p + 1] != t[i]) p = nxt[p];
		if (t[p + 1] == t[i]) p++;
		nxt[i] = p;
	}
	int ans = 0;
	for (int i = 1, p = 0; i <= n; i++) {
		while (p && t[p + 1] != s[i]) p = nxt[p];
		if (t[p + 1] == s[i]) p++;
		if (p == m) ans++, p = nxt[p];
	}
	printf("%d\n", ans);
}
