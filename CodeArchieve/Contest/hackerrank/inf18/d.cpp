#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, c, d;
int main() {
	freopen("input", "r", stdin);
	int q; cin >> q;
	while (q--) {
		int ans = 0;
		cin >> a >> b >> c >> d;
		for (ll x = 1; x <= c; x++) {
			ll c = x*x - x*a, de = b*b - 4*c;
			if (de >= 0 && floor(sqrt(de)) == sqrt(de)) {
				if (de) {
					de = sqrt(de);
					ll x = b + de;
					if (x%2 == 0) x/= 2, ans += x <= d && x >= 1;
					x = b - de;
					if (x%2 == 0) x/= 2, ans += x <= d && x >= 1;
				}
				else {
					if (b%2 == 0) ans += b/2 <= d && b/2 >= 1;
				}
			}
		}
		cout << ans << endl;
	}
}
