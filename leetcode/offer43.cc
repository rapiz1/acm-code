#include <bits/stdc++.h>
using namespace std;
class Solution {
  int a[12], len, f[12];
  int part(int pre) {
    int x = 0;
    for (int i = pre; i >= 0; i--) x = x * 10 + a[i];
    return x;
  }
  int dfs(int pos, int at_upper, int leading_zero) {
    if (pos < 0) return 0;
    if (!at_upper && !leading_zero && f[pos]) return f[pos];
    int ret = 0;
    int upper = at_upper ? a[pos] : 9;
    for (int i = 0; i <= upper; i++) {
      if (i == 1 && at_upper && i == upper)
        ret += part(pos - 1) + 1 + dfs(pos - 1, at_upper, false);  // todo
      else if (i == 1)
        ret += pow(10, pos) + dfs(pos - 1, false, false);
      else
        ret += dfs(pos - 1, at_upper && i == upper, leading_zero && i == 0);
    }

    if (!at_upper && !leading_zero) f[pos] = ret;

    return ret;
  }

 public:
  int countDigitOne(int n) {
    for (int x = n; x; x /= 10) a[len++] = x % 10;
    return dfs(len - 1, true, true);
  }
};

Solution sol;
int main() { cout << sol.countDigitOne(12); }
