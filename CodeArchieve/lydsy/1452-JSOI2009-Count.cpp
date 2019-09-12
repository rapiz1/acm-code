#include <cstdio>
const int N = 310, C = 110;
int n, m, q, a[C][N][N], co[N][N];
inline int lowbit(int x) {return x&-x;}
int P;
inline void add(int x, int y, int v) {
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= m; j += lowbit(j))
			a[P][i][j] += v;
}
inline int pre(int x, int y) {
	int r = 0;
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			r += a[P][i][j];
	return r;
}
inline int sum(int x0, int y0, int x1, int y1) {
	return pre(x1, y1) + pre(x0 - 1, y0 - 1) - pre(x1, y0 - 1) - pre(x0 - 1, y1);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &co[i][j]), P = co[i][j], add(i, j, 1); 
	scanf("%d", &q);
	while (q--) {
		int t, x0, y0, x1, y1, c;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &x0, &y0);
			scanf("%d", &c);
			P = co[x0][y0];
			add(x0, y0, -1);
			P = co[x0][y0] = c;
			add( x0, y0, 1);
		}
		else scanf("%d%d%d%d%d", &x0, &x1, &y0, &y1, &c), P = c, printf("%d\n", sum(x0, y0, x1, y1));
	}
}
