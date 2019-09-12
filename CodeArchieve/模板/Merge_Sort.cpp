#include<cstdio>
#include<algorithm>
#define file(x) "swiss."#x
//#define DBG
using std::sort;
using std::swap;
using std::merge;
const int MAXN=100010<<1;
struct P{int id,lv,sc;}p[MAXN],a[MAXN],b[MAXN];
bool cmp(const P& a,const P&b){
	if(a.sc!=b.sc) return a.sc>b.sc;
	else return a.id<b.id;
}
int n,r,q,sza,szb;
int main(){
	#ifndef DBG
	freopen(file(in),"r",stdin);
	freopen(file(out),"w",stdout);
	#endif
	scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=2*n;i++) scanf("%d",&p[i].sc),p[i].id=i;
	for(int i=1;i<=2*n;i++) scanf("%d",&p[i].lv);
	sort(p+1,p+1+2*n,cmp);
	for(int k=1;k<=r;k++){
		for(int i=1;i<=n;i++){
			a[i]=p[2*i],b[i]=p[2*i-1];
			if(p[2*i-1].lv>p[2*i].lv) swap(a[i],b[i]);
			a[i].sc++;
		}
		int p1=1,p2=1;
		#ifdef DBG
		printf("round %d:\n",k);
		#endif
		for(int i=1;i<=2*n;i++){
			if(p2>n||(p1<=n&&cmp(a[p1],b[p2]))) p[i]=a[p1++];
			else p[i]=b[p2++];
			#ifdef DBG
			printf("rk %d: id:%d sc:%d lv:%d\n",i,p[i].id,p[i].sc,p[i].lv);
			#endif
		}
		//merge(a+1,a+1+n,b+1,b+1+n,p+1,cmp);
	}
	printf("%d",p[q].id);
}
