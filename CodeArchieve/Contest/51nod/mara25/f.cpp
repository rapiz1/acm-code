#include <cstdio>
#include <algorithm>
#include <queue>
const int N = 410, V = N*N, E = (V*2 + V)*2;
int n, s[N], f[N][N], hed[V], nxt[E], sz = 1, S, T;
struct Edge{int u, v, w, c, f;}st[E];
void _add(int u, int v, int w, int c) {
	st[++sz] = (Edge){u, v, w, c, 0};
	nxt[sz] = hed[u], hed[u] = sz;
}
void add(int u, int v, int w, int c) {
	_add(u, v, w, c), _add(v, u, -w, 0);
}
std::queue<int> q;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", s + i);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), s[i] ^= x;
	for (int i = 1; i <= n; i++) s[i] ^= s[i - 1];
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) scanf("%d", &f[i][j]);
	for (int d = 1; d <= n; d++) for (int i = 1; i + d <= n; i++) {
		int j = i + d;
		for (int k = i; k < j; k++) f[i][j] = std::min(f[i][j], f[i][k] + f[k + 1][j]);
	}
	S = n + n*n + 1, T = S + 1;
	for (int i = 1; i <= n; i++) if (s[i]) add(i, T, 0, 1);
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) {
		int u = (i - 1)*n + j;
		add(S, u, f[i][j], 2);
		add(u, i, 0, 1);
		add();
	}
}
