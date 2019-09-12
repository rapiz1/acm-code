#include <iostream>
using namespace std;
typedef long long ll;
const ll M = 100003;
ll qpow(ll x, ll r) {
	ll s = 1;
	while (r) {
		if (r&1) s = s*x%M;
		r >>= 1, x = x*x%M;
	}
	return s;
}
int main() {
	ll n, m;
	cin >> m >> n;
	cout << (qpow(m, n) - m*qpow(m-1, n-1)%M + M)%M;
}
