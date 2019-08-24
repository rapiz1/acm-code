/**
*     ____              _    
*    / __ \____ _____  (_)___
*   / /_/ / __ `/ __ \/ /_  /
*  / _, _/ /_/ / /_/ / / / /_
* /_/ |_|\__,_/ .___/_/ /___/
*            /_/             
*           code@rapiz.me
*          Thu, 22 Aug 2019 19:42:00 +0800
*/
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
string s;
int l;
int main() {
  while (getline(cin, s)) {
    string ss;
    for (auto ch: s) {
      if (ch == '\"') {
        ss += l ? "''" : "``";
        l^=1;
      }
      else {
        ss += ch;
      }
    }
    cout << ss << endl;
  }
}

