#include <cstdio>
#include <cstring>
const int N = 1010;
int n, m, f[N], to[N][2], cnt;
bool vis[N];
bool find(int u) {
	for (int i = 0, v; i < 2; i++) if(!vis[v = to[u][i]]) {
		vis[v] = 1;
		if (!f[v] || find(f[v])) return (f[v] = u);
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d", &to[i][0], &to[i][1]), to[i][0]++, to[i][1]++;
	for (int i = 1; i <= m; i++) {
		memset(vis, 0, sizeof vis);
		if (find(i)) cnt++;
		else break;
	}
	printf("%d\n", cnt);
}
