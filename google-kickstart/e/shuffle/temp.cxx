#include <bits/stdc++.h>
#define NOSOL "IMPOSSIBLE"
using namespace std;
string s;
const int CHARSET = 256;
void input() { cin >> s; }
string solve() {
  string answer = s;
  vector<int> perm;
  int n = s.size();
  for (int i = 0; i < n; i++) perm.push_back(i);
  while (next_permutation(perm.begin(), perm.end())) {
    bool fd = 1;
    for (int i = 0; i < n; i++) {
      answer[i] = s[perm[i]];
      if (answer[i] != s[i])
        ;
      else {
        fd = 0;
        break;
      }
    }
    if (fd) return answer;
  }
  return NOSOL;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    input();
    printf("Case #%d: %s\n", i, solve().c_str());
  }
}
