/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Fri, 13 Sep 2019 19:14:46 +0800
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 21;
int n, m, a[N][N], ans[N][N], sx, sy, tx, ty;
void dfs(int x, int y, int s) {
  //xxx(x); xxx(y); xxx(s);
  if (s > 10) return;
  ans[x][y] = s;
  if (a[x][y] == 3) return;
  for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++)
    if (abs(dx) + abs(dy) == 1) {
      int xx = x, yy = y;
      bool first = 1;
      while (1) {
        int nx = xx + dx, ny = yy + dy;
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
          if (a[nx][ny] == 1) {
            if (first) break;
            a[nx][ny] = 0;
            dfs(xx, yy, s + 1);
            a[nx][ny] = 1;
            break;
          }
          else if (a[nx][ny] == 3) {
            ans[nx][ny] = min(ans[nx][ny], s + 1);
            return;
          }
          xx = nx, yy = ny;
        }
        else {
          break;
        }
        first = 0;
      }
    }
}
void solve() {
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
    if (a[i][j] == 2) sx = i, sy = j;
    else if (a[i][j] == 3) tx = i, ty = j;
  }
  memset(ans, 0x3f, sizeof ans);
  dfs(sx, sy, 0);
  if (ans[tx][ty] > 10) {
    ans[tx][ty] = -1;
  }
  cout << ans[tx][ty] << endl;
}
int main() {
  while (cin >> m >> n) {
    if (n && m)
      solve();
    else break;
  }
}

