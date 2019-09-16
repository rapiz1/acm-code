/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Mon, 16 Sep 2019 10:16:13 +0800
 */
#include <iostream>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N];
inline bool check(int x) {
  int cnt = 1;
  for (int i = 1, s = 0; i <= n; i++) {
    if (s + a[i] <= x) {
      s += a[i];
    }
    else {
      s = a[i];
      cnt++;
    }
  }
  return cnt <= m;
}
void solve() {
  int l = 1, r = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], r += a[i], l =max(l, a[i]);
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  cout << l << endl;
}
int main() {
  fastios;
  while (cin >> n >> m) {
    solve();
  }
}

