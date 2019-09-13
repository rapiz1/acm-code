/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Fri, 13 Sep 2019 18:47:55 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 21;
int n, m, ans;
char mm[N][N];
void dfs(int x, int y) {
  mm[x][y] = '#';
  for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) if (abs(dx) + abs(dy) == 1) {
    int xx = x + dx, yy = y + dy;
    if (1 <= xx && xx <= n && 1 <= yy && yy <= m) {
      if (mm[xx][yy] == '.')
      dfs(xx, yy);
    }
  }
  ans++;
}
void solve() {
  for (int i = 1; i <= n; i++) {
    cin >> (mm[i] + 1);
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) if (mm[i][j] == '@') {
      dfs(i, j);
      break;
    }
  }
  cout << ans << endl;
}
int main() {
  while (cin >> m >> n) {
    if (!n || !m) break;
    solve();
  }
}

