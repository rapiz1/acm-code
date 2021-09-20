#include <bits/stdc++.h>
using namespace std;
class Solution {
  string cur, ans, s;
  int k;
  map<char, int> chcnt;
  bool check() {  // return whether cur is a k-subseq of s
    if (cur.size() == 0) return true;
    int i = 0, round = 0;
    for (auto c : s) {
      if (c == cur[i]) {
        i++;
        if (i == cur.size()) {
          round++;
          i = 0;
        }
        if (round == k) {
          if (ans.size() < cur.size()) ans = cur;
          return true;
        }
      }
    }
    return false;
  }
  void dfs() {
    if (cur.size() * k > s.size()) return;
    if (!check()) return;
    for (auto it = chcnt.rbegin(); it != chcnt.rend(); it++) {
      auto pa = *it;
      char ch = pa.first;
      if (pa.second == 0) continue;
      chcnt[ch]--;
      cur.push_back(ch);
      dfs();
      cur.pop_back();
      chcnt[ch]++;
    }
  }

 public:
  string longestSubsequenceRepeatedK(string s, int k) {
    this->s = s;
    this->k = k;
    for (auto c : s) chcnt[c]++;
    vector<char> del;
    for (auto pa : chcnt) {
      if (pa.second < k) del.push_back(pa.first);
    }
    for (auto c : del) chcnt.erase(c);
    dfs();
    return ans;
  }
};

int main() {
  Solution sol;
  cout << sol.longestSubsequenceRepeatedK("letsleetcode", 2);
}
