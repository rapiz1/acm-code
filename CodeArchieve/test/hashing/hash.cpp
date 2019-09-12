#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int L = 1e4, N = 1e6;
char s[L];
ll h[N];
int n;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		ll hv = 0;
		for (int j = 1; s[j]; j++) hv = hv*31 + s[j] - 'a' + 1;
		h[i] = hv;
	}
	std::sort(h + 1, h +1 + n);
	int ans = std::unique(h + 1, h + 1 +n) - (h + 1);
	ans = n - ans;
	printf("%d\n", ans);
}
