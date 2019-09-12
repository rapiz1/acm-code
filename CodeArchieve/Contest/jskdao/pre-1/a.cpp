#include <cstdio>
const int D = 3;
int n, m;
bool a[100][100];
inline int g(int i, int j){return a[i + D][j + D];}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x, y;scanf("%d%d", &x, &y);
		x += D, y += D;
		a[x][y] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= 3; i++) {
		ans += g(-i, i) && g(-i, 0) && g(-i, -i);
		ans += g(i, i) && g(i, 0) && g(i, -i);

		ans += g(-i, i) && g(0, i) && g(i, i);
		ans += g(-i, -i) && g(0, -i) && g(i, -i);
	}

	ans += g(0, 3) && g(0, 2) && g(0, 1);
	ans += g(0, -3) && g(0, -2) && g(0, -1);

	ans += g(-3, 0) && g(-2, 0) && g(-1, 0);
	ans += g(3, 0) && g(2, 0) && g(1, 0);
	printf("%d\n", ans);
}
