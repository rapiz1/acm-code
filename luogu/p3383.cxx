/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Mon, 09 Sep 2019 22:22:26 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 10000000 + 10;
int n, m;
bool vis[N];
vector<int> pri;
int main() {
  fastios;
  cin >> n >> m;
  vis[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pri.push_back(i);
    for (auto x:pri) {
      ll v = (ll)x*i;
      if (v > n) break;
      vis[v] = 1;
      if (i%x == 0) break;
    }
  }
  while (m--) {
    int x; cin >> x;
    cout << (vis[x] ? "No" : "Yes") << endl;
  }
}
