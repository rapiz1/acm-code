/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Tue, 17 Sep 2019 10:58:34 +0800
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 110;
struct Edge {int u, v, w;
  bool operator<(const Edge& rhs)const {
    return w < rhs.w;
  }
};
vector<Edge> e;
int p[N], n;
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
void solve() {
  int ans = 0;
  for (int i = 1; i <= n; i++) p[i] = i;
  e.clear();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if (i != j) e.push_back((Edge){i, j, x});
    }
  }
  sort(e.begin(), e.end());
  for (int i = 0; i < (int)e.size(); i++) {
    int x = find(e[i].u), y = find(e[i].v);
    if (x != y) {
      p[x] = y;
      ans += e[i].w;
    }
  }
  cout << ans << endl;
}
int main() {
  fastios;
  while (cin >> n) {
    solve();
  }
}

