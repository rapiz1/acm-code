#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 5e5 + 10;
int n;
std::vector<int> a[2];
int sol(int p) {
	int x = a[p][0], i[2] = {}, r = 1;
	i[p]++;
	p ^= 1;
	for (; i[p] < a[p].size();) {
		if (a[p][i[p]] > x) r++, x = a[p][i[p]++], p ^= 1;
		else i[p]++;
	}
	return r;
}
int main() {
//	freopen("input", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		a[0].clear();
		a[1].clear();
		for (int i = 1; i <= n; i++) {
			int t;
			scanf("%d", &t);
			if (t > 0) a[0].push_back(t);
			else a[1].push_back(-t);
		}
		std::sort(a[0].begin(), a[0].end());
		std::sort(a[1].begin(), a[1].end());
		printf("%d\n", std::max(sol(0), sol(1)));
	}
}
