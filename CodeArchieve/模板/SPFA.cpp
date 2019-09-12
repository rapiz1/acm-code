#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAXV=100+10,MAXE=MAXV*MAXV;
struct EDGE{int u,v,w;}st[MAXE];
int n,m,s,d[MAXV],head[MAXV],nxt[MAXE],sz,vcnt[MAXV];
bool inq[MAXV];
inline void add(int u,int v,int w){
	st[++sz].u=u;
	st[sz].v=v;
	st[sz].w=w;
	nxt[sz]=head[u];
	head[u]=sz;
}
void biadd(int u,int v,int w){//无向边 
	add(u,v,w);
	add(v,u,w);
}
bool SPFA(){
	memset(d,0x3f,sizeof(d));
	queue<int> q;
	d[s]=0;inq[s]=vcnt[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=0;
		for(int e=head[u];e;e=nxt[e]) if(d[u]+st[e].w<d[st[e].v]){
			int v=st[e].v;
			d[v]=d[u]+st[e].w;
			if(!inq[v]) {
				inq[v]=1;
				if(++vcnt[v]>n) return false;//负环 
				q.push(v);
			}
		}
	}
	return true;
}
int main(){
	cin>>n>>m>>s;
	int u,v,w;
	for(int i=1;i<=m;i++) cin>>u>>v>>w,add(u,v,w),add(v,u,w);
	SPFA();
	int t;
	while((cin>>t)&&t!=-1) cout<<d[t]<<endl;
}
