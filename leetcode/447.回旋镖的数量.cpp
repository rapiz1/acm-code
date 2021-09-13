#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
  inline int pow(int x) { return x * x; }
  inline int dis(const vector<int>& x, const vector<int>& y) {
    return pow(x[0] - y[0]) + pow(x[1] - y[1]);
  }

 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int n = points.size(), answer = 0;
    for (int i = 0; i < n; i++) {
      unordered_map<int, int> m;
      for (int j = 0; j < n; j++)
        if (j != i) m[dis(points[i], points[j])]++;
      for (auto pa : m) {
        int x = pa.second;
        answer += x * (x - 1);
      }
    }
    return answer;
  }
};
// @lc code=end
