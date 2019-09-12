#include <cstdio>
#include <vector>
#include <utility>
const int W = 1e6 + 10, N = 5e4 + 10, M = 2e5 + 10;
int n, m, a[N], b[N], prev[W], ans[M];
typedef std::pair<int, int> pa;
std::vector<pa> qu[N];
void add(int p, int v) {for (;p<=n;p+=p&-p) b[p] += v;}
int sum(int p) {
	int ret = 0;
	for (;p;p-=p&-p) ret += b[p];
	return ret;
}
int sum(int l, int r) {return sum(r) - sum(l - 1);}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), a[i]++;
	scanf("%d", &m);
	for (int i = 1, l, r; i <= m; i++) scanf("%d%d", &l, &r), qu[r].push_back(std::make_pair(l, i));
	for (int i = 1; i <= n; i++) {
		if (prev[a[i]]) add(prev[a[i]], -1);
		add(i, 1);
		for (int j = 0; j < (int)qu[i].size(); j++) ans[qu[i][j].second] = sum(qu[i][j].first, i);
		prev[a[i]] = i;
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
