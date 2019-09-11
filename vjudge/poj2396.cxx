/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Wed, 11 Sep 2019 09:12:05 +0800
 */
#include <iostream>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 110;
int n, m;
char s[N][N];
bool vis[N][N];
void dfs(int x, int y) {
  vis[x][y] = 1;
  for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) if (dx || dy) {
    int nx = x + dx, ny = y + dy;
    if (s[nx][ny] == 'W' && !vis[nx][ny]) {
      dfs(nx, ny);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> (s[i] + 1);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j] && s[i][j] == 'W') {
        dfs(i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
}

