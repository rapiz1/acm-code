#include <cstdio>
#include <algorithm>
const int M = 300;
int n, m, a[M][M];
int gcd(int a, int b) {return !b ? a : gcd(b, a%b);}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n;i++) {
		int x1, y1, x2, y2, dx, dy;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		dx = x2 - x1, dy = y2 - y1;
		int d = gcd(dx, dy);
		dx /= d, dy /= d;
		a[x1][y1] = a[x2][y2] = i;
		if (x1 < x2 && dx < 0) dx*=-1, dy*=-1; 
		if (x1 > x2 && dx > 0) dx*=-1, dy*=-1; 
		if (y1 < y2 && dy < 0) dx*=-1, dy*=-1;
		if (y1 > y2 && dy > 0) dx*=-1, dy*=-1;
		for (int x = x1, y = y1; x <= m && x >= 1 && y <= m && y >= 1; x += dx, y += dy) {
			if (x != x2 && y != y2) {
				a[x][y] = i;
			}
			else break;
		}
	}
	int q; scanf("%d", &q);
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		printf("%d\n", a[x][y]);
	}
}
