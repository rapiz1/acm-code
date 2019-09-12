#include <cstdio>
#include <algorithm>
const int N = 11;
typedef long long ull;
int n, pri[N], val[N];
ull ret = 0;
void exgcd(int a, int b, ull& d, ull& x, ull& y) {
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a%b, d, y, x), y -= x*(a/b);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	ull M = 1;
	for (int i = 1; i <= n; i++) scanf("%d%d", pri + i, val + i), M *= pri[i];
	for (int i = 1; i <= n; i++) {
		ull d, x, y, w = M/pri[i];
		exgcd(w, pri[i], d, x, y);
		ret = (ret + val[i]*x%pri[i]*w + M)%M;
	}
	printf("%lld", ret);
}
