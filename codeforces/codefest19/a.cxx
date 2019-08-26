/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Mon, 26 Aug 2019 09:15:21 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
int main() {
  int t; 
  cin >> t;
  while (t--) {
    int n ,a , b;
    cin >> a >> b >> n;
    n%=3;
    int ans;
    switch(n) {
      case 0:  ans = a;break;
      case 1: ans = b;break;
      case 2: ans = a^b;break;
    }
    cout << ans << endl;
  }
}

