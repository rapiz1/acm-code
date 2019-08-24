#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
//#define DBG
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int now[256], nxt[N][256];
ll ans=-1, jump = 0;
string s, t;
int main() {
  cin >> s >> t;
  memset(now, -1, sizeof(now));
  memset(nxt, -1, sizeof(nxt));
  for (int i = (int)s.size() - 1; i >= 0; i--) {
    for (int j = 'a'; j <= 'z'; j++) {
      nxt[i][j] = now[j];
    }
    now[s[i]] = i;
  }
  /*
  for (int i = 1; i < s.size(); i++) {
    for (int j = 'a'; j <= 'z'; j++) if (nxt[i][j] == -1) {
      nxt[i][j] = nxt[0][j];
    }
  }
  */
  #ifdef DBG
  for (int i = 1; i < s.size(); i++) {
    for (int j = 'a'; j <= 'z'; j++) if (nxt[i][j] != -1) {
      printf("nxt[%d][%c]:%d\n", i, j, nxt[i][j]);
    }
  }
  #endif
  if (t[0] == s[0]) {
    ans = 0;
  }
  else {
    ans = nxt[0][t[0]];
  }
  if (ans == -1) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i < t.size(); i++) {
    if (nxt[ans][t[i]] != -1) {
      ans = nxt[ans][t[i]];
    }
    else {
      if (t[i] == s[0]) {
        ans = 0;
      }
      else {
        ans = nxt[0][t[i]];
      }
      jump++;
    }
    if (ans == -1) {
      break;
    }
  }
  if (ans == -1) cout << -1;
  else cout << ans + jump*s.size() + 1;
}
