#include <cstdio>
#include <algorithm>
const int N = 35e4 + 10;
typedef long long ll;
int n, a[2][N], mx[2][N];
ll ans;
using std::max;
void solve(int l, int r) {
	for (int k = 0; k < 2; k++) for (int i = 1; i <= n; i++) mx[k][i] = 0;
	int mid = l + r >> 1;
	for (int k = 0; k < 2; k++) {
		for (int i = mid, x = 0; i >= l; i--) mx[k][i] = max(x, a[k][i]), x = max(x, a[k][i]);
		for (int i = mid, x = 0; i <= r; i++) mx[k][i] = max(x, a[k][i]), x = max(x, a[k][i]);
	}
	for (int i = l; i < mid; i++) {
		int x = std::uppper_bound(mx[1] + mid, mx[1] + r + 1, mx[0][i]) - (mx[1] + mid);
		ans += x;
	}
	solve(l, mid), solve(mid + 1, r);
}
int main() {
	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int k = 0; k < 2; k++)
		for (int i = 1; i <= n; i++) scanf("%d", &a[k][i]);
	printf("%lld\n", ans);
}
