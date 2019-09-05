/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Thu, 05 Sep 2019 22:05:11 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
int n, a[N], vis[N], dfn[N], ans = 1e9, clk;
void dfs(int u) {
  vis[u] = 1;
  dfn[u] = ++clk;
  if (vis[a[u]] == 0) {
    dfs(a[u]);
  }
  else if (vis[a[u]] == 1) {
    ans = min(ans, dfn[u] - dfn[a[u]] + 1);
  }
  vis[u] = 2;
}
int main() {
  fastios;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) if (!vis[i]) {
    dfs(i);
  }
  cout << ans << endl;
}

