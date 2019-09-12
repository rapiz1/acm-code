#include <cstdio>
#include <algorithm>
#define file(x) "zjoi13_defend."#x
const int N = 1010, M = 1e4 + 10;
const double eps = 1e-8;
int n, m;
int a[N][M];
inline int sgn(double x) {
	return x > eps ? 1 : x < -eps ? -1 : 1;
}
void show() {
	for (int i = 1; i <= m + 1; i++, putchar('\n')) for (int j = 1; j <= n + 1; j++) printf("%2d ", a[i][j]); 
	puts("");
}
void pivot(int l, int e) {
	int t = a[l][e];
	a[l][e] = -1;
	for (int i = 1; i <= m + 1; i++) if (a[i][e] && i != l) {
		for (int j = 1; j <= n + 1; j++) ;
	}
}
int main() {
	freopen(file(in), "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i][m + 1]);
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d%d", &l, &r, &a[n + 1][i]);
		for (int j = l; j <= r; j++) a[j][i] = 1;
	}
	std::swap(n, m);
	printf("%d", a[m + 1][n + 1]);
}
