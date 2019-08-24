/** 
*  _____   _                 
* /__  /  (_)___  ____ ______
*   / /  / / __ \/ __ `/ ___/
*  / /__/ / /_/ / /_/ / /    
* /____/_/ .___/\__,_/_/     
*       /_/                  
* Tuesday, 20 August 2019
**/
#include "bits/stdc++.h"
using namespace std;
int n, m;
list<int> c;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    c.push_back(i);
  }
  auto it = c.begin();
  while (!c.empty()) {
    for (int i = 1; i < m; i++) {
      it++;
      if (it == c.end()) it = c.begin();
    }
    cout << *it << " ";
    it = c.erase(it);
    if (it == c.end()) it = c.begin();
  }
}
