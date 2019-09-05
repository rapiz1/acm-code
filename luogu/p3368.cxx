/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Thu, 05 Sep 2019 17:44:09 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
inline int lowbit(int x) {
  return x&-x;
}
const int N = 5e5 + 10;
int n, m, a[N];
void add(int x, int k) {
  if (x <= 0) return;
  for (;x<= n; x+= lowbit(x)) {
    a[x] += k;
  }
}
int pre(int x) {
  if (x <= 0) return 0;
  int ret = 0;
  for(;x;x-=lowbit(x)) {
    ret += a[x];
  }
  return ret;
}
void show() {
  for (int i = 1; i <= n; i++) {
    printf("%d%c", pre(i), " \n"[i==n]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int prex = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    add(i, x - prex);
    prex = x;
  }
  while (m--) {
    int op, x, y, z;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", &x, &y, &z);
      add(x, z);
      add(y+1, -z);
    }
    else if (op == 2) {
      scanf("%d", &x);
      printf("%d\n",pre(x));
    }
  }
}

