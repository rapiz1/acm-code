/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Thu, 19 Sep 2019 17:45:14 +0800
 */
#include <iostream>
#include <vector>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int n, m1, m2, dis[N];
struct Edge {int u, v, w;};
vector<Edge> e;
inline bool shortpath(int s) {
  for (int i = 1; i <= n; i++) dis[i] = 1e9;
  dis[s] = 0;
  for (int k = 1; k <= n; k++) {
    for (int i = 0; i < (int)e.size(); i++) {
      if (dis[e[i].u] != 1e9 && dis[e[i].u] + e[i].w < dis[e[i].v]) {
        dis[e[i].v] = dis[e[i].u] + e[i].w;
        if (k == n) {
          return true;
        }
      }
    }
  }
  return false;
}
bool solve() {
  e.clear();
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= m1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e.push_back((Edge){u, v, w});
    e.push_back((Edge){v, u, w});
  }
  for (int i= 1; i <= m2; i++) {
    int u, v, w;cin >> u >> v >> w;
    e.push_back((Edge){u, v, -w});
  }
  //for (int i = 1; i <= n; i++) if (shortpath(i)) return true;
  return shortpath(1);
}
int main() {
  fastios;
  int ks; cin >> ks;
  while (ks--){
    cout << (solve() ? "YES" : "NO") << endl;
  }
}

