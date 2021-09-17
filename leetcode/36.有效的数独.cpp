#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
  int col_taken[9], row_taken[9], square_taken[9];

 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        int sid = (i / 3) * 3 + j / 3;
        int x = board[i][j] - '0';
        if ((col_taken[j] >> x) & 1) return false;
        if ((row_taken[i] >> x) & 1) return false;
        if ((square_taken[sid] >> x) & 1) return false;
        col_taken[j] |= 1 << x;
        row_taken[i] |= 1 << x;
        square_taken[sid] |= 1 << x;
      }
    return true;
  }
};
// @lc code=end
