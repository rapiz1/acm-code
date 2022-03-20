#include <bits/stdc++.h>
using namespace std;
// n <= 21
int n;
vector<int> pods;
int ans;
typedef pair<int, int> pa;
unordered_set<int> vis[22];

const int BASE = 6000;
inline int comb(int x, int y) {
  // if (x > y) swap(x, y);
  return x * BASE + y;
}

void dfs(int pos, int a, int b) {
  if (a > b) swap(a, b);

  int hash = comb(a, b);
  if (vis[pos].count(hash)) return;
  vis[pos].insert(hash);
  if (a == b) ans = max(ans, a);
  if (pos >= n) return;

  dfs(pos + 1, a + pods[pos], b);
  dfs(pos + 1, a, b + pods[pos]);
  dfs(pos + 1, a, b);
}
int main() {
  cin >> n;
  pods.resize(n);
  for (int i = 0; i < n; i++) cin >> pods[i];
  dfs(0, 0, 0);
  cout << ans;
}
