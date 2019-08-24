/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Sat, 24 Aug 2019 14:07:39 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const ll MOD = 998244353;
const int N = 1010;
int n, m;
ll ans;
struct Edge {
  int v, w;
};
struct Node {
  int u, p;
  ll l;
  bool operator<(const Node& rhs)const {
    if (l != rhs.l) return l > rhs.l;
    else return p > rhs.p;
  }
};
vector<Edge> to[N];
priority_queue<Node> que;
bool vis[N];
ll dis[N];
int mnp[N];
void calc(int s) {
  //cout << "source:" << s << endl;
  while (!que.empty()) que.pop();
  memset(vis, 0, sizeof(bool)*(n+1));
  memset(dis, 0x3f, sizeof(ll)*(n+1));
  memset(mnp, 0x3f, sizeof(int)*(n+1));
  que.push(Node({s, 0, 0}));
  dis[s] = 0;
  while (!que.empty()) {
    Node nu = que.top();que.pop();
    int u = nu.u, p = nu.p;
    ll l = nu.l;
    if (vis[u]) continue;
    vis[u] = 1;
    dis[u] = l;
    mnp[u] = p;
    for (auto& e:to[u]) {
      int v = e.v;
      if (vis[v]) continue;
      dis[v] = l + e.w;
      que.push(Node({v, max(p, u == s ? 0 : u), l + e.w}));
    }
  }
  for (int i = 1; i <= n; i++) {
    //cout << i << ": dis:" << dis[i] << " mnp:" << mnp[i] << endl;
    ans = (ans + mnp[i])%MOD;
  }
}
void solve() {
  ans = 0;
  for (int i = 1; i <= n; i++) to[i].clear();
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    to[u].push_back(Edge({v, w}));
    to[v].push_back(Edge({u, w}));
  }
  for (int i = 1; i <= n; i++) {
    calc(i);
  }
  cout << ans << endl;
}
int main() {
  iosfast;
  int ks; cin >> ks;
  while (ks--) {
    solve();
  }
}

