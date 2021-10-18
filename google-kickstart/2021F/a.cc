#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
void input() { cin >> n >> s; }
int gnxt(int p) {
  for (int i = p; i < s.size(); i++)
    if (s[i] == '1') return i;
  return 2 * n;
}
ll solve() {
  ll ans = 0;
  int prev = gnxt(0), next = gnxt(prev + 1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      prev = i;
      next = gnxt(i + 1);
    }
    ans += min(abs(prev - i), abs(next - i));
  }
  return ans;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    input();
    printf("Case #%d: %lld\n", i, solve());
  }
}
