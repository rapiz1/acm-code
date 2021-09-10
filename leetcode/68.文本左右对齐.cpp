#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> answer;
    // space = (maxWidth - sum(wordWidth))/(n(word)-1)
    // space >= 1 => maxWidth + 1 >= sum(wordWith) + n(word)
    for (int i = 0, j = -1; i < words.size(); i = j + 1) {
      int wordWidth = 0;
      while (j + 1 < words.size() && maxWidth + 1 >= wordWidth +
                                                         (j + 1 - i + 1) +
                                                         words[j + 1].size()) {
        wordWidth += words[++j].size();
      }
      string line = words[i];
      if (j == words.size() - 1) {
        for (int k = i + 1; k <= j; k++) line += ' ' + words[k];
      } else if (j != i) {
        int sep = (maxWidth - wordWidth) / (j - i);
        int sep_remain = (maxWidth - wordWidth) % (j - i);
        for (int k = i + 1; k <= j; k++) {
          int space = sep;
          if (sep_remain) {
            sep_remain--;
            space++;
          }
          line += string(space, ' ') + words[k];
        }
      }
      if (line.size() < maxWidth) {
        line += string(maxWidth - line.size(), ' ');
      }
      answer.push_back(line);
    }
    return answer;
  }
};
// @lc code=end
