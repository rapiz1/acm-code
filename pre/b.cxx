#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
using namespace std;
typedef long long ll;
const int N = 1010;
typedef pair<int, int> pa;
int n, m, aa, ab, p[N];
pa a[N], b[N];
inline int dis(pa x, pa y) {
  return abs(x.first - y.first) + abs(x.second - y.second);
}
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
vector<int> tmp[N];
bool vis[N];
void pinit(int n) {
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= n; i++) tmp[i].clear();
}
inline bool check(int x) {
  pinit(n);
  for (int i = 1; i <= n; i++ ) {
    for (int j = i + 1; j <= n; j++) {
      if (dis(a[i], a[j]) <= x) {
        int c = find(i), v = find(j);
        p[c] = v;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    tmp[find(i)].push_back(i);
  }
  for (int i = 1; i <= n; i++) if (tmp[i].size()) {
    memset(vis, 0, sizeof vis);
    for (auto now : tmp[i]) {
      for (int j = 1; j <= m; j++) {
        if (dis(a[now], b[j]) <= x) {
          vis[j] = 1;
        }
      }
    }
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      cnt += vis[j];
    }
    //xxx(cnt);
    if (cnt != m) return 0;
  }
  return 1;
}
bool solve() {
  int l = 0, r = 2000;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }
  aa = l;
  ab = l + 1;
  //xxx(aa);
  //xxx(ab);
  pinit(m);
  for (int i = 1; i <= m; i++) {
    tmp[i].clear();
    for (int j = i + 1; j <= m; j++) {
      if (dis(b[i], b[j]) <= ab) {
        int c = find(i), v = find(j);
        p[c] = v;
          }
    }
  }
  for (int i = 1; i <= m; i++) {
    tmp[find(i)].push_back(i);
  }
  bool flag = 0;
  for (int i = 1; i <= m; i++) if (tmp[i].size()) {
    memset(vis, 0, sizeof vis);
    for (auto now : tmp[i]) {
      for (int j = 1; j <= n; j++) {
        if (dis(b[now], a[j]) <= ab) {
          //xxx(now);xxx(j);
          vis[j] = 1;
        }
      }
    }
    int cnt = 0;
    for (int j = 1; j <= n; j++) cnt += vis[j];
    //xxx(cnt);
    if (cnt < n) flag = 1;
  }
  return flag;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  for (int i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;
  cout << solve();
}
