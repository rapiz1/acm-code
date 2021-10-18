#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 10;
vector<int> hi[MAXN];
ll solve() {
  int n, d, k;
  cin >> d >> n >> k;
  for (int i = 1; i <= d; i++) hi[i].clear();
  for (int i = 1; i <= n; i++) {
    int l, r, h;
    cin >> h >> l >> r;
    for (int j = l; j <= r; j++) hi[j].push_back(h);
  }
  ll ans = 0;
  for (int i = 1; i <= d; i++) {
    ll today = 0;
    sort(hi[i].begin(), hi[i].end(), greater<int>{});
    for (int j = 0; j < k && j < hi[i].size(); j++) today += hi[i][j];
    ans = max(today, ans);
  }
  return ans;
}
int main() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    printf("Case #%d: %lld\n", i, solve());
  }
}
