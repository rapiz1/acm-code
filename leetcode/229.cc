#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> selected{0, 1};
    vector<int> count{0, 0};
    for (auto x : nums) {
      bool neq = true;
      for (int j = 0; j < selected.size(); j++) {
        if (!count[j]) continue;
        neq &= selected[j] != x;
        if (x == selected[j]) {
          count[j]++;
        };
      }
      if (neq && count[0] && count[1])
        for (auto& c : count) c = max(0, c - 1);
      if (neq)
        for (int j = 0; j < selected.size(); j++) {
          if (count[j] == 0) {
            selected[j] = x;
            count[j] = 1;
            break;
          }
        }
    }
    for (auto& x : count) x = 0;
    for (auto x : nums) {
      for (int i = 0; i < selected.size(); i++)
        if (x == selected[i]) count[i]++;
    }
    vector<int> ans;
    for (int i = 0; i < selected.size(); i++)
      if (count[i] > nums.size() / 3) ans.push_back(selected[i]);
    if (ans.size() == 2 && ans[0] == ans[1]) ans.pop_back();
    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> arg{1, 2};
  sol.majorityElement(arg);
}
