/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 14 Sep 2019 09:10:57 +0800
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <vector>
#include <utility>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
ll a, b;
ll gcd(ll a, ll b) {a=a>0?a:-a;b=b>0?b:-b;return b ? gcd(b, a%b) : a;}
inline ll qmul(ll a, ll b, ll mod) {
  ll d = (ll)floor(a*(long double)b/mod + 0.5);
  ll ret = a*b - d*mod;
  if (ret < 0) ret += mod;
  return ret;
}
inline ll randint(ll l, ll r) {
  return (((ll)rand()<<15)^rand())%(r - l + 1) + l;
}
ll qpow(ll x, ll r, ll mod) {
  ll ret = 1;
  for(ll tmp = x; r; r>>=1) {
    if (r&1) ret = qmul(ret, tmp, mod);
    tmp = qmul(tmp, tmp, mod);
  }
  return ret;
}
bool witness(ll a, ll n) {
  int t;
  ll m;
  for (t = 0, m = n - 1; m && !(m&1);t++, m>>=1) ;
  ll x = qpow(a, m, n);
  for (int i = 1; i <= t; i++) {
    ll nx = qmul(x, x, n);
    if (nx == 1 && x != 1 && x != n - 1) return true;
    x = nx;
  }
  return x != 1;
}
bool primetest(ll n) {
  if (n == 1) return false;
  const static int s = 20;
  for (int i = 1; i <= s; i++) {
    ll a = randint(1, n - 1);
    if (witness(a, n)) return false;
  }
  return true;
}
ll rho(ll n) {
  if (n == 1) return 1;
  else if (n == 0) return 0;
  int i, k;
  ll x, y, c;
  for (i = 2, x = randint(0, n - 1), y = x, k = 2, c = rand(); 1; i++) {
    x = (qmul(x, x, n) + c)%n;
    //x = (x*x%n - 1 + n)%n;
   ll d = gcd(y - x, n);
    if (d > 1) {
      return d;
    }
    if (i == k) k<<=1, y = x;
    //xxx(i);xxx(x);xxx(y);
  }
}
map<ll, int> mm;
void resolve(ll n) {
  if (n == 1) return;
  if (primetest(n)) {
    mm[n]++;
  }
  else {
    ll p = n;
    while (p == n) {
      p = rho(p);
    }
    resolve(p);
    resolve(n/p);
  }
}
vector<pair<ll, int> > fac;
double sum;
ll ans;
void dfs(int idx, ll x) {
  if (idx >= (int)fac.size()) return;
  if (b/x + x < sum) {
    sum = b/x + x;
    ans = x;
  }
  for (int i = 0; i <= fac[idx].second; i++, x *= fac[idx].first) {
    dfs(idx+1, x);
  }
}
void solve() {
  mm.clear();
  fac.clear();
  sum = 1e20;
  b /= a;
  resolve(b);
  //xxx(b);
  for (map<ll, int>::iterator x = mm.begin(); x != mm.end(); x++) {
    fac.push_back(*x);
  }
  dfs(0, 1);
  cout << b/ans*a << " " << ans*a << endl;
}
int main() {
  srand(time(NULL));
  fastios;
  while (cin >> a >> b) {
    solve();
  }
}

