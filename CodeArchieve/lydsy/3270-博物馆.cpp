#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
const int NN = 410;
int n, m, a, b, du[NN],N;
double x[NN][NN], p[NN];
std::vector<int> to[30];
int zip(int a, int b) {return (a - 1)*n + b;}
int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	N = zip(n, n);
	for (int i = 1, u, v; i <= m; i++)scanf("%d%d", &u, &v), to[u].push_back(v), to[v].push_back(u), du[u]++, du[v]++;
	for (int i = 1; i <= n; i++) scanf("%lf", p + i);
	for (int i = 1; i <= N; i++) x[i][i] = 1;
	x[zip(a, b)][N + 1] = 1;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) if (i != j) {
			for (int x = 0; x < to[i].size(); x++)
				for (int y = 0; y < to[j].size(); y++) {
					int aa = to[i][x], bb = to[j][y];
					::x[zip(aa, bb)][zip(i, j)] -=  (1 - p[i])/du[i]*(1 - p[j])/du[j];//两人都走
				}
			for (int x = 0; x < to[i].size(); x++) {
				int aa = to[i][x];//a走
				::x[zip(aa, j)][zip(i, j)] -= (1-p[i])/du[i]*p[j];
			}
			for (int y = 0; y < to[j].size(); y++) {
				int bb = to[j][y];//b走
				::x[zip(i, bb)][zip(i, j)] -= p[i]*(1 - p[j])/du[j];
			}

			x[zip(i, j)][zip(i, j)] -= p[i]*p[j];//都不走
		}
	for (int i = 1; i <= N; i++) {
		int r = i;
		for (int j = i + 1; j <= N; j++) if (fabs(x[j][i]) >fabs(x[r][i])) r = j;
		for (int j = 1; j <= N + 1; j++) std::swap(x[i][j], x[r][j]);
		double tmp = x[i][i];
		for (int j = 1; j <= N + 1; j++) x[i][j]/=tmp;
		for (int j = 1; j <= N; j++) if (i != j) {
			tmp = x[j][i];
			for (int k = 1; k <= N + 1; k++) x[j][k] -= tmp*x[i][k];
		}
	}
//	print();
	for (int i = 1; i <= n; i++) printf("%.6lf ", x[zip(i, i)][N + 1]);
}
