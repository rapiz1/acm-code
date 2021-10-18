#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pa;
int solve() {
  int n, k;
  vector<int> b;

  cin >> n >> k;
  int ans = n + 1;
  b.resize(n);
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<vector<pa>> rec_sort_by_l;
  vector<vector<pa>> rec_sort_by_r;
  vector<vector<int>> rec_sort_by_l_suf;
  vector<vector<int>> rec_sort_by_r_pre;
  rec_sort_by_l.resize(k + 1);
  rec_sort_by_r.resize(k + 1);
  rec_sort_by_l_suf.resize(k + 1);
  rec_sort_by_r_pre.resize(k + 1);
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += b[j];
      if (sum <= k) {
        rec_sort_by_l[sum].push_back(pa{i, j});
        rec_sort_by_r[sum].push_back(pa{i, j});
      } else
        break;
    }
  }

  for (int sum = 0; sum < rec_sort_by_l.size(); sum++) {
    auto& v = rec_sort_by_l[sum];
    if (v.empty()) continue;
    sort(v.begin(), v.end());
    auto& mv = rec_sort_by_l_suf[sum];
    mv.resize(v.size());
    for (int i = mv.size() - 1; i >= 0; i--) {
      mv[i] = v[i].second - v[i].first + 1;
      if (i != mv.size() - 1) mv[i] = min(mv[i], mv[i + 1]);
    }
  }

  auto compare_second = [](auto x, auto y) -> bool {
    return x.second < y.second;
  };

  auto compare_first = [](auto x, auto y) -> bool { return x.first < y.first; };

  for (int sum = 0; sum < rec_sort_by_r.size(); sum++) {
    auto& v = rec_sort_by_r[sum];
    if (v.empty()) continue;
    sort(v.begin(), v.end(), compare_second);
    auto& mv = rec_sort_by_r_pre[sum];
    mv.resize(v.size());
    for (size_t i = 0; i < mv.size(); i++) {
      mv[i] = v[i].second - v[i].first + 1;
      if (i) mv[i] = min(mv[i], mv[i - 1]);
    }
  }

  for (int sum = 0; sum < rec_sort_by_l.size(); sum++) {
    if (sum > k) continue;
    for (auto pa : rec_sort_by_l[sum]) {
      int need = k - sum;
      int alen = pa.second - pa.first + 1;
      if (need == 0) {
        ans = min(ans, alen);
      } else {
        size_t i;
        if (!rec_sort_by_l[need].empty()) {
          const auto& sort_by_l = rec_sort_by_l[need];
          i = upper_bound(sort_by_l.begin(), sort_by_l.end(),
                          pair<int, int>{pa.second, pa.second}, compare_first) -
              sort_by_l.begin();
          if (i != sort_by_l.size()) {
            int blen = rec_sort_by_l_suf[need][i];
            ans = min(ans, alen + blen);
          }
        }
        if (!rec_sort_by_r[need].empty()) {
          const auto& sort_by_r = rec_sort_by_r[need];
          i = lower_bound(sort_by_r.begin(), sort_by_r.end(),
                          pair<int, int>{pa.first, pa.first}, compare_second) -
              sort_by_r.begin();
          if (i != sort_by_r.size() && i > 0) {
            i--;
            int blen = rec_sort_by_r_pre[need][i];
            ans = min(ans, alen + blen);
          }
        }
      }
    }
  }

  return ans == n + 1 ? -1 : ans;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    printf("Case #%d: %d\n", i, solve());
  }
}
