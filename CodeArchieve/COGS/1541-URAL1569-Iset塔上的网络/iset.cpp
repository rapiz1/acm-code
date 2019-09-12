#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define file(x) "iset." #x
using std::max;
using std::min;
const int N = 110;
int n, m, d[N][N], dis, u, v, pre[N];
bool vis[N], e[N][N];
std::queue<int> q;
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	memset(d, 0x3f, sizeof(d));
	dis = d[0][0];
	while (m--) {
		scanf("%d%d", &u, &v);
		d[u][v] = d[v][u] = 1;
		e[u][v] = e[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) d[i][i] = 0, e[i][i] = 1;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) if (e[i][j]) {
		int q = i != j, x = 0;
		for (int k = 1; k <= n; k++) x = max(x, 2*min(d[i][k], d[j][k]) + q);
		if (x < dis) u = i, v = j, dis = x;
	}
	q.push(u), q.push(v);
	vis[u] = vis[v] = 1;
	for (;!q.empty();q.pop())
		for (int i = 1, x = q.front(); i <= n; i++) 
			if (e[x][i] && !vis[i])
			 	vis[i] = 1, pre[i] = x, q.push(i);
	for (int i = 1; i <= n; i++) if (pre[i]) printf("%d %d\n", i, pre[i]);
	u != v ? printf("%d %d\n", u, v) : 0;
}
