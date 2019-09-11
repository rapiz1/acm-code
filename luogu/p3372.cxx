/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 07 Sep 2019 21:28:15 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lch (o<<1)
#define rch ((o<<1)|1)
typedef long long ll;
using namespace std;
const int N = 100010, ST = N << 3;
int n, m;
ll sum[ST], av[ST];
void up(int o, int l, int r) {
  sum[o] = sum[lch] + sum[rch] + av[o]*(r - l + 1);
}
void down(int o, int l, int r) {
  int mid = (l + r) >> 1;
  av[lch] += av[o];
  up(lch, l, mid);
  av[rch] += av[o];
  up(rch, mid+1, r);
  av[o] = 0;
}
void add(int o, int l, int r, int q1, int q2, int v) {
  if (q1 <= l && r <= q2) {
    av[o] += v;
  }
  else {
    int mid = (l + r) >> 1;
    if (q1 <= mid) add(lch, l, mid, q1, q2, v);
    if (mid + 1 <= q2) add(rch, mid+1, r, q1, q2, v);
  }
  up(o, l, r);
}
ll query(int o, int l, int r, int q1, int q2) {
  if (q1 <= l && r <= q2) {
    return sum[o];
  }
  else {
    down(o, l, r);
    ll ret = 0;
    int mid = (l + r) >> 1;
    if (q1 <= mid) ret += query(lch, l, mid, q1, q2);
    if (mid+1 <= q2) ret += query(rch, mid+1, r, q1, q2);
    return ret;
  }
}
int main() {
  fastios;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    add(1, 1, n, i, i, x);
  }
  while (m--) {
    int o, x, y , k;
    cin >> o >> x >> y;
    if (o == 1) {
      cin >> k;
      add(1, 1, n, x, y, k);
    }
    else if (o == 2) {
      cout << query(1, 1, n, x, y) << endl;
    }
  }
}

