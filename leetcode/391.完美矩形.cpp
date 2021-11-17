#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */

// @lc code=start
class Solution {
  struct I {
    int x, start, end;
    bool ending;
    bool operator<(const I& rhs) const {
      return x == rhs.x ? (!ending < !rhs.ending) : x < rhs.x;
      // return x == rhs.x ? ending : x < rhs.x;
    };
  };
  typedef pair<int, int> pa;
  bool add(set<pa>& s, I i) {
    if (!i.ending) {
      if (s.count({i.start, i.end})) return false;
      s.insert({i.start, i.end});
      auto it = s.find({i.start, i.end});
      if (it != s.end()) {
        auto nxt = it;
        ++nxt;
        if (nxt != s.end()) {
          if (nxt->first == it->second) {
            i.end = nxt->second;
            s.erase(nxt);
            s.erase(it);
            s.insert({i.start, i.end});
            it = s.find({i.start, i.end});
          } else if (nxt->first < it->second) {
            return false;
          }
        }
      }
      if (it != s.begin()) {
        auto prev = it;
        --prev;
        if (prev->second == it->first) {
          i.start = prev->first;
          s.erase(prev);
          s.erase(it);
          s.insert({i.start, i.end});
        } else if (prev->second > it->first) {
          return false;
        }
      }
    } else {
      auto it = s.lower_bound({i.start, i.end});
      if (it == s.end() || it->first > i.start) it--;
      assert(it->first <= i.start && i.end <= it->second);
      auto bk = *it;
      s.erase(it);
      if (bk.first != i.start) s.insert({bk.first, i.start});
      if (i.end != bk.second) s.insert({i.end, bk.second});
    }
    return true;
  }

 public:
  vector<I> intervals;
  set<pa> s;
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    for (auto r : rectangles) {
      intervals.push_back(I{r[0], r[1], r[3], 0});
      intervals.push_back(I{r[2], r[1], r[3], 1});
    }
    sort(intervals.begin(), intervals.end());
    int l = -1;
    for (int i = 0, j; i < intervals.size(); i = j + 1) {
      for (j = i;
           j + 1 < intervals.size() && intervals[j + 1].x == intervals[i].x;
           j++)
        ;
      // printf("processing %d %d\n", i, j);
      for (int k = i; k <= j; k++)
        if (!add(s, intervals[k])) return false;
      // printf("processed %d\n", j);
      if (l == -1) {
        if (s.size() != 1)
          return false;
        else {
          auto x = *s.begin();
          l = x.second - x.first;
        }
      } else {
        if (s.size() == 0) {
          if (j != intervals.size() - 1) return false;
        } else {
          auto x = *s.begin();
          int nl = x.second - x.first;
          if (l != nl) return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end

Solution sol;
int main() {
  /*
  [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
  [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
  [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
  [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
  */
  /*
   vector<vector<int>> v = {
       {1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
       */
  vector<vector<int>> v = {{1, 1, 3, 3}, {1, 1, 3, 3}};
  for (int i = 1; i <= 100; i++) v.push_back({1, 1, 3, 3});
  sol.isRectangleCover(v);
}
