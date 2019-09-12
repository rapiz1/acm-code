#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m;
ll ans = 1e16;
void work() {
	if (m > 1) for (int i = 1; i < n; i++) {
		ll a = i*m, b = m/2*(n - i), c = n*m - a - b;
		ans = min(ans, max(a, max(b, c)) - min(a, min(b, c)));
	}
	for (int i = 1; i <= n - 2; i++) {
		ll a =  i*m, b = (n - i)/2*m, c = n*m - a - b;
		ans = min(ans, max(a, max(b, c)) - min(a, min(b, c)));
	}
}
int main() {
//	freopen("input", "r", stdin);
	cin >> n >> m;
	work();
	std::swap(n, m);
	work();
	cout << ans;
}
