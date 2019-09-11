/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Mon, 09 Sep 2019 18:03:05 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 3000;
int n, m, s, t, dis[N];
bool vis[N];
struct Node {
  int u, w;
  bool operator<(const Node& rhs)const {
    return w > rhs.w;
  }
};
vector<Node> to[N];
priority_queue<Node> q;
int main() {
  fastios;
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) {
    int u, v, w; cin >>u >> v >> w;
    to[u].push_back((Node){v, w});
    to[v].push_back((Node){u, w});
  }
  q.push((Node){s, 0});
  while (!q.empty()) {
    Node x = q.top(); q.pop();
    int u = x.u, w = x.w;
    if (vis[u]) continue;
    vis[u] = 1;
    dis[u] = w;
    for (auto e : to[u]) {
      int v = e.u;
      if (!vis[v]) {
        q.push((Node){v, e.w + dis[u]});
      }
    }
  }
  cout << dis[t];
}

