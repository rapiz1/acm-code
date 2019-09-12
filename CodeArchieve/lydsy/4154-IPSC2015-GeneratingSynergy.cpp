#include <cstdio>
#include <cstring>
#include <vector>
const int N = 1e5 + 10;
int n, c, m, clk, a[N];
std::vector<int> ch[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &c, &m);
		for (int i = 1; i <= n; i++) ch[i].clear();
		for (int i = 2; i <= n; i++) {
			int fa;
			scanf("%d", &fa);
			ch[fa].push_back(i);
		}
	}
}
