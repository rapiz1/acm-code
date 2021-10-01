#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
 public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    int ans = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
    int x_min = max(ax1, bx1);
    int x_max = min(ax2, bx2);
    int y_min = max(ay1, by1);
    int y_max = min(ay2, by2);
    ans -= max((x_max - x_min), 0) * max((y_max - y_min), 0);
    return ans;
  }
};
// @lc code=end
