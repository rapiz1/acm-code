/**
*     ____              _    
*    / __ \____ _____  (_)___
*   / /_/ / __ `/ __ \/ /_  /
*  / _, _/ /_/ / /_/ / / / /_
* /_/ |_|\__,_/ .___/_/ /___/
*            /_/             
*           code@rapiz.me
*          Tue, 20 Aug 2019 21:39:09 +0800
*/
#include <bits/stdc++.h>
#define DBG(x) cerr<<(#x)<<": "<<x<<endl;
using namespace std;
int n, m;
set<int> a, b;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a.insert(x);
  }
  cin >> m;
  for (int i = 1; i <= m;i++) {
    int x;
    cin>>x;
    b.insert(x);
  }
  for (auto x:a) {
      for (auto y: b) {
        int z = x+ y;
        if (a.count(z) + b.count(z) == 0) {
          cout << x << " "<< y;
          return 0;
        }
      }
  }
}

