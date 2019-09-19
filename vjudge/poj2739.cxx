/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Wed, 18 Sep 2019 22:24:18 +0800
 */
#include <vector>
#include <iostream>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int V = 1e4 + 10;
vector<int> prime;
bool vis[V];
int n;
void init() {
  for (int i = 2; i < V; i++) {
    if (!vis[i]) {
      prime.push_back(i);
    }
    for (int j = i + i; j < V; j += i) vis[j] = 1;
  }
}
void solve(){
  int ans = 0;
  for (int i = 0, j = 1, s = 0; j < (int)prime.size(); j++) {
    s += prime[j - 1];
    while (s > n && i < j) s -= prime[i++];
    if (s == n) ans++;
  }
  cout << ans << endl;
}
int main() {
  fastios;
  init();
  while (cin >> n) {
    if (!n) break;
    solve();
  }
}

