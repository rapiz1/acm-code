/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Wed, 16 Oct 2019 11:24:07 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
int n, h, p[N];
int main() {
	fastios;
	int q;
	cin >> q ;
	while (q--){
		cin >> h >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
		}
		int ans = 0;
		p[n+1] = 0;
		for (int i = 2; i <= n; i++) {
			if (p[i+1] == p[i]-1) {
				i++;
				continue;
			}
			else {
				ans++;
			}
		}
		cout << ans << endl;
	}
}

