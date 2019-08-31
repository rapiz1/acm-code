/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 31 Aug 2019 19:05:57 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
int n, l[N], r[N];
ll f[N][2];
vector<int> to[N];
void dfs(int u, int fa) {
  f[u][0] = 0, f[u][1] = 0;
  for (auto v:to[u]) if (v != fa) {
    dfs(v, u);
    f[u][0] += max(abs(l[u] - l[v]) + f[v][0], abs(l[u] - r[v]) + f[v][1]);
    f[u][1] += max(abs(r[u] - l[v]) + f[v][0], abs(r[u] - r[v]) + f[v][1]);
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    to[i].clear();
  }
  cin >> n;
  for (int i = 1; i < n;i++) {
    int u, v;
    cin >> u >> v;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  dfs(1, 0);
  cout << max(f[1][0], f[1][1]) << endl;
}
int main() {
  fastios;
  int t; cin >> t;
  while (t--) {
    solve();
  }
}

