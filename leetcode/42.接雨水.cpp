#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
 public:
  int trap(vector<int>& height) {
    vector<bool> disable;
    disable.resize(height.size());
    int maxh = height[height.size() - 1];
    for (int i = height.size() - 1; i >= 0; i--) {
      disable[i] = height[i] > maxh;
      maxh = max(maxh, height[i]);
    }
    int answer = 0;
    for (int i = 0; i < height.size(); i++) {
      if (disable[i]) continue;
      int left_h = height[i];
      int k = i;
      while (k + 1 < height.size() && height[k + 1] < left_h) k++;
      int level = k + 1 < height.size() ? left_h : 0;
      for (int j = i; j <= k; j++) answer += max(level - height[j], 0);
      left_h = height[k];
      // cout << i << " " << k << " " << level << endl;
      i = k;
    }
    return answer;
  }
};
// @lc code=end
