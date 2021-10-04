#include <bits/stdc++.h>
using namespace std;
class Solution {
  static const int N = 5e4 + 10;
  int nxt[N][26];

 public:
  string smallestSubsequence(string s, int k, char letter, int repetition) {
    vector<int> letc;
    letc.resize(s.size());
    for (int i = 0; i <= s.size(); i++) {
      for (int j = 0; j < 26; j++) nxt[i][j] = s.size();
    }
    for (int i = s.size() - 1; i >= 0; i--) {
      letc[i] = s[i] == letter;
      if (i != s.size() - 1) {
        letc[i] += letc[i + 1];
        for (int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i + 1] - 'a'] = i + 1;
      }
    }
    int hed[26] = {};
    for (int i = 0; i < 26; i++) {
      hed[i] = nxt[0][i];
    }
    hed[s[0] - 'a'] = 0;
    string ans;
    int pos = -1, need_len = k, need_let = repetition;
    for (; pos < (int)s.size();) {
      if (!need_len) break;
      for (int c = 0; c < 26; c++) {
        int nxt_pos = pos == -1 ? hed[c] : nxt[pos][c];
        int left_len = (int)s.size() - nxt_pos;
        if (left_len < need_len) continue;
        int left_let = letc[nxt_pos];
        if (left_let < need_let) continue;
        need_len--;
        need_let -= s[nxt_pos] == letter;
        ans.push_back(c + 'a');
        pos = nxt_pos;
        break;
      }
    }
    for (int j = ans.size() - 1; j >= 0; j--) {
      if (ans[j] == letter) continue;
      if (need_let > 0)
        ans[j] = letter;
      else
        break;
      need_let--;
    }
    return ans;
  }
};
Solution sol;
int main() {
  /*
  "adffhjfmmmmorsfff"
6
"f"
5
  */
  cout << sol.smallestSubsequence("adffhjfmmmmorsfff", 6, 'f', 5);
  return 0;
}
