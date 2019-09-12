#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAXV=100+10,MAXE=MAXV*MAXV;
struct EDGE{int u,v,w;}st[MAXE];
int n,m,s,d[MAXV],head[MAXV],nxt[MAXE],sz;
inline void add(int u,int v,int w){
	st[++sz].u=u;
	st[sz].v=v;
	st[sz].w=w;
	nxt[sz]=head[u];
	head[u]=sz;
}
void biadd(int u,int v,int w){//ÎÞÏò±ß 
	add(u,v,w);
	add(v,u,w);
}
void BellmanFord(){
	memset(&d,0x3f,sizeof(d));
	d[s]=0;
	for(int i=1;i<=n-1;i++) 
	{
		bool f=1;
		for(int e=1;e<=sz;e++) if(d[st[e].u]+st[e].w<d[st[e].v]) d[st[e].v]=d[st[e].u]+st[e].w,f=0;
		if(f) break;
	}
}
int main(){
	cin>>n>>m>>s;
	int u,v,w;
	for(int i=1;i<=m;i++) cin>>u>>v>>w,add(u,v,w),add(v,u,w);
	BellmanFord();
	int t;
	while((cin>>t)&&t!=-1) cout<<d[t]<<endl;
}
