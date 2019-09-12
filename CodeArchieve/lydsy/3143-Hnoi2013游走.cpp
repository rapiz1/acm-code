#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
const int N = 600;
const double eps = 1e-8;
int n, m, du[N][N];
double a[N][N], ans;
struct EDGE{int u, v;double p;
	bool operator<(const EDGE& b)const {return p > b.p;}
}st[250000];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;scanf("%d%d", &u, &v);
		du[u][u]++, du[v][v]++;
		du[u][v]++, du[v][u]++;
		st[i] = (EDGE){u, v};
	}
	for (int i = 1; i <= n; i++) a[i][i] = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j < n; j++) if (i != j && du[i][j] && du[j][j]) a[i][j] -= 1.0/du[j][j];
	a[1][n + 1] = 1;
	for (int i = 1; i <= n; i++) {
		int r = i;
		for (int j = i + 1; j <= n; j++) if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
		for (int j = 1; j <= n + 1; j++) std::swap(a[r][j], a[i][j]);
		double tmp = a[i][i];
		for (int j = 1; j <= n + 1; j++) a[i][j] /= tmp;
		for (int j = 1; j <= n; j++) if (i != j) {
			tmp = a[j][i];
			for (int k = 1; k <= n + 1; k++) a[j][k] -= tmp*a[i][k];
		}
	}
	a[n][n + 1] = 0;
	for (int i = 1; i <= m; i++) {
		int u = st[i].u, v = st[i].v;
		st[i].p = a[u][n + 1]/du[u][u] + a[v][n + 1]/du[v][v];
	}
	std::sort(st + 1, st + 1 + m);
	for (int i = 1; i <= m; i++) ans += st[i].p*i;
	printf("%.3lf\n", ans);
}
