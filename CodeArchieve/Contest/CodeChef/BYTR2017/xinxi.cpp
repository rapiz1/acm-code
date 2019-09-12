#include<cstdio>
#include<algorithm>
#define file(x) "2015message."#x
using std::min;
const int V=200010,L=1<<15;
int n,nxt[V],cnt,clk,dfn[V],vis[V],ans=1<<30;
int main(){
	freopen(file(in),"r",stdin);
	n=gi();
	for(int i=1;i<=n;i++) nxt[i]=gi();
	for(int i=1;i<=n;i++) if(!vis[i]){
		++cnt;
		int s;
		for(s=i;!vis[nxt[s]];s=nxt[s]) dfn[s]=++clk,vis[s]=cnt;
		dfn[s]=++clk,vis[s]=cnt;
		if(vis[nxt[s]]==vis[s]) ans=min(ans,dfn[s]-dfn[nxt[s]]+1);
	}
	printf("%d",ans);
}
