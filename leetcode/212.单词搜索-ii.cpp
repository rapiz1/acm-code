#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Solution {
  unordered_map<string, bool> rec;

  vector<vector<char>> board;

  static const int N = 13;
  bool vis[N][N];
  string current;
  void dfs(int x, int y) {
    if (current.size() > 10) return;
    if (rec[current] == 1) {
      if (!found[current]) {
        found[current] = 1;
        answer.push_back(current);
      }
    }
    if (current.size() && !rec.count(current)) {
      return;
    }
    if (current.size() == 10) return;
    for (int dx = -1; dx <= 1; dx++)
      for (int dy = -1; dy <= 1; dy++)
        if (dx * dy == 0 && dx + dy != 0) {
          int nx = x + dx, ny = y + dy;
          if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())
            ;
          else
            continue;
          if (vis[nx][ny]) continue;
          vis[nx][ny] = 1;
          current.push_back(board[nx][ny]);
          dfs(nx, ny);
          current.pop_back();
          vis[nx][ny] = 0;
        }
  }

  vector<string> answer;
  unordered_map<string, bool> found;

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    this->board = board;
    for (auto& s : words) {
      for (int i = 1; i < s.size(); i++) {
        auto ss = s.substr(0, i);
        if (rec.count(ss)) continue;
        rec[s.substr(0, i)] = 0;
      }
      rec[s] = 1;
    }
    for (int i = 0; i < board.size(); i++)
      for (int j = 0; j < board[0].size(); j++) {
        current.push_back(board[i][j]);
        vis[i][j] = 1;
        dfs(i, j);
        vis[i][j] = 0;
        current.pop_back();
      }
    return answer;
  }
};
// @lc code=end
