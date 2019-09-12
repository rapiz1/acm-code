#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>
typedef long long ll;
using std::min;
const int N = 2e5 + 50, K = 20, H = 21;
int n, m, k, h[N];
std::vector<int> e[H], key[N];
ll ans;
void solve(int l, int r) {
	if (l == r) {
		for (int i = 0; i < (int)key[l].size(); i++)
			for (int j = i + 1; j < (int)key[l].size(); j++)
				ans += abs(key[l][j] - key[l][i]) <= k;
		return;
	}
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);
	for (int i = 1; i < H; i++) e[i].clear();
	for (int i = mid, x = h[mid]; i >= l; i--) {
		x = min(x, h[i]);
		for (int j = 0; j < (int)key[i].size(); j++) {
			e[min(key[i][j], x)].push_back(key[i][j] - i);
		}
	}
	for (int i = 1; i < H; i++) std::sort(e[i].begin(), e[i].end());
	for (int i = mid + 1, x = h[mid + 1]; i <= r; i++) {
		x = min(x, h[i]);
		for (int j = 0; j < (int)key[i].size(); j++) {
			int hh = min(x, key[i][j]);
			for (int k = 1; k < H; k++) {
				ans += std::upper_bound(e[k].begin(), e[k].end(), ::k - i - key[i][j] + 2*min(k, hh)) - e[k].begin();
			}
		}
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", h + i);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		key[x].push_back(y);
	}
	solve(1, n);
	printf("%lld\n", ans);
}
