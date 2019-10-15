/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Tue, 15 Oct 2019 19:58:02 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c, d, k; cin >>a >> b >> c >> d >> k;
		int p = ceil((double)a/c), q = ceil((double)b/d);
		if (p + q <= k ) {
			cout << p << " " << q << endl;
		}
		else cout << -1 << endl;
	}
}

