#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1e5 + 10;
typedef long long ll;
int n, a, b, h[N];
ll mid;
bool check() {
	ll co = 0;
	for (int i = 1; i <= n; i++) co += std::max((h[i] - mid*b + (a - b - 1))/(a - b), 0ll);
	return co <= mid;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d%d", &n, &a, &b);
	ll l = 0, r = 0;
	for (int i = 1; i <= n; i++) scanf("%d", h + i), r += (h[i] + a - 1)/a;
	while (l < r) {
		mid = (l + r) >> 1;
		if (check()) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", l);
}
