/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Thu, 19 Sep 2019 16:58:19 +0800
 */
#include <iostream>
#include <cstring>
#include <vector>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 310;
int n, m, dis[N][N];
void solve() {
  memset(dis, 0x3f, sizeof dis);
  for (int i = 1; i <= m; i++) {
    int t; cin >> t;
    vector<int> vec;
    vec.resize(t);
    for (int i = 0; i < (int)vec.size(); i++) {
      cin >> vec[i];
    }
    for (int p = 0; p < (int)vec.size(); p++)
      for (int q = 0; q < (int)vec.size(); q++)
        if (p != q) {
          dis[vec[p]][vec[q]] = 1;
        }
  }
  for (int i = 1; i <= n; i++) dis[i][i] = 0;
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    int s = 0;
    for (int j = 1; j <= n; j++) {
      s += dis[i][j];
    }
    ans = min(ans, s);
  }
  cout << ans*100/(n-1) << endl;
}
int main() {
  fastios;
  while (cin >> n >> m) {
    solve();
  }
}
