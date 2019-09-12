#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#define file(x) "lights."#x
const int N = 40, M = 600;
std::vector<int> to[N], fv;
std::bitset<N> bits[N];
int n, m, cc, ily;
void dfs(int p) {
	if (p >= fv.size()) {
		for (int i = 1; i <= n; i++) ily += bits[i][n + 1];
		cc = std::min(cc, ily);
		for (int i = 1; i <= n; i++) ily -= bits[i][n + 1];
	}
	else {
		if (ily >= cc) return;
		int u = fv[p];
		ily++;
		for (int i = 1; i <= n; i++) if (bits[i][u]) bits[i].flip(n + 1);
		dfs(p + 1);
		ily--;
		for (int i = 1; i <= n; i++) if (bits[i][u]) bits[i].flip(n + 1);
		dfs(p + 1);
	}
}
void print() {
	for (int i = 1; i <= n; i++, putchar('\n'))
			for (int j = 1; j <= n; j++) printf("%d", (int)bits[i][j]);
	puts("");
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) 
		scanf("%d%d", &u, &v), bits[u][v] = bits[v][u] = 1;
	for (int i = 1; i <= n; i++) bits[i][i] = bits[i][n + 1] = 1;
	for (int i = 1; i <= n; i++) {
		int r = i;
		for (;r <= n && !bits[r][i]; r++);
		if (r > n) {
			fv.push_back(i);
			continue;
		}
		std::swap(bits[i], bits[r]);
		for (int j = 1; j <= n; j++) if (i != j && bits[j][i]) bits[j] ^= bits[i];
	}
	if (fv.size()) {
		cc = 1e9;
		dfs(0);
		printf("%d\n", cc);
	}
	else {
		int fix = 0;
		for (int i = 1; i <= n; i++) fix += bits[i][n + 1];
		printf("%d\n", fix);
	}
}
