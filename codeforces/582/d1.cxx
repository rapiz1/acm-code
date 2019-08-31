/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Fri, 30 Aug 2019 22:55:18 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int N = 60;
int n, k, a[N],ans = 1e9;
map<int, vector<int> > st; 
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int c, x;
    for (c = 0, x = a[i]; x; x/=2, c++) {
      st[x].push_back(c);
    }
    st[0].push_back(c);
  }
  for (auto& x : st) {
    auto& v = x.second;
    if ((int)v.size() >= k) {
      sort(v.begin(), v.end());
      int now = 0;
      for (int i = 0; i < k; i++) {
        now += v[i];
      }
      ans = min(ans, now);
    }
  }
  cout << ans << endl;
}

