//from ¼äµýÍøÂç 
#include<cstdio>
#include<cstring> 
#include<stack>
#include<algorithm>
using std::stack;
using std::min;
const int MAXV=3010,MAXE=8010,INF=0x3f3f3f3f;
struct EDGE{int u,v;}st[MAXE];
stack<int> stk;
int n,p,r,ans,unc=INF;
bool ins[MAXV];
int hed[MAXV],nxt[MAXE],sz,pbv[MAXV],pbvcnt,dfsclk,dfn[MAXV],cost[MAXV],ru[MAXV],mnw[MAXV],mnid[MAXV];
void add(int u,int v){
	st[++sz].u=u,st[sz].v=v;
	nxt[sz]=hed[u],hed[u]=sz;
}
int dfs(int u){
	stk.push(u);
	ins[u]=1;
	int lowu=dfn[u]=++dfsclk;
	for(int e=hed[u];e;e=nxt[e]) {
		if(dfn[st[e].v]) {
			if(ins[st[e].v]) lowu=min(lowu,dfn[st[e].v]);
		}
		else lowu=min(lowu,dfs(st[e].v));
	}
	if(lowu==dfn[u]){
		int nc=++pbvcnt;
		mnw[nc]=cost[u],mnid[nc]=u,pbv[u]=nc;
		while(stk.top()!=u) {
			int v=stk.top();stk.pop();
			mnw[nc]=min(mnw[nc],cost[v]),mnid[nc]=min(mnid[nc],v),pbv[v]=nc,ins[v]=0;
		}
		ins[u]=0,stk.pop();
	}
	return lowu;
}
void solve(){
	for(int i=1;i<=sz;i++) if(pbv[st[i].v]!=pbv[st[i].u])ru[pbv[st[i].v]]++;
	for(int u=1;u<=pbvcnt;u++) if(!ru[u])
		if(mnw[u]==INF) {
			unc=min(unc,mnid[u]);
		}
		else ans+=mnw[u];
}
int main(){
	memset(cost,0x3f,sizeof(cost));
	memset(mnw,0x3f,sizeof(mnw));
	memset(mnid,0x3f,sizeof(mnid));
	scanf("%d%d",&n,&p);
	int x,y;
	for(int i=1;i<=p;i++) scanf("%d %d",&x,&y),cost[x]=y;
	scanf("%d",&r);
	for(int i=1;i<=r;i++) scanf("%d %d",&x,&y),add(x,y);
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
	solve();
	if(unc!=INF) printf("NO\n%d",unc);
	else printf("YES\n%d",ans);
}
