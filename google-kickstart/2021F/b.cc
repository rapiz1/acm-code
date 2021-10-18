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
    hi[l].push_back(h);
    hi[r + 1].push_back(-h);
  }
  ll ans = 0;
  priority_queue<int, vector<int>, greater<int>> bigger;
  priority_queue<int> smaller;
  ll lazy_size = 0;
  ll sum = 0;
  map<int, int> lazy_num;
  for (int i = 1; i <= d; i++) {
    ans = max(ans, sum);
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
