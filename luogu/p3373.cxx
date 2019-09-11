/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sun, 08 Sep 2019 21:55:33 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lch (o<<1)
#define rch ((o<<1)|1)
typedef long long ll;
using namespace std;
const int N = 1e5 + 10, ST = N << 2;
int n, m;
ll p, sum[ST], av[ST], mv[ST];
void up(int o, int l, int r) {
  sum[o] = sum[lch] + sum[rch];
  if (mv[o] != 1) sum[o] *= mv[o];
  if (av[o]) sum[o] += av[o]*(r - l + 1);
  sum[o] %= p;
}
// lazy tag form: x*mv[o] + av[o]
void mkav(int o, int l, int r, ll v) {
  av[o] = (av[o] + v)%p;
  sum[o] = (sum[o] + v*(r - l + 1))%p;
}
void mkmv(int o, int l, int r, ll v) {
  mv[o] = mv[o]*v%p;
  av[o] = av[o]*v%p;
  sum[o] = sum[o]*v%p;
}
void down(int o, int l, int r) {
  int mid = (l+r)>>1;
  if (mv[o] != 1) {
    if (l <= mid) mkmv(lch, l, mid, mv[o]);
    if (mid < r) mkmv(rch, mid+1, r, mv[o]);
    mv[o] = 1;
  }
  if (av[o]) {
    if (l <= mid) mkav(lch, l, mid, av[o]);
    if (mid < r) mkav(rch, mid+1, r, av[o]);
    av[o] = 0;
  }
}
void modify(int o, int l, int r, int q1, int q2, ll v, int op) {
  auto opf = op == 1 ? mkmv : mkav;
  if (q1 <= l && r <= q2) {
    opf(o, l, r, v);
  }
  else {
    down(o, l, r);
    int mid = (l + r) >> 1;
    if (q1 <= mid) modify(lch, l, mid, q1, q2, v, op);
    if (mid < q2) modify(rch, mid+1, r, q1, q2, v, op);
    up(o, l, r);
  }
}
ll query(int o, int l, int r, int q1, int q2) {
  if (q1 <= l && r <= q2) {
    return sum[o];
  }
  down(o, l, r);
  ll ret = 0;
  int mid = (l+r)>>1;
  if (q1 <= mid) ret += query(lch, l, mid, q1, q2);
  if (mid < q2) ret += query(rch, mid+1, r, q1, q2);
  return ret%p;
}
void show() {
  for (int i = 1; i <= n; i++) {
    cout << query(1, 1, n, i, i) << " ";
  }
  cout << endl;
}
void build(int o, int l, int r) {
  av[o] = 0;
  mv[o] = 1;
  sum[o] = 0;
  if (l != r) {
    int mid = (l + r) >> 1;
    if (l <= mid) build(lch, l, mid);
    if (mid < r) build(rch, mid+1, r);
    up(o, l, r);
  }
}
int main() {
  fastios;
  cin >> n >> m >> p;
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    x%= p;
    modify(1, 1, n, i, i, x, 2);
  }
  //show();
  while (m--) {
    int o, x, y, k;
    cin >> o >> x >> y;
    if (o == 3) {
      cout << query(1, 1, n, x, y) << endl;
    }
    else {
      cin >> k;
      modify(1, 1, n, x, y, k, o);
    }
    //show();
  }
}

