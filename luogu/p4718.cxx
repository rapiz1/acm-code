/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sat, 14 Sep 2019 09:10:57 +0800
 */
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastios ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
using namespace std;
namespace IO{
	char buf[1<<15],*fs,*ft;
	inline char gc(){return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;}
	inline ll gi(){
		ll x=0;int rev=0,ch=gc();
		while(ch<'0'||ch>'9'){if(ch=='-')rev=1;ch=gc();}
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=gc();}
		return rev?-x:x;
	}
}
using IO::gi;
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;}
inline ll qmul(ll a, ll b, ll mod) {
  register ll d = (ll)floor(a*(long double)b/mod + 0.5);
  register ll ret = a*b - d*mod;
  ret = ret < 0 ? ret + mod : ret;
  return ret;
}
inline ll randint(ll l, ll r) {
  return rand()%(r - l + 1) + l;
}
inline ll qpow(ll x, ll r, ll mod) {
  ll ret = 1;
  for(ll tmp = x; r; r>>=1) {
    if (r&1) ret = qmul(ret, tmp, mod);
    tmp = qmul(tmp, tmp, mod);
  }
  return ret;
}
inline bool witness(ll a, ll n) {
  int t;
  ll m;
  for (t = 0, m = n - 1; m && !(m&1);t++, m>>=1) ;
  ll x = qpow(a, m, n);
  for (int i = 1; i <= t; i++) {
    ll nx = qmul(x, x, n);
    if (nx == 1 && x != 1 && x != n - 1) return true;
    x = nx;
  }
  return x != 1;
}
const int S = 10;
bool primetest(ll n) {
  if (n == 1) return false;
  for (int i = 1; i <= S; i++) {
    ll a = randint(1, n - 1);
    if (witness(a, n)) return false;
  }
  return true;
}
ll rho(ll n) {
  if (n == 1) return 1;
  //xxx(n);
  int i, k;
  register ll x, y, c;
  for (i = 2, x = randint(0, n - 1), y = x, k = 2, c = rand(); 1; i++) {
    x = (qmul(x, x, n) + c)%n;
    //x = (x*x%n - 1 + n)%n;
    ll d = gcd(abs(y - x), n);
    if (d > 1) {
      return d;
    }
    if (i == k) k<<=1, y = x;
    //xxx(i);xxx(x);xxx(y);
  }
}
ll ans;
void resolve(ll n) {
  if (n <= ans) return;
  if (n == 1) return;
  else if (primetest(n)) {
    ans = ans > n ? ans : n;
  }
  else {
    register ll p = n;
    while (p == n) {
      p = rho(p);
    }
    resolve(p);
    resolve(n/p);
  }
}
const int ST = 1e6 + 10;
ll q[ST];
int s, t;
void resolve_q(ll n) {
  ll x, y;
  ans = 1;
  s=0;
  t=1;
  q[t++] = n;
  while (s!=t) {
    x = y = q[s++];
    //s%=ST;
    if (x <= ans) continue;
    else if (primetest(x)) {
      ans = ans > x ? ans : x;
    }
    else {
      while (x == y) x = rho(x);
      q[t++] = x;
      //t%=ST;
      q[t++] = y/x;
      //t%=ST;
    }
  }
}
void solve() {
  ll n;
  n = gi();
  ans = 0;
  resolve_q(n);
  if (ans == n) puts("Prime");
  else printf("%lld\n", ans);
}
int main() {
  srand(time(NULL));
  int ks = gi();
  while (ks--) {
    solve();
  }
}

