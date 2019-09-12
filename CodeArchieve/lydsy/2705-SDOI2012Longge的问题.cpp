#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int phi(int x) {
	if (x == 1) return 1;
	int ret = x;
	for (ll i = 2; i*i <= x; i++) if (x%i == 0) {
		ret = ret/i*(i - 1);
		while (x%i == 0) x/=i;
	}
	if (x > 1) ret = ret/x*(x - 1);
	return ret;
}
int n;
ll ans = 0;
int main() {
	cin >> n;
	for (ll i = 1; i*i <= n; i++) if (n%i == 0) {
		ans += i*phi(n/i);
		if (n/i != i) ans += n/i*phi(i);
	}
	cout << ans;
}
