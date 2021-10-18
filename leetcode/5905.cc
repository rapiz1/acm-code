#include <bits/stdc++.h>
using namespace std;
class Solution {
  typedef struct Node {
    int first, second, third;
    bool operator<(const Node& rhs) const { return first > rhs.first; }
  } pa;
  typedef long long ll;
  priority_queue<pa> q;
  unordered_map<int, int> dis1, dis2;
  unordered_map<int, bool> vis[2];
  int change;
  int upround(int x, int y) { return (x + y - 1) / y * y; }
  int fixtime(int x) {
    if ((x / change) % 2) {
      if (x % change == 0) return x + change;
      return upround(x, change);
    } else {
      return x;
    }
  }

 public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> to;
    to.resize(n);
    for (auto e : edges) {
      int u = e[0] - 1, v = e[1] - 1;
      to[u].push_back(v);
      to[v].push_back(u);
    }
    this->change = change;
    for (int i = 0; i < n; i++) dis1[i] = dis2[i] = INT_MAX / 2;

    q.push({0, 0, 0});  // (2*change)*k -> green
    dis1[0] = 0;
    while (!q.empty()) {
      auto [dis, u, flag] = q.top();
      q.pop();
      if (dis2[u] < dis) continue;
      if (flag == 0 && vis[flag][u]) continue;
      vis[flag][u] = 1;
      // printf("reach %d with time %d, flag = %d\n", u, dis, flag);
      for (auto v : to[u]) {
        int now = fixtime(dis) + time;
        if (flag == 0 && now < dis1[v]) {
          dis2[v] = dis1[v];
          dis1[v] = now;
          q.push({now, v, 0});
          if (dis2[v] != INT_MAX / 2) q.push({dis2[v], v, 1});
        }
        if (now > dis1[v] && now < dis2[v]) {
          dis2[v] = now;
          q.push({now, v, 1});
        }
      }
    }
    return dis2[n - 1];
  }
};

int main() {
  Solution sol;
  int n = 6;
  vector<vector<int>> v = {{1, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 5}, {4, 6}};
  int time = 3, change = 100;
  cout << sol.secondMinimum(n, v, time, change);
}
