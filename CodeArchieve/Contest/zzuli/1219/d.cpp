#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100, M = 10007;
ll ans, f[N];
void solve() {
	ans = 1;
	int n; cin >> n;
	for (int i = 1, x; i < n; i++) cin >> x, ans = ans*f[x]%M;
	cout << ans << endl;
}
int main() {
//	freopen("input", "r", stdin);
	int t; cin >> t;
	f[0] = 1;
	for (int i = 1; i < 100; i++) {
		for (int j = 1; j <= 3; j++) if (i - j >= 0) f[i] = (f[i] + f[i - j])%M;
	}
	while (t--) solve();
}
