/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Fri, 23 Aug 2019 12:54:50 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
ll a, b;
ll getb(ll t, int k) {
  return (t>>k)&1;
}
ll setb(ll& t, int k, int x) { // set k-th bit to x(0/1)
  if (x) {
    t |= 1ll<<k;
  }
  else {
    t &= ~(1ll<<k);
  }
  return t;
}
/*
void show(int t) {
  for (int i = 31; i>=0; i--) cout << getb(t, i);
  cout  << endl;
}
*/
ll solve() {
  ll ret = 0;
  for (int i = 0; i < 32; i++) {
    int x = getb(a, i);
    int y = getb(b, i);
    int opt1 = (x^1) & (y^1);
    int opt0 = (x^0) & (y^0);
    if (opt1 < opt0) {
      setb(ret, i, 1);
    }
    else {
      setb(ret, i, 0);
    }
  }
  if (((a^1)&(b^1)) == 0) return 1;
  if (ret == 0) ret = 1;
  return ret;
}
ll brute() {
  ll v = 1ll<<32, ans;
  for (ll ret = 1; ret <= 1000000; ret++) {
    ll nv = (a^ret)&(b^ret);
    if (nv < v) {
      v = nv;
      ans = ret;
    }
  }
  return ans;
}
int main() {
  int ks; cin >> ks;
  while (ks--) {
    cin >> a >> b;
    cout << solve() << endl;
  }
}

