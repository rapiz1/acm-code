/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 19 Oct 2019 10:48:51 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		while (b >= 1 && c >= 2) {
			b -= 1, c -= 2;
			ans += 3;
		}
		while (a >= 1 && b >= 2) {
			a -= 1, b -= 2;
			ans += 3;
		}
		cout << ans << endl;
	}
}
