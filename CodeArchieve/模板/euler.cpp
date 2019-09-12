#include<iostream>
using namespace std;
const int MAXV=1010;
bool e[MAXV][MAXV];
int n,m,ans[MAXV],sz,vis[MAXV][MAXV];
void euler(int u){
	for(int i=1;i<=n;i++) if(e[u][i]&&!vis[u][i]){
		vis[u][i]=vis[i][u]=1;
		euler(i);
		ans[++sz]=i;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u][v]=e[v][u]=1;
	}
	euler(1);
	cout<<"1 ";
	for(int i=sz;i;i--) cout<<ans[i]<<" ";
} 
