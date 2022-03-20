#include <bits/stdc++.h>
using namespace std;
const int N = 30000 + 5;

int f[N * 2], a[N], n, m;
int ans = 0;

void dfs1(int c, int t, int maxn) {
  if (c >= m) {
    f[t + N] = max(f[t + N], maxn);
    if (t == 0) ans = max(ans, maxn / 2);
    return;
  }
  dfs1(c + 1, t + a[c], maxn + a[c]);
  dfs1(c + 1, t - a[c], maxn + a[c]);
  dfs1(c + 1, t, t);
}
void dfs2(int c, int t, int maxn) {
  if (c > n) {
    if (f[t + N])
      ans = max(ans, (f[t + N] + maxn) / 2);
    else if (t == 0)
      ans = max(ans, maxn / 2);
    return;
  }
  dfs2(c + 1, t + a[c], maxn + a[c]);
  dfs2(c + 1, t - a[c], maxn + a[c]);
  dfs2(c + 1, t, t);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  m = n / 2;
  dfs1(1, 0, 0);
  dfs2(m, 0, 0);
  cout << ans << endl;
  return 0;
}
