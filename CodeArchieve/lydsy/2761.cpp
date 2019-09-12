#include <cstdio>
#include <vector>
const int N = 5e4 + 10, M = 1e5 + 3;
int n;
std::vector<int> a[M];
inline int adj(int x) {return x < 0 ? x + (-x + M - 1)/M*M : x%M;}
void solve() {
	for (int i = 0; i < M; i++) a[i].clear();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		int y = adj(x);
		bool vaild = 1;
		for (int j = 0; j < (int)a[y].size(); j++) if (a[y][j] == x) {vaild=0;break;}
		if (!vaild) continue;
		else a[y].push_back(x);
		if (i != 1) putchar(' ');
		printf("%d", x);
	}
	putchar('\n');
}
int main() {
	int t; scanf("%d", &t);
	while (t--)solve();
}
