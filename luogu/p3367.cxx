/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Thu, 05 Sep 2019 17:33:13 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 1e4 + 10;
int n, m, p[N];
int find(int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) p[i] = i;
  while (m--) {
    int z, x, y;
    cin >> z >> x >> y;
    int a = find(x), b = find(y);
    if (z == 1) {
      p[a] = b;
    }
    else {
      printf("%s\n", a == b ? "Y" : "N");
    }
  }
}
