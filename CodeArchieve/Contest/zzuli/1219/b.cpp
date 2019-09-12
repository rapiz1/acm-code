#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	int d = abs(x1 - x2) + abs(y1 - y2);
	int tot = 0;
	if (n&1) {
		if ((n + 1)/2 < d) tot = 1;
		else {
			if (d&1) tot = 2;
			else tot = 1;
		}
	}
	else {
		if (n/2 < d) tot = 0;
		else {
			if (d&1) tot = 0;
			else tot = 1;
		}
	}
	if (tot <= 0) tot = -1;
	cout << tot;
}
int main() {
//	freopen("input", "r", stdin);
//	freopen("output", "w", stdout);
	int t; cin >> t;
	while (t--) {
		solve();
		if (t) cout << endl;
	}
}
