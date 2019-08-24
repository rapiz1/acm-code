/**
*     ____              _    
*    / __ \____ _____  (_)___
*   / /_/ / __ `/ __ \/ /_  /
*  / _, _/ /_/ / /_/ / / / /_
* /_/ |_|\__,_/ .___/_/ /___/
*            /_/             
*           code@rapiz.me
*          Tue, 20 Aug 2019 22:55:07 +0800
*/
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
const int N = 110;
int n, m, e[N][N], p[int(1e6+10)], dis[N][N], dp[int(1e6 + 10)], pre[int(1e6+10)];
struct FOO {
  int value, source;
  FOO(int v, int s):value(v), source(s) {}
  bool operator<(const FOO& rhs)const {
    return value > rhs.value;
  }
};
priority_queue<FOO> q;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin.ignore();
    char ch;
    for (int j = 1; j <= n; j++) cin >> ch, e[i][j] = ch - '0' || i == j;
  }
  memset(dis, 0x3f, sizeof dis);
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
    if (e[i][j]) dis[i][j] = 1;
  }
  for (int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for (int j = 1; j <=n;j ++) 
    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> p[i];
  memset(dp, 0x3f, sizeof dp);
  dp[1] = 1;
  q.push(FOO(1, 1));
  for (int i = 2; i <= m; i++) {
    FOO ele = q.top();
    q.pop();
    while (!q.empty() && i - ele.source != dis[p[ele.source]][p[i]]) {
      ele = q.top();
      q.pop();
    }
    q.push(ele);
    int value, source;
    pre[i] = ele.source;
    value = ele.value + 1; 
    source = i;
    dp[i] = value;
    q.push(FOO(value, source));
//    printf("dp[%d]:%d\n", i, dp[i]);
  }
  /*
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = min(dp[i][j], dp[i-1][j]);
      pre[i][j] = pre[i-1][j];
      while (!q.empty()) {
        FOO ele = q.front();
        int u = p[k], v = p[ele.source];
        if (dis[u][v] == j - k) {
          if (dp[i-1][k] + 1 < dp[i][j]) {
            dp[i][j] = min(dp[i][j], dp[i-1][k] + 1);
            pre[i][j] = k;
            q.push(FOO(dp[i][j], j));
          }
        }
      }
    }
  }
  */
  std::vector<int> path;
  for (int x = m, i = m; i >= 1; i--) {
    if (p[x] == 0) break;
    path.push_back(p[x]);
    x = pre[x];
  }
  cout << dp[m] << endl;
  for (int i = path.size() - 1; i >= 0; i--)
  {
    cout << path[i] << " ";
  }
}

