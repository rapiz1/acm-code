#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
const int L = 6;
int ans, n, m;
bool a[L][L], b[L][L];
std::vector<int> sol;
inline bool c2l(int x) {
	if (x - 2 < 0) return 1;
	for (int j = 0; j < m; j++) if (!b[x - 2][j]) return 0;
	return 1;
}
inline bool ck(int x, int y) {return 0 <= x && x < n && 0 <= y && y < m;}
bool dfs(int p, int s) {
	if (p == n*m) return c2l(n - 1) && c2l(n) && c2l(n + 1);
	if (p%m == 0 && !c2l(p/m)) return 0;
	if (dfs(p + 1, s)) return 1;
	int x = p/m, y = p%m;
	for (int i = x - 1, xx = 0; i <= x + 1; i++, xx++) 
		for (int j = y - 1, yy = 0; j <= y + 1; j++, yy++)
			if (ck(i, j)) b[i][j] ^= a[xx][yy];
	sol.push_back(p);
	if (dfs(p + 1, s + 1)) return 1;
	sol.pop_back();
	for (int i = x - 1, xx = 0; i <= x + 1; i++, xx++) 
		for (int j = y - 1, yy = 0; j <= y + 1; j++, yy++)
			if (ck(i, j)) b[i][j] ^= a[xx][yy];
	return 0;
}
int main() {
//	freopen("input", "r", stdin);
	int ks = 0;
	while (scanf("%d%d", &n, &m)&&n&&m) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char c;
				scanf(" %c", &c);
				a[i][j] = c == '*';
			}
		}
		memset(b, 0, sizeof(b));
		sol.clear();
		printf("Case #%d\n", ++ks);
		if (!dfs(0,0)) puts("Impossible.");
		else {
			for (int i = 0; i < sol.size(); i++) printf("%d ", sol[i] + 1);
			putchar('\n');
		}
	}
}
