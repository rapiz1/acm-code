#include <cstdio>
#include <cstring>
const int N = 210, K = 60, V = 5500;
int n, k, v, f[V][K], q[2][K*V], ans;
int main() {
	freopen("bags.in", "r", stdin);
	freopen("bags.out", "w", stdout);
	scanf("%d%d%d", &k , &v, &n);
	memset(f, 0xc0, sizeof(f));
	f[0][1] = 0;
	while (n--) {
		int w, c;
		scanf("%d%d", &c, &w);
		for (int j = v; j >= c; j--)  {
			for (int p = 1; p <= k; p++)
				q[0][p] = f[j - c][p] + w, q[1][p] = f[j][p];
			int x[2] = {1, 1}, tot = 0;
			while (tot < k) {
				if (x[1] > k || (x[0] <= k && q[0][x[0]] > q[1][x[1]])) f[j][++tot] = q[0][x[0]++];
				else f[j][++tot] = q[1][x[1]++];
			}
		}
	}
	for (int i = 1; i <= k; i++) ans += f[v][i];
	printf("%d", ans);
}
