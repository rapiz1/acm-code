/**
*     ____              _    
*    / __ \____ _____  (_)___
*   / /_/ / __ `/ __ \/ /_  /
*  / _, _/ /_/ / /_/ / / / /_
* /_/ |_|\__,_/ .___/_/ /___/
*            /_/             
*           code@rapiz.me
*          Tue, 20 Aug 2019 22:48:06 +0800
*/
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
int n, l, r;
ll mn, mx;
int main() {
  cin >> n >> l >> r;
  int i, x;
  for (i = 1, x = 1; i <= l; i++, x<<=1) {
      mn+=x;
  }
  x>>=1;
  mn += n - l;
  for (i = 1, x = 1; i <= r; i++, x<<=1) {
    mx += x;
  }
  x>>=1;
  mx += x*(n - r) ;
  cout << mn << " " << mx;
}

