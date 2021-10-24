#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isvalid(string s) {
    char quote[] = {',', '.', '!'};
    int cntq = 0;
    int cntl = 0;
    for (auto c : s) {
      if (isdigit(c)) return false;
      cntl += c == '-';
      cntq += c == ',' || c == '.' || c == '!';
    }
    if (cntl > 1 || cntq > 1) return false;
    for (auto c : quote) {
      int pos = s.find(c);
      if (pos != string::npos) {
        if (pos == s.size() - 1)
          ;
        else
          return false;
      }
    }
    int pos = s.find('-');
    if (pos == 0 || pos == s.size() - 1) return false;
    return true;
  }
  int countValidWords(string sentence) {
    stringstream ss(sentence);
    int ans = 0;
    string s;
    while (ss >> s) {
      ans += isvalid(s);
    }
    return ans;
  }
};
int main() {
  Solution sol;
  cout << sol.countValidWords("abc");
}
