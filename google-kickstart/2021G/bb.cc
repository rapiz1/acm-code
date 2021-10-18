#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pa;
int get_coordinate(vector<pa>& f) {
  ll ans_sum = 1e9, ans_pos = 0;
  for (int i = -100; i <= 100; i++) {
    ll sum = 0;
    for (auto e : f) {
      if (e.first <= i && i <= e.second) continue;
      sum += min(abs(i - e.first), abs(i - e.second));
    }
    if (sum < ans_sum) {
      ans_sum = sum;
      ans_pos = i;
    }
  }
  return ans_pos;
}
pa solve() {
  int k;
  cin >> k;
  vector<pa> x, y;
  for (int i = 0; i < k; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    x.push_back(pa{a, c});
    y.push_back(pa{b, d});
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
