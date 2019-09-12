#include <bits/stdc++.h>
typedef long long ll;
const int N = 1e3 + 10;
int n, m, q;
long long a[N][N], val[N][N];
char s[100];
int lowbit(int x) {return x&-x;}
ll pre(int x, int y) {return a[x][y];}
ll sum(int x0, int y0, int x1, int y1) {
	return pre(x1, y1) + pre(x0 - 1, y0 - 1) - pre(x1, y0 - 1) - pre(x0 - 1, y1);
}
void build() {
	memset(a, 0, sizeof a);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		a[i][j] = a[i][j - 1] + val[i][j];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] += a[i - 1][j];
}
void solve() {
	memset(a, 0, sizeof a);
	memset(val, 0, sizeof val);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) val[i][j] = i + j;
	build();
	while (q--) {
		scanf("%s", s);
		if (s[0] == 'M') {
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);
			val[x][y] = v;
			build();
		}
		else {
			int x0, y0, x1, y1;
			scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
			printf("%lld\n", sum(x0, y0, x1, y1));
		}
	}
}
int main() {
//	freopen("input", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) solve();
}
