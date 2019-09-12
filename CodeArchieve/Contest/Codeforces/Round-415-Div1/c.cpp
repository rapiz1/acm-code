#include <cstdio>
#include <cstring>
const int N = 100, M = 8, MOD = 1e9 + 7;
int a[M][M] = {
{1, 2, 3, 4, 5, 6, 7, 8},
{2, 1, 4, 3, 6, 5, 8, 7},
{3, 4, 1, 2, 7, 8, 5, 6},
{4, 3, 2, 1, 8, 7, 6, 5},
{5, 6, 7, 8, 1, 2, 3, 4},
{6, 5, 8, 7, 2, 1, 4, 3},
{7, 8, 5, 6, 3, 4, 1, 2},
{8, 7, 6, 5, 4, 3, 2, 1} 
};
int f(int x, int y) {
	if (x < M && y < M) return a[x][y];
	else return f(x%M, y%M) + f(x/M,y/M)*M;
}
int main() {
//	scanf("%d", &n);
	int n = 50;
	for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) a[i][j]--;

	for (int i = 0; i < n; i++, putchar('\n')) for (int j = 0; j < n; j++)
	 	printf("%2d ", f(i, j) + 1);
}
