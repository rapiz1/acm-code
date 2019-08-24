/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Thu, 22 Aug 2019 23:05:26 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
int n;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll a, b, f[2][4];
string s;
void solve() {
  memset(f, 0x3f, sizeof f);
  cin >> n >> a >> b;
  cin >> s;
//  s = 'x' + s;
//  cout << s << endl << endl;
  f[0][1] = b;
  for (int i = 1; i <= n; i++) {
    int k = i&1;
    if ((i== n || s[i] == '0') && s[i-1] == '0') {
      f[k][1] = min(f[k^1][1], f[k^1][2] + a) + a + b;
    }
    else f[k][1] = INF;
    f[k][2] = min(f[k^1][1] + a, f[k^1][2]) + a + 2*b;
//    printf("f[%d][%d]:%lld\n", i, 1, f[k][1]);
//    printf("f[%d][%d]:%lld\n", i, 2, f[k][2]);
  }
  cout << f[n&1][1] << endl;
}
int main() {
  int ks; cin >> ks;
  while (ks--) {
    solve();
  }
}

