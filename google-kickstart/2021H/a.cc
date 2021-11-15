#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, f;
int dis(int a, int b) {
  a -= 'a';
  b -= 'a';
  const int mod = 'z' - 'a' + 1;
  int d = abs(a - b);
  return min(d, mod - d);
}
ll solve() {
  ll ans = 0;
  cin >> s >> f;
  for (auto c : s) {
    int md = 26;
    for (auto t : f) md = min(md, dis(t, c));
    ans += md;
  }
  return ans;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    printf("Case #%d: %lld\n", i, solve());
  }
}
