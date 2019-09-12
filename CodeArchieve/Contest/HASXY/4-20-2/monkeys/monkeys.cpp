#include <cstdio>
#include <algorithm>
#include <cstring>
const int C = 25;
int n, m, k, x[C], y[C], vis[int(1e7)];
bool check(int a, int dep) {
	if (dep == n) return !a;
	if (!a) return 1;
	if (dep < vis[a]) return vis[a];
	for (int i = 1; i <= m; i++) if (a >= y[i] && (a - y[i])%x[i] == 0) {
		if (check(a - y[i] - (a - y[i])/x[i], dep + 1)) return (vis[a] = std::max(dep, vis[a]));
	}
	return 0;
}
int main() {
	freopen("monkeys.in", "r", stdin);
//	freopen("monkeys.out", "w", stdout);
	memset(vis, -1, sizeof vis);
	scanf("%d%d", &n, &m);
	n++;
	for (int i= 1; i <= m; i++) scanf("%d%d", x + i, y + i);
	scanf("%d", &k);
	/*
	int i, tot;
	for (i = 1, tot = 0; tot < k && i < int(1e7); i++)
		if (check(i, 1)) tot++;
		*/
	for (int i = 1; i <= 100 ;i++) if (check(i, 1)) printf("%d\n", i);
//	printf("%d\n", tot == k ? i - 1 : -1);
}
