#include <bits/stdc++.h>
using namespace std;
class Solution {
  int n, pn, start = -1, end = -1;
  vector<int> in, out;
  vector<vector<int>> to;
  unordered_map<int, int> sv_rec;
  vector<vector<int>> ans;
  vector<vector<int>>* ppairs;
  void dfs(int u) {
    while (!to[u].empty()) {
      int v = to[u].back();
      to[u].pop_back();
      dfs(v);
    }
    if (u < pn) {
      ans.push_back((*ppairs)[u]);
    }
  }

 public:
  vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    this->ppairs = &pairs;
    pn = n = pairs.size();
    in.resize(n * 3);
    out.resize(n * 3);
    to.resize(n * 3);
    for (int i = 0; i < pairs.size(); i++) {
      auto& p = pairs[i];
      if (!sv_rec.count(p[0])) {
        sv_rec[p[0]] = n++;
      }
      int u = sv_rec[p[0]];
      to[u].push_back(i);
      out[u]++;

      if (!sv_rec.count(p[1])) {
        sv_rec[p[1]] = n++;
      }
      u = sv_rec[p[1]];
      to[i].push_back(u);
      in[u]++;

      in[i]++;
      out[i]++;
    }
    for (int i = 0; i < n; i++) {
      if (in[i] == out[i]) continue;
      if (in[i] == out[i] + 1) {
        // assert(end == -1);
        end = i;
      }
      if (in[i] + 1 == out[i]) {
        // assert(start == -1);
        start = i;
      }
    }
    if (start == -1) start = end = 0;
    dfs(start);
    reverse(ans.begin(), ans.end());
    ans.resize(pn);
    return ans;
  }
};
Solution sol;
vector<vector<int>> a = {};
int main() {
  // a = {{1, 2}, {2, 3}, {3, 1}};
  a = {{8, 0}, {0, 7}, {7, 8}, {8, 7}, {7, 0}, {0, 5}, {5, 0}, {0, 8}, {8, 5}};
  // for (int i = 1; i <= int(1e5); i++) a.push_back(vector<int>{i, i + 1});
  sol.validArrangement(a);
}
