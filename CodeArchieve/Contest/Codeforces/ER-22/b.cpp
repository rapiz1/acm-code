#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
ll x, y, l, r, ans;
vector<ll> un;
int main() {
//	freopen("input", "r", stdin);
	cin >> x >> y >> l >> r;
	un.push_back(l - 1);
	un.push_back(r + 1);
	for (ll xx = 1;1;) {
		for (ll yy = 1; 1;) {
			if (0.0 + xx + yy > r) break;
			if (xx + yy >= l) un.push_back(xx + yy);
			if (1.0*yy*y <= r) yy *= y;
			else break;
		}
		if (1.0*xx*x <= r) xx *= x;
		else break;
	}
	sort(un.begin(), un.end());
	int s = unique(un.begin(), un.end()) - un.begin();
	for (int i = 1; i < s; i++) {
		ans = max(ans, un[i] - un[i - 1] - 1);
	}
	cout << ans;
}
