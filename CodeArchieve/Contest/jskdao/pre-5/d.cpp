#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <vector>
const int N = 5e4 + 10, M = 1e5 + 10;
typedef unsigned long long ull;
typedef std::pair<int, ull> pa;
int n, m, ans[M];
ull val[N], s[N], t[N];
std::vector<pa> qu[N];
std::vector<ull> st;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), s[i] = x;
	for (int i = 1; i <= n; i++) val[i] = (ull)rand()*rand();
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + val[s[i]];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){ 
		int k; scanf("%d", &k);
		for (int i = 1, x; i <= k; i++) scanf("%d", &x), t[i] = t[i - 1] + val[x];
		qu[k].push_back(pa(i, t[k]));
	}
	for (int i = 1; i <= n; i++) if (!qu[i].empty()) {
		st.clear();
		for (int j = i; j <= n; j++) st.push_back(s[j] - s[j - i]);
		std::sort(st.begin(), st.end());
		for (int j = 0; j < (int)qu[i].size(); j++) 
			ans[qu[i][j].first] = std::upper_bound(st.begin(), st.end(), qu[i][j].second) 
			                      - std::lower_bound(st.begin(), st.end(), qu[i][j].second);
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
