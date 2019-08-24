/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Fri, 23 Aug 2019 12:09:45 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
int head, nxt[N], pre[N];
int n, m;
void show() {
  for (int x = head;x;x=nxt[x]) {
    printf("%d%c", x, " \n"[nxt[x] == 0]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int pp = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (i == 1) {
      head = x;
    }
    else {
      pre[x] = pp;
      nxt[pp] = x;
    }
    pp = x;
  }
//  show();
  while (m--) {
    int x;
    scanf("%d", &x);
    if (x==head) continue;
    nxt[pre[x]] = nxt[x];
    pre[nxt[x]] = pre[x];
    nxt[x] = head;
    pre[head] = x;
    head = x;
    pre[x] = 0;
//    show();
  }
  for (int x = head;x;x=nxt[x]) {
    printf("%d ", x);
  }
}
