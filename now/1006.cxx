/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Sun, 25 Aug 2019 15:17:25 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define iosfast ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int N = 310;
struct UFS {
  int n, p[N];
  void init(int nn) {
    n = nn;
    for (int i = 1; i <= n; i++) p[i] = i;
  }
  int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
  }
  void uni(int x, int y) {
    p[find(x)] = find(y);
  }
  bool check() {
    int x = find(1);
    for (int i = 2; i <= n; i++) {
      if (find(i) != x) return false;
    }
    return true;
  }
}ufs[N];
struct Edge {
  int u, v;
}e[N];
int n, m, k;
bool check() {
  for (int i = 1; i <= k; i++) ufs[i].init(n);
  for (int i = 1; i <= m; i++) {
    int u = e[i].u, v = e[i].v;
    for (int j = 1; j <= k; j++) {
      int x = ufs[j].find(u), y = ufs[j].find(v);
      if (x == y) continue;
      else {
        ufs[j].uni(x, y);
        break;
      }
    }
  }
  for (int i = 1; i <= k; i++) if (ufs[i].check() == 0) {
    return false;
  }
  return true;
}
void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    e[i] = {u, v};
  }
  int fk = 3000;
  while (fk--) {
    random_shuffle(e + 1, e + 1 + m);
    if (check()) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}
int main() {
  int ks; cin >> ks;
  while (ks--) {
    solve();
  }
}

