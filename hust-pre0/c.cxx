/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 21 Sep 2019 21:25:04 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
int n, a[N];
int main() {
  fastios;
  cin >> n;
  for (int i =1; i <= n; i++) cin >>  a[i];
  sort(a + 1, a +1 + n);
  ll now = 0;
  for (int i = 1; i <= n; i++) {
    //xxx(now);
    if (a[i] <= now + 1) {
      now = now + a[i];
    }
    else {
      cout << (now + 1) << endl;
      return 0;
    }
  }
  cout << now + 1;
}
