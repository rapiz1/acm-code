#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 1e3 + 10, K = 70;
int n;
ll r[K], ans;
struct ST{ll n; int w;
	bool operator<(const ST& b)const {return w > b.w;}
}st[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%d", &st[i].n, &st[i].w);
	std::sort(st + 1 ,st + 1 + n);
	for (int i = 1; i <= n; i++) {
		ll x = st[i].n;
		for (int j = 61; ~j; j--) if (x>>j&1)
			if (r[j]) x^=r[j];
			else {
				r[j] = x, ans += st[i].w;
				break;
			}
	}
	printf("%lld", ans);
}
