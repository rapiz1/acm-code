#include <cstdio>
#include <cstring>
#define file(x) "oulipo."#x
const int L = 2e6;
int n, m, nxt[L];
char a[L], b[L];
void solve() {
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	memset(nxt, 0, sizeof nxt);
	nxt[1] = 0;
	for (int i = 2; i <= n; i++) {
		int p = nxt[i - 1];
		for(;p&&a[i] != a[p + 1]; p = nxt[p]);
		if (a[i] == a[p + 1]) p++;
		nxt[i] = p;
	}
	int ans = 0;
	for (int i = 1, p = 0; i <= m; i++) {
		for(;p&&a[p + 1] != b[i]; p = nxt[p]);
		if (b[i] == a[p + 1]) p++;
		if (p == n) ans++, p = nxt[p];
	}
	printf("%d\n", ans);
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	int t;scanf("%d", &t);
	while (t--) solve();
}
