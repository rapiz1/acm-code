/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Thu, 22 Aug 2019 22:39:35 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
typedef pair<int, int> poi;
const int N = 60;
int n, m, a[N][N], ans, b[N][N];
vector<poi> s;
void paint(int x, int y) {
  b[x][y] = 1;
  if (x+1<=n) b[x+1][y] = 1;
  if (y+1<=m) b[x][y+1] = 1;
  if (x+1<=n && y + 1 <=m) b[x+1][y+1] = 1;
  s.push_back(poi(x, y));
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i+1 <= n; i++) {
    for (int j = 1; j+1 <= m; j++) {
      if (a[i][j] && a[i+1][j+1] && a[i+1][j] && a[i][j+1]) {
        paint(i, j);
      }
    }
  }
//  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cout << b[i][j] << (j == m ? "\n" : " ");
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
    if (a[i][j] != b[i][j]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << s.size() << endl;
  for (auto x:s) {
    cout << x.first << " "<<x.second << endl;
  }
}

