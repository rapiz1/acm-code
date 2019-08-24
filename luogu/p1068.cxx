/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Sat, 24 Aug 2019 10:13:29 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int N = 5e3 + 10;
struct Peo {
  int id, s;
}p[N];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].id >> p[i].s;
  }
  sort(p+1,p+1+n, [](Peo& x, Peo& y)->bool{
      if (x.s == y.s) return x.id < y.id;
      else return x.s > y.s;
      });
  m = m*1.5;
  m = min(m, n);
  int sz = upper_bound(p+1,p+1+n, p[m].s, [](int x, Peo& y)->bool{return x > y.s;}) - (p+1);
  cout << p[m].s << " " << sz << endl;
  for (int i = 1; i <= sz; i++) cout << p[i].id << " " << p[i].s << endl;
}
