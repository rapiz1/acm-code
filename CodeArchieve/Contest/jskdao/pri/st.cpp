#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define up(i,j,n)	for(int i=j;i<=n;++i)
#define down(i,j,n)	for(int i=j;i>=n;--i)
#define cmax(a,b)	a=max(a,b)
#define cmin(a,b)	a=min(a,b)

ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}

const ll MAXN=1e5+5;
const ll oo=0x3f3f3f3f;
const ll LIM=1e5;

ll f[66][2][MAXN],T,L,R,P,dig[105],a[MAXN],h[MAXN],g[MAXN];
ll miu[MAXN],prime[MAXN],cnt=0;
bool vis[MAXN];

ll read(){
	char ch=getchar();ll x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}

namespace solution{
	ll col(ll num,ll p){
		if(num==0)return 0;
		ll len=0;
		while(num){
			dig[len++]=num%p;
			num/=p;
		}
		up(i,0,len)up(j,0,p)up(k,0,1)f[i][k][j]=0;
		f[len][1][1]=1;
		dig[len]=1;
		down(i,len-1,0){
			ll x=f[i+1][1][dig[i+1]];
			if(dig[i]!=0&&dig[i+1]!=0&&gcd(dig[i],dig[i+1])==1)f[i][1][dig[i]]=x;
			if(dig[i+1]!=0&&x)up(j,1,dig[i]-1)if(gcd(dig[i+1],j)==1)
				f[i][0][j]+=x;
			copy(f[i+1][0],f[i+1][0]+p,a);
			up(j,1,p-1){
				h[j]=0;
				for(int k=j;k<=p-1;k+=j)h[j]+=a[k];
				h[j]*=miu[j];
			}
			down(j,p-1,1){
				g[j]=0;
				if(h[j])for(int k=j;k<p;k+=j)g[k]+=h[j];
			}
			up(j,1,p-1)f[i][0][j]+=g[j];
			f[i][0][1]++;
		}
		ll sum=0;
		up(i,1,p-1)sum+=f[0][0][i]+f[0][1][i];
		sum--;
		return sum;
	}
	void Solve(){
		miu[1]=1;
		up(i,2,LIM){
			if(!vis[i]){
				prime[++cnt]=i;
				miu[i]=-1;
			}
			up(j,1,cnt){
				if(i*prime[j]>LIM)break;
				vis[i*prime[j]]=1;
				if(i%prime[j])miu[i*prime[j]]=miu[i]*miu[prime[j]];
				else{
					miu[i*prime[j]]=0;
					break;
				}
			}
		}
		T=read();
		while(T--){
			L=read();R=read();P=read();
			printf("%lld\n",col(R,P)-col(L-1,P));
		}
	}
}

int main(){
	using namespace solution;
	freopen("input", "r", stdin);
	Solve();
	return 0;
}
