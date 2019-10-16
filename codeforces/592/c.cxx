/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Tue, 15 Oct 2019 22:20:11 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
int main() {
	ll n, p, d, w;
	cin >> n >> p >> w >> d;
	for (int y = 0; y < w; y++) {
		if ((p - y*d)%w == 0) {
			ll x = (p - y*d)/w;
			if (x >= 0 && x + y <= n) {
				cout << x << " " << y << " " << (n - x - y) << endl;
				return 0;
			}
		}
	}
	cout << -1;
}

