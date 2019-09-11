/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Tue, 10 Sep 2019 21:49:21 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
const int ST = 4000*100 + 10, N = 3e5 + 10;
const ll MOD = 20071027;
char senten[N], buf[110];
int sz, st[ST], ch[ST][26], s, n;
ll f[N];
void insert(char* s){
  int pos;
  for (pos = 1;*s; s++) {
    int idx = *s - 'a';
    if (!ch[pos][idx]) {
      ch[pos][idx] = ++sz;
    }
    pos = ch[pos][idx];
  }
  st[pos]++;
}
ll solve() {
  for (int i = 0; i <= n; i++) f[i] = 0;
  for (int i = 0; i <= sz; i++) {
    memset(ch[i], 0, sizeof ch[i]);
    st[i] = 0;
  }
  sz = 1;
  n = strlen(senten);
  cin >> s;
  for (int i = 1; i <= s; i++) {
    cin >> buf;
    insert(buf);
  }
  f[n] = 1;
  for (int i = n-1; i>=0; i--) {
    int pos = 1;
    //xxx(i);
    for (int j = i; j < n; j++) {
      int idx = senten[j] - 'a';
      if (ch[pos][idx]) {
        pos = ch[pos][idx];
      }
      else break;
      if (st[pos]) {
        f[i] += (ll)st[pos]*f[j+1];
        f[i] %= MOD;
        //xxx(j);
      }
    }
    //xxx(f[i]);
  }
  return f[0];
}
int main() {
  int ks = 1;
  while (cin >> senten) {
    //if (ks != 1) cout << endl;
    cout << "Case " << ks << ": " << solve() << endl;
    ks++;
  }
}

