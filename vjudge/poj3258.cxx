/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Mon, 16 Sep 2019 09:49:21 +0800
 */
#include <iostream>
#include <algorithm>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 5e4 + 10;
int len, n, m, a[N];
inline bool check(int x) {
  int cnt = 0;
  for (int i = 1, lp = 0; i <= n; i++) {
    if (a[i] - lp < x) {
      cnt++;
    }
    else {
      lp = a[i];
    }
  }
  //xxx(x);
  //xxx(cnt);
  return cnt <= m;
}
int main() {
  cin >> len >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int l = 1, r = len;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }
  cout << l << endl;
}

