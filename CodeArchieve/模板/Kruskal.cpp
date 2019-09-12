//COSG 7.mcst 通信线路
//Kruskal裸题 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
const int MAXV=1501+1,MAXE=MAXV*MAXV*2+5;
struct EDGE{
	int u,v,w;
	bool operator<(const EDGE& rhs)const {return this->w<rhs.w;};
}st[MAXE];
struct MST{
	static const int SZ=MAXE;
	int p[SZ];
	MST(){memset(this,0,sizeof(*this));};
	inline bool insert(int x){
		if(p[x]!=0) return false;
		p[x]=x;
		return true;
	}
	inline int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
}s;
using namespace std;
int n,cost[MAXV][MAXV],sz;//[1...n*n]
inline void add(int u,int v,int w){
	st[++sz].u=u;
	st[sz].v=v;
	st[sz].w=w;
}
inline void add_edge(int u,int v,int w){
	add(u,v,w);
	add(v,u,w);
}
int Kruskal(){
	int ans=0;
	sort(st+1,st+1+sz);
	for(int i=1;i<=sz;i++) s.p[i]=i;
	for(int i=1;i<=sz;i++) {
		int x=s.find(st[i].u),y=s.find(st[i].v);
		if(x!=y) ans+=st[i].w;s.p[x]=y;
	}
	return ans;
}
int main(){
	freopen("mcst.in","r",stdin);
	freopen("mcst.out","w",stdout);
	cin>>n;
	int w;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		cin>>w;
		if(w==-1) continue;
		else add_edge(i,j,w);
	}
	cout<<Kruskal();
	
}
