/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Fri, 06 Sep 2019 17:33:15 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 1e4 + 10;
vector<int> to[N], tt;
int n, m, ans, na;
bool tak[N], vis[N];
bool dfs(int u, int co) {
  if (vis[u]) {
    return tak[u] == co;
  }
  tt.push_back(u);
  vis[u] = 1;
  tak[u] = co;
  na += co;
  for (auto v : to[u]) {
    if (!dfs(v, co^1)) {
      return false;
    }
  }
  return true;
}
bool solve() {
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      na = 0;
      if (dfs(i, 0))
        ans += min(na, (int)tt.size() - na);
      else return false;
      tt.clear();
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    to[v].push_back(u);
    to[u].push_back(v);
  }
  if (solve()) {
    printf("%d\n", ans);
  }
  else {
    puts("Impossible");
  }
}

