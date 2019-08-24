/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 24 Aug 2019 16:34:42 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
namespace getMu {
  const int MAXN = 1e6;
  bool isNotPrime[MAXN + 1];
  int mu[MAXN + 1], phi[MAXN + 1], primes[MAXN + 1], cnt;
  inline void euler()
  {
    isNotPrime[0] = isNotPrime[1] = true;
    mu[1] = 1;
    phi[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
      if (!isNotPrime[i])
      {
        primes[++cnt] = i;
        mu[i] = -1;
        phi[i] = i - 1;
      }

      for (int j = 1; j <= cnt; j++)
      {
        int t = i * primes[j];
        if (t > MAXN) break;

        isNotPrime[t] = true;

        if (i % primes[j] == 0)
        {
          mu[t] = 0;
          phi[t] = phi[i] * primes[j];
          break;
        }
        else
        {
          mu[t] = -mu[i];
          phi[t] = phi[i] * (primes[j] - 1);
        }
      }
    }
  }
  void print(int n) {
    for (int i = 1; i <= n; i++) {
      printf("mu[%d] %d\n", i, mu[i]);
    }
  }
}
int n, m;
void solve() {
  using getMu::mu;
  cin >> n >> m;
  ll sum = 0, ans = 0;
  for (int i = 1; i <= m; i++) sum += mu[i];
  for (int i = 1; i <= n; i++) {
    ll dec = 0;
    for (int j = i; j <= m; j+=i) {
      dec += mu[j];
    }
    ans += mu[i]*(sum - dec);
  }
  cout << ans << endl;
}
int main() {
  int t; cin >> t;
  getMu::euler();
  getMu::print(20);
  while (t--) {
    solve();
  }
}

