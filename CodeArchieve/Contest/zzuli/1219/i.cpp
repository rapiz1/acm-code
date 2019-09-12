#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	long long lb = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] - 1<= lb) lb += a[i];
	}
	cout << lb << endl;
}
int main() {
//	freopen("input", "r", stdin);
	int t; cin >> t;
	while (t--) solve();
}
