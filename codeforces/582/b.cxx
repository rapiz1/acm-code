/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Fri, 30 Aug 2019 22:39:28 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int N = 151000;
int n, a[N], mn[N];
int main() {
  fastios;
  int t; cin >> t;
  while (t--) {
  cin >> n;
    for (int i = 1; i <= n;i++) {
      cin >> a[i];
    }
    mn[n] = a[n];
    for (int i = n; i > 1; i--) {
      mn[i-1] = min(mn[i], a[i-1]);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] > mn[i+1]) {
        ans++;
      }
    }
    cout << ans << endl;
  }
}
