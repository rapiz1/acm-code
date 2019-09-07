/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 07 Sep 2019 10:36:44 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
int n;
string s,t;
bool cir() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (j != i) for (int k = 0; k < 3; k++) {
        if (k != j && k != i) {
          string now = string(1, i + 'a') + string(1, j + 'a') + string(1, k + 'a');
          now += now;
          if (now.find(s) != string::npos || now.find(t) != string::npos) {
            continue;
          }
          else {
            now = string(1, i + 'a') + string(1, j + 'a') + string(1, k + 'a');
            string ans;
            for (int i = 1; i <= n; i++) ans += now;
            cout << "YES\n" << ans << endl;
            return true;
          }
        }
      }
    }
  }
  return false;
}
bool path() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (j != i) for (int k = 0; k < 3; k++) {
        if (k != j && k != i) {
          string now = string(1, i + 'a') + string(1, j + 'a') + string(1, k + 'a');
          if (now.find(s) == string::npos && now.find(t) == string::npos) {
            cout << "YES\n";
            string ans = string(n, i + 'a') + string(n, j + 'a') + string(n, k + 'a');
            cout << ans << endl;
            return true;
          }
        }
      }
    }
  }
  return false;
}
int main() {
  cin >> n;
  cin >> s >> t;
  if (cir()) {
  }
  else if (path()) {
  }
  else {
    cout << "NO\n";
  }
}

