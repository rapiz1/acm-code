#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int sumOfBeauties(vector<int>& nums) {
    vector<int> mxv, mnv;
    mxv.resize(nums.size());
    mnv.resize(nums.size());
    for (int i = 0; i < nums.size(); i++) mxv[i] = mnv[i] = nums[i];
    for (int i = 1; i < nums.size(); i++) mxv[i] = max(mxv[i], mxv[i - 1]);
    for (int i = nums.size() - 2; i >= 0; i--) mnv[i] = min(mnv[i], mnv[i + 1]);
    int answer = 0;
    for (int i = 1; i < nums.size() - 1; i++) {
      int k = 0;
      if (mxv[i - 1] < nums[i] && nums[i] < mnv[i + 1]) {
        k = 2;
      } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
        k = 1;
      }
      // cout << i << " " << k << endl;
      answer += k;
    }
    return answer;
  }
};

int main() {
  Solution sol;
  vector<int> a{2, 4, 6, 4};
  sol.sumOfBeauties(a);
}
