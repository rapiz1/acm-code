/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Thu, 22 Aug 2019 23:47:39 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
typedef pair<int, int> pa;
const int N = 3e5 + 10, MOD = 998244353;
int n;
pa a[N];
map<pa, int> st;
vector<int> v1, v2;
//TODO: remeber long long !
void show(vector<pa> & vec) {
  for (auto x:vec) {
    cerr << x.first << " " << x.second << endl;
  }
  cerr << endl;
}
bool checkself() {
  bool f1 = 1, f2 = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i-1].first > a[i].second) {
      f1 = 0;
    }
    if (a[i-1].second > a[i].second) {
      f2 = 0;
    }
  }
  return !f1 && !f2;
}
ll mkfac(ll x) {
  ll ret = 1;
  for (int i = 1; i <= x; i++) {
    ret = (ret*i)%MOD;
  }
  return ret;
}
ll calc(vector<int>& v) {
  vector<int> tmp;
  map<int, int> st;
  for (auto x: v) {
    st[x]++;
  }
  ll ret = 1;
  for (auto x: st) {
    ret = (ret*mkfac(x.second))%MOD;
  }
  return ret;
}
ll calcAll() {
  map<pa, int> st;
  vector<pa> tmp;
  for (int i = 1; i <= n; i++) {
    st[a[i]]++;
    tmp.push_back(a[i]);
  }
  stable_sort(tmp.begin(), tmp.end(), [](pa x, pa y)->bool{return x.first <= y.first && x.second <= y.second;});
  for (int i = 1; i < n; i++) {
    if (!(tmp[i-1].first <= tmp[i].first && tmp[i-1].second <= tmp[i].second)) {
      return 0;
    }
  }
  ll ret =1;
  for (auto x:st) {
    ret = (ret*mkfac(x.second))%MOD;
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    v1.push_back(a[i].first), v2.push_back(a[i].second);
  }
  ll fac = 1;
  for (int i = 2; i <= n; i++) fac = (fac*i)%MOD;
//  xxx(calc(v1));
//  xxx(calc(v2));
//  xxx(calcAll());
  fac = fac - calc(v1) - calc(v2) + calcAll();
  while (fac < 0) {
    fac += MOD;
  }
  fac %= MOD;
  cout << fac;
}

