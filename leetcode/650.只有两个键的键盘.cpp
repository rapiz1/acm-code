#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
  static const int N = 1010;
  int f[N][N];

 public:
  int minSteps(int n) {
    // f[i][j]: 已有字符数i,剪贴板字符数j
    // f[i][j] = min f[i-j][j]
    //              |f[i/2][*] if i%2 == 0 and j == i/2
    //                  +1
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    f[1][1] = 1;
    f[1][n + 1] = 0;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        f[i][j] = f[i - j][j] + 1;
        if (j * 2 == i) f[i][j] = min(f[i][j], f[i / 2][n + 1] + 2);
        f[i][n + 1] = min(f[i][j], f[i][n + 1]);
        // printf("f[%d][%d]:%d\n", i, j, f[i][j]);
      }
    }
    return f[n][n + 1];
  }
};
// @lc code=end
