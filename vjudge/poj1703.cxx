/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Thu, 19 Sep 2019 20:34:33 +0800
 */
#include <iostream>
#include <cstdio>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 1e5 + 10, SZ = N << 1;
int n, m, p[SZ];
//2*x - 1 -> a  2*x -> b
int find(int x) {return x==p[x] ? x: p[x]=find(p[x]);}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n*2; i++) {
    p[i] = i;
  }
  while (m--) {
    char op; int a, b;
    scanf(" %c%d%d", &op, &a, &b);
    if (op == 'D') {
      int x = find(2*a - 1), y = find(2*b);
      p[x] = y;
      x = find(2*a), y = find(2*b - 1);
      p[x] = y;
    }
    else {
      int x = find(2*a), y = find(2*b);
      if (x == y) {
        puts("In the same gang.");
      }
      else {
        y = find(2*b - 1);
        if (x == y) {
          puts("In different gangs.");
        }
        else {
          puts( "Not sure yet.");
        }
      }
    }
  }
}
int main() {
  fastios;
  int ks; scanf("%d", &ks);
  while (ks--) {
    solve();
  }
}

