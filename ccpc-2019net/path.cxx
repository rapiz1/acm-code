/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Fri, 23 Aug 2019 15:01:02 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
const int N = 5e4 + 10, K = 2.5*1e5 + 10;
int n, m, q, mxk, k[N];
ll ans[K];
struct Edge {
  int u, v, w;
  bool operator<(const Edge& rhs)const {return w < rhs.w;}
};
struct Ele {
  int ver, idx;
  ll len;
  Ele(int ver, int idx, ll len):ver(ver), idx(idx), len(len) {}
  bool operator<(const Ele& rhs)const {
    return len > rhs.len;
  }
  void print() {
    printf("ver:%d idx:%d len:%lld\n", ver, idx, len);
  }
};
vector<Edge> to[N];
priority_queue<Ele> que;
void calc() {
  for (int u = 1; u <= n; u++) {
    if (to[u].size()) que.push(Ele(u, 0, to[u][0].w));
  }
  int cnt = 0;
  while(cnt < mxk) {
    Ele top = que.top(); que.pop();
//    top.print();
    int ver = top.ver, idx = top.idx;
    ll len = top.len;
    ans[++cnt] = len;
    if (idx+1 < (int)to[ver].size()) {
      que.push(Ele(ver, idx+1, len - to[ver][idx].w + to[ver][idx+1].w));
    }
    {
      auto& e = to[ver][idx];
      if (to[e.v].size()) que.push(Ele(e.v, 0, top.len + to[e.v][0].w));
    }
  }
}
void solve() {
  while (!que.empty()) que.pop();
  for (int i = 1; i <= n; i++) to[i].clear();
  mxk = 0;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    to[u].push_back({u, v, w});
  }
  for (int i = 1; i <= n; i++) {
    sort(to[i].begin(), to[i].end());
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d", k + i);
    mxk = max(mxk, k[i]);
  }
  calc();
  for (int i = 1; i <= q; i++) {
    printf("%lld\n", ans[k[i]]);
  }
}
int main() {
  int ks; scanf("%d", &ks);
  while (ks--) {
    solve();
  }
}

