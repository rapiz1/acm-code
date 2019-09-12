#include <bits/stdc++.h>
using namespace std;
const int N = 30;
typedef long long ll;
int n;
ll c[N], p[N], l[N], ss;
ll mod(ll x, ll y) {
	if (x > 0) return x%y;
	else return x + (-x + y - 1)/y*y;
}
void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a%b, d, y, x), y -= a/b*x;
}
inline bool check(ll m) {
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
		ll x, y, d, a = p[i] - p[j], z = c[j] - c[i];
		if (a < 0) a = -a, z = -z;
		exgcd(a, m, d, x, y);
		if (z%d) continue;
		x = mod(z/d*x, m/d);
		if (x <= min(l[i], l[j])) return 0;
	}
	return 1;
}
int main() {
//	freopen("input", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i] >> p[i] >> l[i], ss = max(ss, c[i]--);
	for (int i = ss; i <= int(1e6) ;i++) if (check(i)) {
		printf("%d\n", i);
		break;
	}
}
