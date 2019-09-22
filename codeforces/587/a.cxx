/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sun, 22 Sep 2019 09:20:12 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
int n, cnt[2], ans;
char s[N];
int main() {
  cin >> n >> (s + 1);
  for (int i = 1; i <= n; i++) {
    cnt[s[i] - 'a']++;
    if (i%2 == 0) {
      if (cnt[0] != cnt[1]) {
        ans++;
        if (cnt[0] > cnt[1]) {
          if  (s[i] == 'a') s[i] = 'b';
          else s[i-1] = 'b';
          cnt[0]--, cnt[1]++;
        }
        else {
          if (s[i] == 'b') s[i] = 'a';
          else s[i-1] = 'a';
          cnt[1]--, cnt[0]++;
        }
      }
    }
  }
  cout << ans << endl << s+1 << endl;
}

