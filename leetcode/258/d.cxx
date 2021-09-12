#include <bits/stdc++.h>
using namespace std;
class Solution {
  static const int MAXN = 1e5 + 10;
  static const int MAXV = 1e5 + 10;
  int s[MAXV];
  inline int lowbit(int x) { return x & -x; }
  int pre(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += s[x];
    return ret;
  }
  int sum(int l, int r) {
    if (l) return pre(r) - pre(l - 1);
    return pre(r);
  }
  int full(int l, int r) { return sum(l, r) == r - l + 1; }
  void add(int x, int v) {
    for (; x < MAXV; x += lowbit(x)) s[x] += v;
  }
  int findmin(int x, int y) {
    // return missing number in s[x...y]
    int l = x, r = y;
    while (l < r) {
      int mid = l + r >> 1;
      if (full(l, mid))
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }
  vector<int> dfn;
  typedef pair<int, int> pa;
  vector<pa> intervals;
  vector<int> child[MAXN];

  void dfs(int now) {}

 public:
  vector<int> smallestMissingValueSubtree(vector<int>& parents,
                                          vector<int>& nums) {
    dfn.reserve(parents.size());
    intervals.reserve(parents.size());
    int n = parents.size();
    int rt = -1;
    for (int i = 0; i < n; i++) {
      if (parents[i] == -1) {
        rt = i;
      }
      child[parents[i]].push_back(i);
    }
    dfs(rt);
  }
};
int main() {}
