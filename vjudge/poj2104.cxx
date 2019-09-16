/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sun, 15 Sep 2019 20:58:10 +0800
 */
#pragma GCC optimize(3)
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
namespace IO {
  const int LEN = 1<<15;
  char buf[LEN], *s, *t;
  inline char gc() {
    if (s == t) t = (s=buf) + fread(buf, 1, LEN, stdin);
    return *s++;
  }
  inline int gi() {
    int x = 0, rev = 1, ch = gc();
    while (!isdigit(ch)) {
      if (ch == '-') rev = -1;
      ch = gc();
    }
    while (isdigit(ch)) {
      x=x*10+ch-'0';
      ch=gc();
    }
    return x*rev;
  }
}
using IO::gi;
const int N = 2e5 + 10;
int B, n, m, a[N], l, r, k,b[N], all[N];
void init() {
  memcpy(b, a, sizeof a);
  memcpy(all,a, sizeof a);
  sort(all + 1, all + 1 + n);
  for (int i = 1; i <= n; i = i/B*B + B) {
    int j = min(i/B*B + B, n + 1);
    sort(b + i, b + j);
  }
}
inline int check(int x) {
  int ret = 0, ll = l/B*B + B - 1, rr = r/B*B;
  if (l/B != r/B) {
    for (int i = l; i <= ll; i++) {
      ret += x >= a[i];
    }
    for (int i = rr; i <= r; i++) {
      ret += x >= a[i];
    }
    for (int i = l/B + 1; i < r/B; i++)  {
      int lb = max(i*B, 1), ub = min(lb + B, n + 1);
      ret += upper_bound(b + lb, b + ub, x) - (b + lb);
    }
  }
  else {
    for (int i = l; i <= r; i++) {
      ret += x >= a[i];
    }
  }
  return ret;
}
void solve() {
  int xl = 1, xr = n;
  while (xl < xr) {
    int tar = (xl + xr) >> 1;
    if (check(all[tar]) >= k) {
      xr = tar;
    }
    else {
      xl = tar + 1;
    }
  }
  printf("%d\n", all[xl]);
}
int main() {
  n = gi(), m = gi();
  B = max(sqrt(n*log2(n)), 1.0);
  for (int i = 1; i <= n; i++) a[i] = gi();
  init();
  while (m--) {
    l = gi(), r = gi(), k = gi();
    solve();
  }
}

