/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 14 Sep 2019 12:49:45 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
int n;
inline int randint(int l, int r) {
  return rand()%(r - l + 1) + l;
}
int qpow(int x, int r, int mod) {
  int ret = 1;
  for(int tmp = x; r; r>>=1) {
    if (r&1) ret = ((ll)ret*tmp)%mod;
    tmp = (ll)tmp*tmp%mod;
  }
  return ret;
}
bool witness(int a, int n) {
  int t, m;
  for (t = 0, m = n - 1; m && !(m&1);t++, m>>=1) ;
  int x = qpow(a, m, n);
  for (int i = 1; i <= t; i++) {
    int nx = (ll)x*x%n;
    if (nx == 1 && x != 1 && x != n - 1) return true;
    x = nx;
  }
  return x != 1;
}
bool primetest(int n) {
  if (n == 1) return false;
  const static int s = 50;
  for (int i = 1; i <= s; i++) {
    int a = randint(1, n - 1);
    if (witness(a, n)) return false;
  }
  return true;
}
int main() {
  srand(time(NULL));
  cin >> n;
  cout << (primetest(n) ? "YES" : "NO") << endl;
}
