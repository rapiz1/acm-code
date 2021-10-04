#include <bits/stdc++.h>
using namespace std;
class Solution {
  int dp[3][3][3][3];  // s, f[i], act first => win or lose
  int dfs(int s, int f[3]) {
    int mem = dp[s][f[0]][f[1]][f[2]];
    if (mem != -1) return mem;
    int ret = 0;

    vector<int> succ;
    for (int i = 0; i < 3; i++) {
      if (f[i] == 0) continue;
      if ((s + i) % 3 == 0) continue;
      f[i]--;
      succ.push_back(dfs((s + i) % 3, f));
      f[i]++;
    }
    if (succ.size()) {
      int win = 1;
      for (auto x : succ) win &= !x;

      ret = win;
    } else {
      ret = 0;
    }
    return dp[s][f[0]][f[1]][f[2]] = ret;
  }

 public:
  bool stoneGameIX(vector<int>& stones) {
    int f[3] = {};
    for (auto x : stones) f[x % 3]++;
    for (int i = 0; i < 3; i++) f[i] %= 3;
    memset(dp, -1, sizeof dp);
    return dfs(0, f);
  }
};
Solution sol;
int main() {
  vector<int> arg = {2};
  sol.stoneGameIX(arg);
  return 0;
}
