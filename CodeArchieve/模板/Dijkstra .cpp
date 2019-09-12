#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAXV=100+10,MAXE=MAXV*MAXV;
struct EDGE{int u,v,w;}st[MAXE];
int n,m,s,d[MAXV],head[MAXV],nxt[MAXE],sz;
struct CMP{
	bool operator()(int a,int b){
		return d[a]<d[b];
	}
};
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
void Dijsktra(){
	memset(d,0x3f,sizeof(d));
	priority_queue<int,vector<int>,CMP> q;
	d[s]=0;
	q.push(s);
	while(!q.empty()){
		int cur=q.top();
		q.pop();
		for(int e=head[cur];e;e=nxt[e]) if(d[cur]+st[e].w<d[st[e].v] d[st[e].v]=d[cur]+st[e].w,q.push(st[e].v);
}
int main(){
	cin>>n>>m>>s;
	int u,v,w;
	for(int i=1;i<=m;i++) cin>>u>>v>>w,add(u,v,w),add(v,u,w);
	Dijsktra();
	int t;
	while((cin>>t)&&t!=-1) cout<<d[t]<<endl;
}
