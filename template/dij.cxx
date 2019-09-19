/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Thu, 19 Sep 2019 20:03:56 +0800
 */
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 100000 + 10;
int n, m, s, dis[N];
bool vis[N];
struct Edge {int v, w;
  bool operator<(const Edge& rhs)const {
    return w > rhs.w;
  }
};
vector<Edge> to[N];
priority_queue<Edge> q;
void dij(vector<Edge> edges[N]) {
  memset(vis+1, 0, sizeof(int)*n);
  memset(dis+1, 0x3f, sizeof(int)*n);
  dis[s] = 0;
  q.push((Edge){s, 0});
  while (!q.empty()) {
    Edge e = q.top(); q.pop();
    int u = e.v;
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = 0; i < (int)edges[u].size(); i++) {
      int v = edges[u][i].v, w = edges[u][i].w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push((Edge){v, dis[v]});
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    to[u].push_back((Edge){v, w});
  }
  dij(to);
  for (int i  = 1; i <= n; i++) printf("%d ", dis[i]);
}

