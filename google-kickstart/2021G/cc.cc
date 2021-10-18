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
  unordered_map<int, vector<pa>> rec;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += b[j];
      rec[sum].push_back(pa{i, j});
    }
  }
  for (auto e : rec) {
    int sum = e.first;
    if (sum > k) continue;
    for (auto pa : rec[sum]) {
      int need = k - sum;
      int alen = pa.second - pa.first + 1;
      if (need == 0) {
        ans = min(ans, alen);
      } else {
        for (auto ppa : rec[need]) {
          if (max(ppa.first, pa.first) <= min(ppa.second, pa.second)) continue;
          int blen = ppa.second - ppa.first + 1;
          ans = min(ans, alen + blen);
          cout << pa.first << " " << pa.second << " " << ppa.first << " "
               << ppa.second << endl;
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
