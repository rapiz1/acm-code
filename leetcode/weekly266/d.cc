#include <bits/stdc++.h>
using namespace std;
class Solution {
  typedef pair<int, int> pa;
  vector<int> values;
  vector<pa> to[1010];
  int maxTime;
  int ans = 0;
  int vis[1010] = {};
  void dfs(int u, int val, int t) {
    if (t >= maxTime) return;
    if (!u) ans = max(ans, val);
    if (t * 2 <= maxTime) {
      ans = max(ans, val);
    }
    for (auto e : to[u]) {
      int v = e.first;
      int w = e.second;
      vis[v]++;
      dfs(v, val + (vis[v] != 1 ? 0 : values[v]), t + w);
      vis[v]--;
    }
  }

 public:
  int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges,
                         int maxTime) {
    this->values = values;
    this->maxTime = maxTime;
    for (auto& e : edges) {
      to[e[0]].push_back({e[1], e[2]});
      to[e[1]].push_back({e[0], e[2]});
    }
    vis[0]++;
    dfs(0, values[0], 0);
    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> val = {0, 32, 10, 43};
  vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 15}, {0, 3, 10}};
  sol.maximalPathQuality(val, edges, 49);
}
