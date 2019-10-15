/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Tue, 15 Oct 2019 20:18:43 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
int main() {
	fastios;
	int t; cin >> t;
	while (t--) {
		int n; string a, b;
		cin >> n >> a;
		int ans = n;
		for (int i = 0; i < (int)a.size(); i++) {
			if (a[i] == '1') {
				ans = max(ans, 2*max(i + 1, n - i));
			}
		}
		cout << ans << endl;
	}
}

