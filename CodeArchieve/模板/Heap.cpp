#include<cstdio>
#include<algorithm>
#define fa (o>>1)
#define lch (o<<1)
#define rch ((o<<1)+1)
using std::swap;
using std::sort;
const int MAXN=1e3+1;
struct HP{//Ð¡¸ù¶Ñ 
	int st[MAXN*4],sz;
	void up(int o){
		while(o!=1&&st[o]<st[fa]) swap(st[o],st[fa]),o=fa;
	}
	void down(int o){
		while(lch<=sz){
			int t=lch;
			if(st[rch]<st[lch]&&rch<=sz) t++;
			if(st[t]<st[o]) swap(st[t],st[o]),o=t;
			else break;
		}
	}
	void in(int x){st[++sz]=x,up(sz);}
	int re(int o){
		int t=st[o];
		swap(st[o],st[sz--]);
		down(o);
		return t;
	}
}hp;
struct M{int t,w;
bool operator<(const M& rhs)const{return t<rhs.t;}
}a[MAXN];
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].t);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].w);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) if(hp.sz<a[i].t) hp.in(a[i].w);
	else if(hp.st[1]<a[i].w) hp.re(1),hp.in(a[i].w);
	while(hp.sz) ans+=hp.re(1);
	printf("%d",ans);
} 
