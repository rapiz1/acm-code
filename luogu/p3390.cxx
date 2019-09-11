/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Mon, 09 Sep 2019 21:28:36 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 1010, M = 1e9 + 7;
int n;
ll k;
struct mat {
  int n, m;
  ll a[N][N];
  void diag(int n) {
    this->n = n, this->m = n;
    for (int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) a[i][j] = i == j;
  }
  void init(int n, int m) {
    this->n = n, this->m = m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
      a[i][j] = 0;
    }
  }
  void cp(mat& rhs) {
    n = rhs.n, m = rhs.m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = rhs.a[i][j];
  }
}a, tmp;
void mul(mat& a, mat& b, mat& c) {
  c.init(a.n, b.m);
  for (int i = 1; i <= a.n; i++) for (int j = 1; j <= b.m; j++) for (int k = 1; k <= a.m; k++)
    c.a[i][j] += a.a[i][k]*b.a[k][j], c.a[i][j] %= M;
}
void matpow(mat& a, ll r, mat& ret) {
  ret.diag(a.n);
  for (;r;r>>=1) {
    if (r&1) {
      mul(ret, a, tmp);
      ret.cp(tmp);
    }
    mul(a, a, tmp);
    a.cp(tmp);
  }
}
int main() {
  fastios;
  cin >> n >> k;
  a.init(n, n);
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a.a[i][j];
  mat ret;
  matpow(a, k, ret);
  for (int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << ret.a[i][j] << " ";
    }
    cout << endl;
  }
}
