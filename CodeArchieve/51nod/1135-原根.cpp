#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p;
ll qpow(ll x, ll r, ll m) {
	if (!x) return 0;
	ll ret = 1;
	for (x%=m; r;r>>=1, x=x*x%m) if (r&1) ret = ret*x%m;
	return ret;
}
bool check(int a) {
	int phi = p - 1;
	ll i, x;
	for (i = 2, x = phi; i*i <= x; i++) if (x%i == 0) {
		if (qpow(a, phi/i, p) == 1) return 0;
		for (;x%i==0;x/=i);
	}
	if (x > 1 && qpow(a, phi/x, p) == 1) return 0;
	return 1;
}
int main() {
	cin >> p;
	for (int i = 2; i < p; i++) if (check(i)) {
		printf("%d", i);
		break;
	}
}
