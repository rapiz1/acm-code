/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 31 Aug 2019 21:10:06 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;
namespace IO{
	char buf[1<<15],*fs,*ft;
	inline char gc(){return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;}
	inline int gi(){
		int x=0,rev=0,ch=gc();
		while(ch<'0'||ch>'9'){if(ch=='-')rev=1;ch=gc();}
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=gc();}
		return rev?-x:x;
	}
}
using IO::gi;
int n, ch[N][2], root, sz[N], mnch[N], id[N];
bool isch[N];
void dfs(int u) {
  sz[u] = 1;
  mnch[u] = n + 1;
  for (int i = 0; i < 2; i++) {
    int v = ch[u][i];
    if (!v) continue;
    dfs(v);
    sz[u] += sz[v];
    mnch[u] = min(mnch[u], min(mnch[v], v));
  }
}
void calc(int u, int l, int r) {
  if (l == r) {
    id[u] = l;
    return;
  }
  if (ch[u][0] && ch[u][1]) {
    int bound = 0;
    for (int i = 0; i < 2; i++) {
      int v = ch[u][i];
      if (mnch[u] == min(mnch[v], v)) {
        calc(v, l, l + sz[v] - 1);
        bound = l + sz[v];
      }
      else {
        id[u] = bound;
        calc(v, bound + 1, r);
      }
    }
  }
  else {
    int v = ch[u][0] ? ch[u][0] : ch[u][1];
    if (mnch[u] < u) {
      calc(v, l, l + sz[v] - 1);
      id[u] = l + sz[v];
    }
    else {
      calc(v, l + 1, r);
      id[u] = l + 1;
    }
  }
}
void solve() {
  n = gi();
  for (int i = 0; i <= n; i++) {
    isch[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    ch[i][0] = gi();
    ch[i][1] = gi();
    isch[ch[i][0]] = isch[ch[i][1]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (!isch[i]) {
      root = i;
      break;
    }
  }
  //xxx(root);
  dfs(root);
  calc(root, 1, n);
  /*
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", i, (int)id[i]);
  }
  */
  ll ans = 0, k = 233;
  for (int i = 1; i <= n; i++, k = k*233%MOD) {
    //xxx(k);
    ans += (id[i]^i)*k%MOD;
  }
  ans %= MOD;
  printf("%d\n", (int)ans);
}
int main() {
  int t = gi();
  while (t--) {
    solve();
  }
}

