/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Mon, 16 Sep 2019 12:27:37 +0800
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
namespace IO {
  const int L = 1 << 15;
  char buf[L], *s, *t;
  inline char gc() {
    if (s == t) t = (s=buf) + fread(buf, 1, L, stdin);
    if (s == t) {
      exit(0);
    }
    return *s++;
  }
  inline int gi() {
    int f = 1, ch = gc(), r = 0;
    while (!isdigit(ch)) {
      if (ch == '-') f = -1;
      ch = gc();
    }
    while (isdigit(ch)) r = r*10 + ch - '0', ch = gc();
    return r*f;
  }
}
using IO::gi;
const int N = 1e5 + 10;
int n;
int a[N], b[N], target;
inline int aa(int x) {return x > 0 ? x : -x;}
bool cmp(int a, int b) {
  return aa(a - target) < aa(b - target);
}
inline ll check(int x) {
  //xxx(x);
  ll ret = 0;
  for (int i = 1; i <= n; i++) {
    target = a[i];
    ret += (a + n + 1) - lower_bound(a + i + 1, a + n + 1, target + x, cmp);
    target = b[i];
    ret += (b + n + 1) - lower_bound(b + i + 1, b + n + 1, target + x, cmp);
  }
  //xxx(ret);
  return ret/2;
}
void solve() {
  for (int i = 1; i <= n; i++) {
    a[i] = gi();
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) b[i] = a[n - i + 1];
  int l = 0, r = a[n];
  ll bound = (ll)n*(n-1)/4 + 1;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid) >= bound) {
      l = mid;
    }
    else {
      r = mid - 1;
    }
  }
  printf("%d\n", l);
}
int main() {
  while (n = gi()) {
    if (!n) break;
    solve();
  }
}
