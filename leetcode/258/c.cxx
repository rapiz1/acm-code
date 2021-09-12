#include <bits/stdc++.h>
using namespace std;
class Solution {
  static const int MAXN = 15;
  bool sel[MAXN];
  char x[MAXN];
  int xn;
  char y[MAXN];
  int yn;
  int answer;
  bool check_pali(char s[MAXN], int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--)
      if (s[i] != s[j]) return false;
    return true;
  }
  void dfsy(int pos, const string& s) {
    if (pos >= s.size()) {
      // boundary
      if (!check_pali(y, yn))
        return;
      else {
        answer = max(answer, xn * yn);
        return;
      }
    }
    // pick
    if (!sel[pos]) {
      sel[pos] = 1;
      y[yn++] = s[pos];
      dfsy(pos + 1, s);
      --yn;
      sel[pos] = 0;
    }
    // not pick
    dfsy(pos + 1, s);
  }
  void dfsx(int pos, const string& s) {
    if (pos >= s.size()) {
      // boundary
      if (!check_pali(x, xn)) return;
      // else dfsy(0, s);
    }
    // pick
    sel[pos] = 1;
    x[xn++] = s[pos];
    dfsx(pos + 1, s);
    --xn;
    sel[pos] = 0;
    // not pick
    dfsx(pos + 1, s);
  }

 public:
  int maxProduct(string s) {
    xn = yn = answer = 0;
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(sel, 0, sizeof sel);
    dfsx(0, s);
    return answer;
  }
};

int main() {
  Solution sol;
  cout << sol.maxProduct("leetcodecom");
}
