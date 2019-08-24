/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Fri, 23 Aug 2019 13:23:11 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define lch (o<<1)
#define rch ((o<<1)|1)
typedef long long ll;
using namespace std;
namespace IStream{
    const int L=1<<15;
    char buffer[L],*S,*T;
    inline char Get_Char()
    {
        if(S==T)
        {
            T=(S=buffer)+fread(buffer,1,L,stdin);
            if(S==T) return EOF;
        }
        return *S++;
    }
    inline int gi()
    {
        char c;
        int re=0;
        for(c=Get_Char();c<'0'||c>'9';c=Get_Char());
        while(c>='0'&&c<='9')
            re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
        return re;
    }
}
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
const int N = 1e5 + 10, SEG=N<<2;
const int ADD = 10000000;
int n, m;
ll lastAns, a[N];
void solve() {
  lastAns = 0;
  n = gi();
  m = gi();
  for (int i = 1; i <= n; i++) {
    a[i] = gi();
    st.insert(a[i]);
  }
  while (m--) {
    int op = gi();
    if (op == 1) {
      int t1 = gi()^lastAns;
    }
    else {
      int t2 = gi()^lastAns, t3 = gi()^lastAns;

    }
  }
}
int main() {
  int ks = gi();
  while (ks--) {
    solve();
  }
}

