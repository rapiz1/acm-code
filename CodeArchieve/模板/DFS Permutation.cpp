#include<cstdio>
const int MAXN=100+1;
int n,st[MAXN],sz;
bool pkd[MAXN];
void dfs(int cur){
	if(cur>n) {
		for(int i=1;i<=sz;i++) printf("%d ",st[i]);
		printf("\n");
	}
	else for(int i=1;i<=n;i++) if(!pkd[i]) pkd[i]=1,st[++sz]=i,dfs(cur+1),sz--,pkd[i]=0;
}
int main(){
	scanf("%d",&n);
	dfs(1);
}
