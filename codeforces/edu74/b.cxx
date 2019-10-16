/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Wed, 16 Oct 2019 11:05:36 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
int n, r;
ll x[N];
int main() {
	fastios;
	int t; cin >> t;
	while (t--) {
		cin >> n >> r;
		for (int i = 1; i <= n; i++) cin >> x[i];
		sort(x + 1, x + 1 + n);
		n = unique(x + 1, x + 1 + n) - (x + 1);
		ll delta = 0;
		int ans = 0;
		for (int i = n; i; i--) {
			if (x[i] - delta <= 0) continue;
			else {
				ans++;
				delta += r;
			}
		}
		cout << ans << endl;
	}
}

