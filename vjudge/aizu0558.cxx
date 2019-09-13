/*
 *     ____              _    
 *    / __ \____ _____  (_)___ *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Fri, 13 Sep 2019 19:55:31 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 1010;
int n, m, dd[4][2] = {
  {1, 0},
  {0, 1},
  {-1, 0},
  {0, -1}
}, fac;
char mm[N][N];
struct Node {
  int x, y, s, hp;
};
queue<Node> q;
bool vis[N][N][10];
int main() {
  cin >> n >> m >> fac;
  Node start;
  for (int i = 1; i <= n; i++) {
    cin >> (mm[i] + 1);
    for (int j = 1; j <= m; j++) {
      if (mm[i][j] == 'S') {
        start.x = i;
        start.y = j;
      }
    }
  }
  start.s = 0;
  start.hp = 1;
  q.push(start);
  while (!q.empty()) {
    Node u = q.front(); q.pop();
    vis[u.x][u.y][u.hp] = 1;
    //xxx(u.x);xxx(u.y);xxx(u.hp);xxx(u.s);
    if (u.hp == fac +1) {
      cout << u.s << endl;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int nx = u.x + dd[i][0], ny = u.y + dd[i][1], nhp = u.hp;
      if (1 <= nx && nx <= n && 1 <= ny && ny <= m){
        if (mm[nx][ny] != 'X') {
          if (mm[nx][ny] >= '1' && mm[nx][ny] <= '9') {
            int idx = mm[nx][ny] - '1' + 1;
            if (u.hp == idx) nhp++;
          }
          if (!vis[nx][ny][nhp]) {
            vis[nx][ny][nhp] = 1;
            q.push((Node){nx, ny, u.s + 1, nhp});
          }
        }
      }
    }
  }
}
