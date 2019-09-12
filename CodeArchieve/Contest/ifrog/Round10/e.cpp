#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
typedef long long ll;
const int N = 2400, L = 10;
std::set<ll> res;
std::vector<ll> fac, ans;
void gen(int p, ll now) {
	if (p > L) return;
	if (now) fac.push_back(now);
	gen(p + 1, now*10 + 1);
	gen(p + 1, now*10 + 6);
}
void mult(int p, ll now) {
	if (now > 1e10 || p == (int)fac.size()) return;
	res.insert(now);
	if (fac[p] && fac[p] != 1) if (double(now)*fac[p] <= 1e10) mult(p, now*fac[p]), mult(p + 1, now*fac[p]);
	if (double(now)*fac[p] <= 1e10) mult(p + 1, now);
}
int main() {
	gen(0, 0);
	std::sort(fac.begin(), fac.end());
	mult(0, 1);
	for (std::set<ll>::iterator it = res.begin(); it != res.end(); it++) {
		ans.push_back(*it);
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		int c = upper_bound(ans.begin(), ans.end(), r) - lower_bound(ans.begin(), ans.end(), l);
		printf("%d\n", c);
	}
}
