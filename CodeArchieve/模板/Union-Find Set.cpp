#include<cstdio>
const int MAXN=2e4+1;
int n,m,q;
struct UFS{
	int p[MAXN],rk[MAXN];
	void init(){for(int i=1;i<=n;i++) p[i]=i;}
	int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
	void unionxy(int x,int y){
		if((x=find(x))==(y=find(y))) return;
		if(rk[x]>rk[y]) p[y]=x;
		else{
			p[x]=y;
			if(rk[x]==rk[y]) rk[y]++;
		}
	}
}ufs;
int main(){
	scanf("%d%d",&n,&m);
	ufs.init();
	int a,b;
	for(int i=1;i<=m;i++) scanf("%d%d",&a,&b),ufs.unionxy(a,b);
	scanf("%d",&q);
	for(int i=1;i<=q;i++) scanf("%d%d",&a,&b),printf("%s\n",ufs.find(a)==ufs.find(b)?"Yes":"No");
}
