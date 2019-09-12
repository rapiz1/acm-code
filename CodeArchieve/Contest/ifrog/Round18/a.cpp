#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
const int N = 31, W = 11;
typedef long long ll;
int a[W][W][W], n;
ll ans[N];
void solve() {
	int q;
	scanf("%d%d", &n, &q);
	memset(ans, 0, sizeof ans);
	memset(a, 0, sizeof a);
	for (int i = 1; i <= n; i++) {
		int x, y, z;scanf("%d%d%d", &x, &y, &z);
		a[x][y][z]++;
	}
		for (int x = 0; x < W; x++) for (int y = 0; y  < W; y++)
			for (int z = 0; z < W; z++) if (a[x][y][z]) {
			for (int xx = 0; xx < W; xx++) for (int yy = 0; yy < W; yy++)
				for (int zz = 0, g; zz < W; zz++) if (a[xx][yy][zz]) {
					g=abs(x - xx) + abs(y - yy) + abs(z - zz);
					ans[g] += g ? (ll)a[x][y][z]*a[xx][yy][zz] : (a[x][y][z] - 1ll)*a[x][y][z];
				}
			}
		for (int i = 1; i < N;i ++) ans[i] += ans[i-1];
	while (q--) {
		int x; scanf("%d", &x);
		x = std::min(x, N - 1);
		printf("%lld\n", ans[x]/2);
	}
}
int main() {
//	freopen("input", "r", stdin);
	int t; scanf("%d", &t);
	while(t--) solve();
}
