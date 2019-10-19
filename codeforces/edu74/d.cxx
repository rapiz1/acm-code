/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 19 Oct 2019 10:23:13 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 3e5 + 10;
ll n;
ll ans;
char s[N];
int main() {
	cin >> n >> (s+1);
	for (int i = 1, j; i <= n; i = j) {
		j = i;
		int cnt = 0;
		while (j <= n && s[j] == s[i]) cnt++, j++;
		if (j <= n) {
			ans += cnt;
		}
		if (i > 1) {
			ans += cnt-1;
		}
	}
	cout << n*(n+1)/2 - n - ans << endl;
}

