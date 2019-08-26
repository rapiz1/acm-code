/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Mon, 26 Aug 2019 09:22:17 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
map<int, int > st, now;
const int N = 2010;
int n, a[N];
int main() {
  fastios;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    st[a[i]]++;
  }
  int done = 0;// max to st.size()
  for (auto x: st) {
    if (x.second == 1) done++;
  }
  int tmp = done;
  int ans = 1e9;
  if (done == (int)st.size()) ans = 0;
  for (int i = 1; i <= n; i++) {
    now.clear();
    done = tmp;
    for (int j = i; j <= n; j++) {
      now[a[j]]++;
      if (!(now[a[j]]-1 >= st[a[j]]-1) && now[a[j]] >= st[a[j]] -1) {
        done++;
      }
      if (done == (int)st.size()) {
        //xxx(i);
        //xxx(j);
        ans = min(ans, j - i + 1);
        //xxx(ans);
      }
    }
  }
  cout << ans << endl;
}

