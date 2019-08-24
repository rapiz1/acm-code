/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Tue, 20 Aug 2019 22:34:26 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
string s;
int main() {
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (i%2 == 0) ans++;
  }
  if ((s.size() -1)%2 == 0) {
    bool flag = 1;
    if (s[0] == '1') {
      for (int i = 1; i < s.size(); i++) {
        if (s[i] != '0') flag = 0;
      }
    }
    ans -= flag;

  }
  cout << ans;
}

