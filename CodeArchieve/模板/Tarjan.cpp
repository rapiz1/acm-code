#include<iostream>
#include<stack>
using namespace std;
const int MAXV=1000+10,MAXE=MAXV*MAXV;
struct EDGE{
	int u,v;
}st[MAXE];
int n,m,sz,head[MAXV],nxt[MAXE],dfn[MAXV],dfs_clock=0,sccid,pbcid,scc[MAXV],pbc[MAXV];//1...sz
stack<int> sscc;//强连通分量 Strongly Connected  Components
stack<int> spbc;//点双联通分量 Point Biconnected Components 
bool iscut[MAXV],isbridge[MAXV];
void add(int u,int v){
	st[++sz].u=u;
	st[sz].v=v;
	nxt[sz]=head[u];
	head[u]=sz;
}
int dfs(int u=1,int fa=-1){//返回low(u) 
	spbc.push(u);
	sscc.push(u);
	int lowu=dfn[u]=dfs_clock++,child=0;
	for(int e=head[u];e;e=nxt[e]) if(!dfn[st[e].v]){
		child++;
		int lowv=dfs(st[e].v,u);
		lowu=min(lowu,lowv);
		if(lowv>=dfn[u]) iscut[u]=1;//割顶 
		if(lowv>dfn[u]) isbridge[e]=1;//桥 
	}
	else if(dfn[st[e].v]<dfn[u]&&st[e].v!=fa) lowu=min(lowu,dfn[st[e].v]);
	if(fa<0&&child==1) iscut[u]=0;//割顶特判
	if(iscut[u]) {
		pbcid++;
		while(spbc.top()!=u) pbc[spbc.top()]=pbcid,spbc.pop();//点双联通分量 
	}
	if(lowu==dfn[u]) {//强连通分量
		sccid++;
		while(sscc.top()!=u) scc[sscc.top()]=sccid,sscc.pop();
	}
	return lowu;
}
int main(){
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++) cin>>u>>v,add(u,v);
	dfs();
}
