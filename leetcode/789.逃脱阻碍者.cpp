#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=789 lang=cpp
 *
 * [789] 逃脱阻碍者
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    int x, y, time;
  };
  int dis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
  }
  bool danger(Node node, vector<vector<int>>& g) {
    for (auto v : g) {
      if (dis(node.x, node.y, v[0], v[1]) <= node.time) return true;
    }
    return false;
  }
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    int my_dis = dis(0, 0, target[0], target[1]);
    for (auto& v : ghosts) {
      if (dis(v[0], v[1], target[0], target[1]) <= my_dis) return false;
    }
    return true;
    /*
  map<pair<int, int>, bool> vis;
  queue<Node> q;
  q.push(Node{0, 0, 0});
  if (danger(Node{0, 0, 0}, ghosts)) return false;
  if (target[0] == 0 && target[1] == 0) return true;
  while (!q.empty()) {
    auto now = q.front();
    if (now.x == target[0] && now.y == target[1]) return true;
    q.pop();
    for (int dx = -1; dx <= 1; dx++)
      for (int dy = -1; dy <= 1; dy++)
        if (dx * dy == 0 && dx + dy) {
          int nx = now.x + dx, ny = now.y + dy;
          if (vis[pair<int, int>{nx, ny}]) continue;
          auto nn = Node{nx, ny, now.time + 1};
          if (danger(nn, ghosts)) continue;
          q.push(nn);
        }
  }
  */
    return false;
  }
};
// @lc code=end
