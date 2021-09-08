#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
  typedef pair<int, int> pa;

 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capital) {
    int answer = w;
    vector<int> idx_sorted_by_capital;
    idx_sorted_by_capital.reserve(capital.size());
    for (int i = 0; i < capital.size(); i++) idx_sorted_by_capital.push_back(i);
    sort(idx_sorted_by_capital.begin(), idx_sorted_by_capital.end(),
         [&capital](int x, int y) { return capital[x] < capital[y]; });
    priority_queue<int> q;
    int j = -1;
    while (j + 1 < idx_sorted_by_capital.size() &&
           capital[idx_sorted_by_capital[j + 1]] <= answer) {
      q.push(profits[idx_sorted_by_capital[++j]]);
    }
    for (int i = 0; i < k && !q.empty(); i++) {
      answer += q.top();
      q.pop();
      while (j + 1 < idx_sorted_by_capital.size() &&
             capital[idx_sorted_by_capital[j + 1]] <= answer) {
        q.push(profits[idx_sorted_by_capital[++j]]);
      }
    }
    return answer;
  }
};
// @lc code=end
