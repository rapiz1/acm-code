#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
class Solution {
  static const int MAXE = 201;
  vector<vector<int>> answer;
  int have[MAXE], used[MAXE], target;
  void clear() {
    answer.clear();
    memset(have, 0, sizeof(have));
    memset(used, 0, sizeof(used));
  }
  void print() {
    for (auto comb : answer) {
      for (auto v : comb) {
        cout << v << " ";
      }
      cout << endl;
    }
  }
  void dfs(int sum, int lower) {
    if (sum == target) {
      vector<int> now_ans;
      for (int i = 1; i < MAXE; i++) {
        for (int j = 0; j < used[i]; j++) {
          now_ans.push_back(i);
        }
      }
      answer.push_back(now_ans);
    }
    else if (sum > target) {
      return;
    }
    for (int i = lower; i <= min(target - sum, MAXE-1); i++) {
      if (!have[i]) continue;
      used[i]++;
      dfs(sum + i, i);
      used[i]--;
    }
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    clear();
    this->target = target;
    for (auto num : candidates) {
      have[num]++;
    }
    dfs(0, 1);
    return answer;
  }
};
int main() {
  Solution solver;
  vector<int> candidates = vector<int>({2,3,5});
  int target = 8;
  solver.combinationSum(candidates, target);
}
