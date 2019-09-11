/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Wed, 11 Sep 2019 09:34:53 +0800
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 1010;
int r, n, a[N];
void solve() {
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int ans = 0;
  for (int i = 1, j=0; i <= n; i++) {
    if (j && abs(a[j] - a[i]) <= r) continue;
    for (j = i; j <= n; j++) {
      if (a[j] - a[i] <= r) continue;
      else break;
    }
    j--;
    ans++;
  }
  cout << ans << endl;
}
int main() {
  while (cin >> r >> n) {
    if (r == -1 && n == -1) 
      break;
    solve();
  }
}

