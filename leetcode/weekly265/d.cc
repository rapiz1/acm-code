#include <bits/stdc++.h>
using namespace std;
class Solution {
  string s1, s2;
  set<vector<int>> a;
  // ep1 is len of expanded string
  bool dfs(int p1, int p2, int ep1, int ep2 /*, int matchn*/) {
    if (ep1 && ep2) {
      int mn = min(ep1, ep2);
      ep1 -= mn;
      ep2 -= mn;
      // matchn += mn;
    }

    // some ep 0
    while (ep1 || ep2) {
      if (ep1 && p2 < s2.size() && !isdigit(s2[p2]))
        p2++, ep1--;
      else if (ep2 && p1 < s1.size() && !isdigit(s1[p1]))
        p1++, ep2--;
      else
        break;
    }

    // ep all 0
    while (p1 < s1.size() && p2 < s2.size() && ep1 == 0 && ep2 == 0 &&
           s1[p1] == s2[p2] && !isdigit(s1[p1]) && !isdigit(s2[p2]))
      p1++, p2++;

    vector<int> f = {p1, p2, ep1, ep2};
    if (a.count(f)) return false;
    a.insert(f);

    if (p1 == s1.size() && p2 == s2.size() && ep1 == 0 && ep2 == 0) return true;

    if (p2 < s2.size() && isdigit(s2[p2])) {
      // int len = 1;
      // while (p2 + len < s2.size() && isdigit(s2[p2 + len])) len++;
      int num = 0;
      for (int i = 0; p2 + i < s2.size() && isdigit(s2[p2 + i]); i++) {
        num = num * 10 + s2[p2 + i] - '0';
        if (dfs(p1, p2 + i + 1, ep1, ep2 + num)) return true;
      }
    }
    if (p1 < s1.size() && isdigit(s1[p1])) {
      // int len = 1;
      // while (p1 + len < s1.size() && isdigit(s1[p1 + len])) len++;
      int num = 0;
      for (int i = 0; p1 + i < s1.size() && isdigit(s1[p1 + i]); i++) {
        num = num * 10 + s1[p1 + i] - '0';
        if (dfs(p1 + i + 1, p2, ep1 + num, ep2)) return true;
      }
    }
    return false;
  }

 public:
  bool possiblyEquals(string s1, string s2) {
    this->s1 = s1;
    this->s2 = s2;
    return dfs(0, 0, 0, 0);
  }
};

int main() {
  Solution sol;
  // string a = "l123e";
  // string b = "44";
  string a = "49u74v37v687u179v588u958u2";
  string b = "2v191u7u275u937u5v883v2u61v";
  cout << sol.possiblyEquals(a, b);
}
