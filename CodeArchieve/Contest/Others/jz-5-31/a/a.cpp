#include <cstdio>
#include <algorithm>
#include <cstring>
const int K = 5, W = 15;
int n, a[K], vis[W][W][W][W];
bool dfs() {
	int& mem = vis[a[1]][a[2]][a[3]][a[4]];
	if (mem != -1) return mem;
	for (int i = 1; i < K; i++) if (a[i] >= i) {
		a[i] -= i;
		int ret = dfs();
		a[i] += i;
		if (!ret) return (mem = 1);
	}
	for (int i = 2; i < K; i++) if(a[i]) {
		for (int j = 1; j < i; j++) {
			a[i]--;
			a[j]++, a[i - j]++;
			int ret = dfs();
			a[i]++;
			a[j]--, a[i - j]--;
			if (!ret) return (mem = 1);
		}
	}
	return (mem = 0);
}
void solve() {
	for (int i = 1; i < K; i++) scanf("%d", a + i);
	memset(vis, -1, sizeof vis);
	printf("%d\n", dfs());
}
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) solve();
}
