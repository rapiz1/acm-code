#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char nextdi(char c) {
  if (c < '9' && c >= '0')
    return c + 1;
  else if (c == '9')
    return '0';
  else
    assert(false);
}
string solve() {
  string s, ret;
  int n;
  cin >> n >> s;
  ret = s;
  while (1) {
    bool fd = false;
    for (int rule_start = '0'; rule_start <= '9'; rule_start++) {
      s = ret;
      ret.clear();
      ret.reserve(s.size());
      for (int i = 0; i < s.size(); i++) {
        if (i + 1 == s.size()) {
          ret.push_back(s[i]);
          continue;
        }
        char c = s[i];
        char nc = s[i + 1];
        if (c == rule_start && nc == nextdi(c)) {
          ret.push_back(nextdi(nc));
          fd = true;
          i++;
        } else {
          ret.push_back(c);
        }
      }
    }
    if (!fd) break;
  }
  return ret;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    printf("Case #%d: %s\n", i, solve().c_str());
  }
}
