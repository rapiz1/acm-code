#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
typedef long long ll;
ll l, r;
void input() {
  cin >> s;
  cin >> l >> r;
}
static const char TARGET = 'B';
ll solve() {
  int bc = 0;
  for (auto c : s) bc += c == TARGET;
  l--, r--;
  ll l_idx = l / s.size(), r_idx = r / s.size();
  ll complete_count = r_idx - l_idx - 1;
  l %= s.size();
  r %= s.size();
  ll answer = complete_count * bc;
  for (int i = l; i < s.size(); i++) answer += s[i] == TARGET;
  for (int i = 0; i <= r; i++) answer += s[i] == TARGET;
  return answer;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    input();
    printf("Case #%d: %lld\n", i, solve());
  }
}
