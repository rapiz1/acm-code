/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Sat, 24 Aug 2019 10:09:10 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
int n;
vector<int> v;
int main() {
  cin >> n;
  v.resize(n);
  for (auto& x: v) {
     cin >> x;
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  cout << v.size() << endl;
  for (auto& x: v) {
    cout << x << " ";
  }
}

