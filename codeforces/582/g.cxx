/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 07 Sep 2019 12:19:45 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 4e5 + 10;
int n, m, a[N], sz[N], p[N];
ll rec[N];
struct Ele {
  int u, v, w, q;
}e[N];
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
int main() {
  fastios;
  cin >> n >> m;
  for (int i =1; i <= n; i++) p[i] = i, sz[i] = 1;
  for (int i = 1; i < n; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  for (int i = 1; i <= m; i++) {
    cin >> e[i + n - 1].w;
    e[i + n - 1].q = i;
  }
  sort(e + 1, e + n + m, [](auto a, auto b) {
      return a.w != b.w ? a.w < b.w : (a.u > b.u);
      });
  /*
  for (int i = 1; i < n + m; i++) {
    xxx(i);
    xxx(e[i].u);
    xxx(e[i].v);
    xxx(e[i].w);
  }
  */
  ll ans = 0;
  for (int i = 1; i < n + m; i++) {
    if (e[i].q) {
      rec[e[i].q] = ans;
    }
    else {
      int x = find(e[i].u), y = find(e[i].v);
      p[x] = y;
      ans += (ll)sz[x]*sz[y];
      sz[y] += sz[x];
    }
  }
  for (int i = 1; i <= m; i++) cout << rec[i] << " ";
}

