/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Thu, 05 Sep 2019 12:17:18 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N];
int lowbit(int x) {
  return x&-x;
}
void add(int x, int v) {
  for (;x <= n;x+=lowbit(x)) {
    a[x] += v;
  }
}
int pre(int x) {
  int ret = 0;
  for(;x;x-=lowbit(x)) {
    ret += a[x];
  }
  return ret;
}
int main() {
  fastios;
  cin >> n >> m;
  for (int i = 1; i <= n; i++ ) {
    int x; 
    cin >> x;
    add(i, x);
  }
  while (m--) {
    int op, x, k;
    cin >> op >> x >> k;
    if (op == 1) {
      add(x, k);
    }
    else {
      cout << pre(k) - pre(x-1) << endl;
    }
  }
}

