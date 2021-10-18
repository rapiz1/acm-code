#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pa;
struct F {
  int pos;
  bool is_l;
  bool operator<(const F& rhs) const { return pos < rhs.pos; }
};
int get_coordinate(vector<F>& f) {
  if (f.empty()) return 0;
  sort(f.begin(), f.end());
  ll right_set = 0, left_set = 0;
  ll right_sz = 0, left_sz = 0;
  ll ans_sum = LONG_LONG_MAX, ans_pos = 0;
  for (auto e : f) {
    if (!e.is_l) continue;
    right_set += e.pos;
    right_sz++;
  }
  for (auto e : f) {
    int pos = e.pos;
    if (e.is_l) {
      right_set -= e.pos;
      right_sz--;
    } else {
      left_set += e.pos;
      left_sz++;
    }
    ll sum = pos * left_sz - left_set + right_set - pos * right_sz;
    if (sum < ans_sum) {
      ans_sum = sum;
      ans_pos = pos;
    }
  }
  return ans_pos;
}
pa solve() {
  int k;
  cin >> k;
  vector<F> x, y;
  for (int i = 0; i < k; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    x.push_back({a, 1});
    x.push_back({c, 0});
    y.push_back({b, 1});
    y.push_back({d, 0});
  }
  return {get_coordinate(x), get_coordinate(y)};
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    printf("Case #%d: ", i);
    auto x = solve();
    cout << x.first << " " << x.second << endl;
  }
}
