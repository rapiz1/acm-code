/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sun, 25 Aug 2019 13:59:51 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long ll;
using namespace std;
const int MOD = 1e9 + 7;
typedef pair<ll, double> PA;
ll a, b, n, divtwo;
ll qpow(ll a,ll r){
  ll res=1,fac=a;
  while(r){
    if(r&1) res*=fac, res%=MOD;
    fac*=fac,r>>=1;
    fac%=MOD;
  }
  return res;
}
ll mrev(ll a) {
  return qpow(a, MOD - 2);
}
inline long long multi(long long x,long long y,long long mod=MOD)
{
  long long tmp=(x*y-(long long)((long double)x/mod*y+1.0e-8)*mod);
  return tmp<0 ? tmp+mod : tmp;
}
PA calc(ll n) {
  ll lret = multi(multi(multi(n,n),n),b) + multi(multi(multi(n-1,n),n),a);
  //xxx(lret);
  double dret = 1.0*n*n*n*b + (n-1.0)*n*n*a;
  if (n%2) return PA({lret, dret});
  PA tmp = calc(n/2);
  ll lt = tmp.first;
  double dt = tmp.second;
  ll ls = multi(multi(multi(18,(n*divtwo%MOD)),(n*divtwo%MOD)),a) + 7*lt%MOD;
  //xxx(ls);
  double ds = 18.0*n/2*n/2*a + 7*dt;
  ls %= MOD;
  if (ds < dret) {
    return PA({ls, ds});
  }
  else return PA({lret, dret});
}
void solve() {
  cin >> n >> a >> b;
  cout << calc(n).first << endl;
}
int main() {
  int ks; cin >> ks;
  divtwo = mrev(2);
  while (ks--) {
    solve();
  }
}

