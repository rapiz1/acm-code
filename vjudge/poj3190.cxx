/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 14 Sep 2019 08:31:08 +0800
 */
#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 5e4 + 10;
struct pa {
  int first, second, id, ans;
};
struct T {
  int id, time;
  bool operator<(const T& rhs)const {
    return time > rhs.time;
  }
};
bool cmp1(pa x, pa y) {
      if (x.first != y.first) return x.first < y.first;
      else return x.second < y.second;
}
bool cmp2(pa x, pa y) {
  return x.id < y.id;
}
priority_queue<T> q;
int n;
pa a[N];
int main() {
  fastios;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second, a[i].id = i;
  sort(a + 1, a + 1 + n, cmp1);
  int ans= 0 ;
  for (int i = 1; i <= n; i++) {
    if (q.empty()) {
      q.push((T){a[i].ans = ++ans, a[i].second});
    }
    else {
      T u = q.top(); q.pop();
      /*
      xxx(i);
      xxx(u.id);xxx(u.time);xxx(a[i].first);
      */
      if (u.time < a[i].first) {
        u.time = a[i].second;
        q.push(u);
        a[i].ans = u.id;
      }
      else {
        q.push(u);
        q.push((T){a[i].ans = ++ans, a[i].second});
      }
    }
  }
  cout << ans << endl;
  sort(a + 1, a + 1 + n,cmp2);
  for (int i = 1; i <= n; i++) cout << a[i].ans << endl;
}
