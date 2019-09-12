#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
const int N = 2e5 + 10;
typedef std::pair<int, int> In;
int n, k;
In a[N];
std::vector<std::vector<int> > ans;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	ans.resize(2*n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].first, &a[i].second);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (a[j].first < a[i].first + 0.5 && a[i].first + 0.5 < a[j].second) 
				ans[2*(i - 1)].push_back(j);
		for (int j = 1; j <= n; j++)
			if (a[j].first < a[i].second + 0.5 && a[i].second + 0.5 < a[j].second) 
				ans[2*(i - 1) + 1].push_back(j);
	}
	std::sort(ans.begin(), ans.end());
	n = std::unique(ans.begin(), ans.end()) - ans.begin();
//	for (int i = 0; i < n; i++, puts(""))  for (int j = 0; j < (int)ans[i].size(); j++) printf("%d ", ans[i][j]);
	if (ans[0].size()) k--;
	printf("%d\n", (int)ans[k].size());
	for (int i = 0; i < (int)ans[k].size(); i++) printf("%d ", ans[k][i]);
}
