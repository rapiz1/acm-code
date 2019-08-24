/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Sat, 24 Aug 2019 21:15:02 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const ll MOD = 1e9 + 7;
const int N = (1e5 + 10)*2;
string s;
int a[N], n, c[N][2];
// 0 left, 1 right
int main() {
  cin >> n >> s;
  if (s[0] == 'W' || s[(int)s.size()-1] == 'W') {
    cout << 0 << endl;
    return 0;
  }
  s = 'X' + s;
  a[1] = 0;
  for (int i = 2; i <= 2*n; i++) {
    if (s[i] == s[i-1]) {
      a[i] = a[i-1]^1;
    }
    else {
      a[i] = a[i-1];
    }
  }
  for (int i = 1; i <= 2*n; i++){
    c[i][0] = c[i-1][0];
    c[i][1] = c[i-1][1];
    c[i][a[i]]++;
  }
  if (c[2*n][0] != c[2*n][1]) {
    cout << 0 << endl;
    return 0;
  }
  ll cnt = 1;
  for (int i = 2; i <= 2*n ;i++ ){
    if (a[i] == 1) {
      cnt*= c[i-1][0] - c[i-1][1];
      cnt %= MOD;
    }
  }
  ll fac = 1;
  for (int i = 1; i <= n; i++) {
    fac = (fac*i)%MOD;
  }
  cout << (cnt*fac)%MOD;
}
