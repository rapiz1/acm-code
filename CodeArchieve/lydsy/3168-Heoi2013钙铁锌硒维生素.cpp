#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
const int N = 2*310;
const double eps = 1e-8;
int n, pri[N][N], sec[N][N], f[N], cc;
double a[N][N];
bool vis[N];
std::vector<int> to[N];
inline bool eq(double x, double y) {return fabs(x - y) <= eps;}
void lu() {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[j][i] = pri[i][j];
	for (int i = 1; i <= n; i++) {
		int r = i;
		for (int j = i + 1; j <= n; j++) if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
		if (r != i) {
			for (int j = 1; j <= n + 1; j++) std::swap(a[i][j], a[r][j]);
			for (int j = 1; j <= n; j++) std::swap(sec[j][r], sec[j][i]);
		}
		for (int j = i + 1; j <= n; j++) {
			a[j][i]/=a[i][i];
			for (int k = i + 1; k <= n; k++) a[j][k] -= a[j][i]*a[i][k];
		}
	}
}
void gd(int ii) {
	for (int i = 1; i <= n; i++) {
		bool alo = 1;
		for (int j = i; j <= n; j++) if (!eq(a[i][j], 0)) alo = 0;
		if (alo && !eq(a[i][n + 1], 0)) return;
	}
	for (int i = 1; i <= n; i++) a[i][n + 1] = sec[ii - n][i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++) a[i][n + 1] -= a[i][j]*a[j][n + 1];
	for (int i = n; i; i--) {
		for (int j = i + 1; j <= n; j++) a[i][n + 1] -= a[i][j]*a[j][n + 1];
		a[i][n + 1] /= a[i][i];
	}
	for (int i = 1; i <= n; i++) if (!eq(a[i][n + 1], 0)) to[ii].push_back(i), to[i].push_back(ii);
}
bool find(int u) {
	for (int i = 0, v; i < (int)to[u].size(); i++) {
		if (vis[v = to[u][i]]) continue;
		vis[v] = 1;
		if (!f[v] || find(f[v])) return (f[v] = u);
	}
	return 0;
}
bool dfs(int u, int t) {
	for (int i = 0, v; i < (int)to[u].size(); i++) {
		if (vis[v = to[u][i]]) continue;
		vis[v] = 1;
		if (f[v] == t || f[v] > t && dfs(f[v], t)) return (f[v] = u);
	}
	return 0;
}
int main() {
//	freopen("ferrous.in" ,"r",stdin);
//	freopen("ferrous.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &pri[i][j]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &sec[i][j]);
	lu();
	for (int i = 1; i <= n; i++) gd(n + i);
	for (int i = n; i; i--) memset(vis, 0, sizeof vis), cc += find(i);
	if (cc == n) {
		puts("TAK");
		for (int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof vis);
			dfs(i, i);
		}
		for (int i = 1; i <= n; i++) for (int j = n + 1; j <= 2*n; j++) if (f[j] == i)
			printf("%d\n", j - n);
	}
	else puts("NIE");
}
