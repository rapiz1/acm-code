#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const ll M = 19930726;
const int N = 2e6 + 10;
int n, f[N];
ll cc[N], k, ans = 1;
char s[N];
ll qpow(ll x, ll r) {
	ll ret = 1;
	x%=M;
	while (r) {
		if (r&1) ret = ret*x%M;
		r>>=1, x=x*x%M;
	}
	return ret;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%lld%s", &n, &k, s + 1);
	s[n + 1] = '$';
	for (int i = 1, mx = 0, p = 0; i <= n; i++) {
		if (mx > i) f[i] = std::min(f[p*2 - i], mx - i);
		for (;s[i + f[i]] == s[i - f[i]]; f[i]++);
		if (i + f[i] > mx) mx = i + f[i], p = i;
		cc[f[i]]++;
	}
	for (int i = n; i && k; i--) {
		cc[i] += cc[i + 1];
		ans = ans*qpow(2*i - 1, std::min(k, cc[i]))%M;
		k -= std::min(k, cc[i]);
	}
	printf("%lld\n", ans);
}
