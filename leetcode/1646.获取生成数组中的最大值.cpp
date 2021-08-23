#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1646 lang=cpp
 *
 * [1646] 获取生成数组中的最大值
 *
 * https://leetcode-cn.com/problems/get-maximum-in-generated-array/description/
 *
 * algorithms
 * Easy (50.61%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    29K
 * Total Submissions: 54.3K
 * Testcase Example:  '7'
 *
 * 给你一个整数 n 。按下述规则生成一个长度为 n + 1 的数组 nums ：
 *
 *
 * nums[0] = 0
 * nums[1] = 1
 * 当 2  时，nums[2 * i] = nums[i]
 * 当 2  时，nums[2 * i + 1] = nums[i] + nums[i + 1]
 *
 *
 * 返回生成数组 nums 中的 最大 值。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 7
 * 输出：3
 * 解释：根据规则：
 * ⁠ nums[0] = 0
 * ⁠ nums[1] = 1
 * ⁠ nums[(1 * 2) = 2] = nums[1] = 1
 * ⁠ nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
 * ⁠ nums[(2 * 2) = 4] = nums[2] = 1
 * ⁠ nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
 * ⁠ nums[(3 * 2) = 6] = nums[3] = 2
 * ⁠ nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
 * 因此，nums = [0,1,1,2,1,3,2,3]，最大值 3
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 2
 * 输出：1
 * 解释：根据规则，nums[0]、nums[1] 和 nums[2] 之中的最大值是 1
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 3
 * 输出：2
 * 解释：根据规则，nums[0]、nums[1]、nums[2] 和 nums[3] 之中的最大值是 2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int getMaximumGenerated(int n) {
    vector<int> f;
    f.resize(max(n + 1, 2));
    f[0] = 0;
    f[1] = 1;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
      f[i] = i % 2 ? (f[i / 2] + f[i / 2 + 1]) : f[i / 2];
      ans = max(ans, f[i]);
    }
    for (int i = 0; i <= n; i++) {
      ans = max(ans, f[i]);
    }
    return ans;
  }
};
// @lc code=end
