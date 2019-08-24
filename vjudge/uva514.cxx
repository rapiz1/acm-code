/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 24 Aug 2019 08:40:20 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
int n;
vector<int> p;
stack<int> sk;
bool solve() {
  while (!sk.empty()) sk.pop();
  for (auto& x: p) {
    cin >> x;
    //xxx(x);
    if (!x) return 0;
  }
  int i = 1;
  bool can = 1;
  for (auto x: p) {
    while (i <= n && !(!sk.empty() && sk.top() == x)) {
      sk.push(i++);
    }
    if (!sk.empty() && sk.top() == x) {
      sk.pop();
    }
    else {
      can = 0;
      break;
    }
  }
  cout << (can ? "Yes" : "No") << endl;
  return 1;
}
int main() {
  while (cin >> n) {
    if (!n) break;
    p.clear();p.resize(n);
    while (solve()) ;
    cout << endl;
  }
  cout << endl;
}

