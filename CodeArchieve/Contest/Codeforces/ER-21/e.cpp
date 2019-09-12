#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 1e5 + 10, W = 4, M = 3e5 + 10;
int n, m, a[N], f[W][M];
std::vector<int> b[4];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, w, c; i <= n; i++) {
		scanf("%d%d" , &w, &c);
		a[w].push_back(c);
	}
	for (int i = 1; i < W; i++) std::sort(b[i].begin(), b[i].end());
	for (int i = 1; i < W; i++) {
		for (int j = 1; j <= m; j++) {

		}
	}
}
