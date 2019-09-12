#include <cstdio>
const int N = 3e5 + 10, M = 5e5 + 10;
struct Edge {int u, v, w;}st[M];
int n, m, p[N], sz[N];
int find(int x) {return p[x] < 0 ? x : p[x] = find(p[x]);}
void uni(int x, int y) {
	x = find(x), y = find(y);
	if (x);
}
char cmd[100];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
	for (int i = 1; i <= m ;i++) {
		int x, y;
		scanf("%s%d", cmd, &x);
		if (cmd[0] == 'A') {
			scanf("%d", &y);
		}
	}
}
