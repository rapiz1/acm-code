/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Thu, 22 Aug 2019 22:35:12 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
int b, p, f, h, c;
void solve() {
  cin >> b >> p >> f >> h >> c;
  if (h < c) {
    swap(h, c);
    swap(p, f);
  }
  int ham = min(b/2, p);
  b -= 2*ham;
  int chi = min(b/2, f);
  cout << ham*h + chi*c << endl; 
}
int main() {
  int ks; cin >> ks;
  while (ks--) {
    solve();
  }
}

