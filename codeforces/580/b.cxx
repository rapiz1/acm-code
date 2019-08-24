/**
*     ____              _    
*    / __ \____ _____  (_)___
*   / /_/ / __ `/ __ \/ /_  /
*  / _, _/ /_/ / /_/ / / / /_
* /_/ |_|\__,_/ .___/_/ /___/
*            /_/             
*           code@rapiz.me
*          Tue, 20 Aug 2019 21:54:58 +0800
*/
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, a[N];
ll pos, neg;
int main() {
  cin >> n;
  cin >> a[1];
  pos = abs(a[1] -1);
  neg = abs(a[1] + 1);
  for (int i = 2; i <= n; i++) {
      cin >> a[i];
      ll tpos = min(abs(a[i] - 1) + pos, abs(a[i] + 1) + neg);
      ll tneg = min(abs(a[i] - 1) + neg, abs(a[i] + 1) + pos);
      pos = tpos;
      neg = tneg;
  }
  cout << pos;
}

