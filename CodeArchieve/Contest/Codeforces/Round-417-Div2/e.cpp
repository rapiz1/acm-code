#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
typedef long long ll;
const int N = 1e5 + 10;
int n, a[N], fa[N], dep[N], nim;
bool lf[N];
ll ans;
std::vector<int> to[N], x, y;
std::queue<int> q;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	memset(lf, 1, sizeof lf);
	for (int i = 2; i <= n; i++) scanf("%d", fa + i), lf[fa[i]] = 0;
	for (int i = 1; i <= n; i++) if (lf[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (!dep[fa[u]]) dep[fa[u]] = dep[u] + 1, q.push(fa[u]);
	}
	for (int i = 1; i <= n; i++) {
		if (dep[i]%2 == 0) x.push_back(a[i]), nim ^= a[i];
		else y.push_back(a[i]);
	}
	std::sort(y.begin(), y.end());
	if (!nim) {
		ans += (ll)y.size()*(y.size() - 1)/2;
		ans += (ll)x.size()*(x.size() - 1)/2;
	}
	for (int i = 0; i <(int)x.size(); i++) {
		int now = nim^x[i];
		ans += std::upper_bound(y.begin(), y.end(), now) - std::lower_bound(y.begin(), y.end(), now);
	}
	printf("%I64d", ans);
}
