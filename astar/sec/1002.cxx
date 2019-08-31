/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 31 Aug 2019 19:24:10 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl
#define fastios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int K = 63;
ll a, b, c, d;
inline int get(ll x, int k) {
  return (x >> k) &1;
}
inline int sgn(ll x) {
  if (x > 0) return 1;
  else if (x == 0) return 0;
  else return -1;
}
void solve() {
  cin >> a >> b >> c >> d;
  ll delta = b - a;
  if (a == c && b == d) {
    cout << "Yes\n" << endl;
    return;
  }
  ll da = c - a, db = d - b;
  if (!((sgn(delta) == -sgn(da) || !sgn(da)) && (sgn(delta) == sgn(db) || !sgn(db)))) {
    cout << "No" << endl;
    return;
  } 
  delta = abs(delta);
  da = abs(da), db = abs(db);
  if (da % delta || db % delta) {
    cout << "No" << endl;
    return;
  }
  da /= delta, db /= delta;
  da = abs(da), db = abs(db);
  if (da & db) {
    cout << "No" << endl;
    return;
  }
  bool flag = 0;
  for (int i = K; i >= 0; i--) {
    if (get(da, i)) flag=1;
    else if (get(db, i)) flag=1;
    else if (flag) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  for (int i = 0; get(da, i) || get(db, i); i++) {
    if (get(da, i)) cout << "B";
    else if (get(db, i)) cout << "A";
  }
  cout << endl;
  return;
}
int main() {
  fastios;
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}

