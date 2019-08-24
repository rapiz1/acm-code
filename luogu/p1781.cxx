/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Sat, 24 Aug 2019 10:47:19 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
int n;
vector<string> a, b;
int main() {
  cin >> n;
  a.resize(n);
  for (auto& x: a) cin >> x;
  b = a;
  sort(a.begin(), a.end(), [](string& x, string& y) {
        if (x.size() != y.size()) return x.size() > y.size();
        else return x > y;
      });
  for (int i = 0; i < n; i++) if (b[i] == a[0]) {
    cout << (i+1) << endl;
    break;
  }
  cout << a[0];
}

