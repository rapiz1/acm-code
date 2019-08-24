/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Sat, 24 Aug 2019 20:32:13 +0800
 */
// multiple rev
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int N = 2010;
const int MOD = 1e9 + 7;
ll n, k, a[N], rev[N], val[N];
ll qpow(ll a,ll r){
  a%=MOD;
	ll res=1,fac=a;
	while(r){
		if(r&1) res*=fac, res%=MOD;
		fac*=fac,r>>=1;
    fac%=MOD;
	}
	return res;
}
ll mrev(ll x) {
  return qpow(x, MOD - 2);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    val[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (a[i] < a[j]) {
        rev[i]++;
      }
    }
  }
  for (int i = 1; i < N; i++) val[i] += val[i-1];
  ll ans = 0;
  ll divtwo = mrev(2);
  for (int i = 1; i <= n; i++) {
    ans += ll(val[a[i]-1])*k%MOD*(k-1ll)%MOD*divtwo%MOD + ll(rev[i])*k%MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}

