/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Mon, 16 Sep 2019 10:32:51 +0800
 */
#include <iostream>
#include <algorithm>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 1010;
int n, k, a[N], b[N];
double c[N];
inline bool check(double x) {
  for (int i = 1; i <= n; i++) c[i] = a[i] - b[i]*x;
  sort(c + 1, c + 1 + n);
  double s = 0;
  for (int i = k + 1; i <= n; i++) {
    s += c[i];
  }
  return s >= 0;
}
void solve() {
  for (int i = 1; i <= n; i++)cin >> a[i];
  for (int i = 1; i <= n; i++)cin >> b[i];
  double l = 0, r = 1;
  for (int T = 20; T; T--) {
    double mid = (l + r)/2;
    if (check(mid)) l = mid;
    else r = mid;
  }
  r *= 100;
  cout << int(r + 0.5) << endl;
}
int main() {
  fastios;
  while (cin >> n >> k) {
    if (n == 0 && k == 0) break;
    solve();
  }
}

