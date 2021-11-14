#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, f;
int dis(int a, int b) {
  a -= 'a';
  b -= 'a';
  const int mod = 'z' - 'a' + 1;
  return (a - b + mod) % mod;
}
ll solve() {
  ll ans = 0;
  cin >> s >> f;

  return ans;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    printf("Case #%d: %lld\n", i, solve());
  }
}
