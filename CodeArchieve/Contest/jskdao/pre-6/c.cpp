#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
typedef long long ll;
using std::min;
typedef std::pair<int, int> pa;
const int N = 2e5 + 50, K = 20;
int n, m, k, h[N], mn[N][K];
pa key[N];
ll ans;
int mm(int l, int r) {
	int n = r - l + 1, d = 0;
	while ((1 << (d + 1)) <= n) d++;
	return std::min(mn[l][d], mn[r - (1 << d) + 1][d]);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", h + i), mn[i][0] = h[i];
	for (int k = 1; k < K; k++) for (int i = 1; i + (1 << k) - 1 <= n; i++)
		mn[i][k] = std::min(mn[i][k - 1], mn[i + (1 << (k - 1))][k - 1]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &key[i].first, &key[i].second);
		for (int j = 1; j  < i; j++) {
			pa x = key[i], y = key[j];
			if (x.first > y.first) std::swap(x, y);
			int t = x.second + y.second - 2*min(mm(x.first, y.first), min(x.second, y.second)) + y.first - x.first;
			ans += t <= k;
		}
	}
	printf("%lld\n", ans);
}
