/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 24 Aug 2019 20:26:01 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
int M, D;
int main() {
  cin >> M >> D;
  int cnt = 0;
  for (int m = 1; m <= M; m++) {
    for (int d = 1; d <= D; d++) {
      int ten = d/10, one = d%10;
      if (one >= 2 && ten >= 2 && one*ten == m) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}

