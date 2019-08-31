/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Fri, 30 Aug 2019 22:43:44 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int N = 11;
ll a[N];
ll n, m;
int main() {
  fastios;
  int q; cin >> q;
  while (q--) {
    cin >> n >> m;
    ll len = -1, s = 0;
    for (int i = 1; i <= 10; i++) {
      a[i] = i*m%10;
      for (int j = 1; j < i; j++) {
        if (a[i] == a[j]) {
          len = i - j;
          break;
        }
      }
      if (len != -1) {
        break;
      }
    } 
    if (len == -1) {
      len = 10;
    }
    for (int i = 1; i <= len; i++) s += a[i];
    ll ans = n/m/len*s;
    ll d = n/m%len;
    for (int i = 1; i <= d; i++){
      ans += a[i];
    }
    cout << ans << endl;
  }
}

