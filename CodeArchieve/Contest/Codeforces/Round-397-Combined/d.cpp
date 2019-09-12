#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int n, f[N], g[N], h[N], m;
std::vector<int> val[N];
bool done[N];
int main() {
//	freopen("input", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> f[i], val[f[i]].push_back(i);
	for (int i = 1; i <= n; i++) if (f[i] == i) {
		++m;
		h[m] = f[i];
	}
	for (int i = 1; i <= m; i++) g[h[i]] = i;
	for (int i = 1; i <= n; i++) if (g[i]) {
		if (done[f[i]]) continue;
		for (int j = 0; j < val[f[i]].size(); j++) 
			g[val[f[i]][j]] = g[i];
		done[f[i]] = 1;
	}
	bool f = 1;
	for (int i = 1; i <= n; i++) if (!g[i]) f = 0;
	if (!m || !f) {
		puts("-1");
		return 0;
	}
	printf("%d\n", m);
	for (int i = 1; i <= n; i++) printf("%d ", g[i]);
	putchar('\n');
	for (int i = 1; i <= m; i++) printf("%d ", h[i]);
}
