/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 19 Oct 2019 11:00:14 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const ll M = 1e9 + 7;
ll n, m;
ll qpow(ll x, ll r) {
	x %= M;
	ll ret = 1;
	for (ll f = x;r;r>>=1) {
		if (r&1) ret  = (ret*f)%M;
		f = f*f%M;
	}
	return ret;
}
int main() {
	cin >> n >> m;
	cout << qpow((qpow(2, m) - 1 + M)%M, n);
}

