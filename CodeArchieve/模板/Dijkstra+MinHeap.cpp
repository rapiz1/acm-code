/** SSSP
* Dijkstra+小根堆 
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN=100,MAXM=MAXN*MAXN;
int head[MAXN],cnt,d[MAXN];
//链式前向星 
//边的下标从1开始
struct EDGE{
	int u,v,w,next;
	EDGE(){next=0;}//0 -> NULL
	EDGE(int _u,int _v,int _w,int _next):u(_u),v(_v),w(_w),next(_next){};
}edge[MAXM];
void _add(int u,int v,int w){
	edge[++cnt]=EDGE(u,v,w,head[u]);
	head[u]=cnt;
}
void add(int u,int v,int w) {
	_add(u,v,w);
	_add(v,u,w);
}
//比较函数
struct CMP{
	bool operator()(int a,int b) {
		return d[a]>d[b];
	}
}; 
priority_queue<int,vector<int>,CMP> q;
int main(){
	memset(d,0x3f,sizeof(d));
	int n,m,u,v,w,s;
	cin>>n>>m>>s;
	for(int i=0;i<m;i++) cin>>u>>v>>w,add(u,v,w),q.push(i);
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	while(!q.empty()){
		int idx=q.top();
		q.pop();
		for(int i=head[idx];i;i=edge[i].next) d[edge[i].v]=min(d[edge[i].v],d[edge[i].u]+edge[i].w);
	}
	int t;
	while(cin>>t&&t!=-1) cout<<d[t]<<endl;
}
/**Debug
* memset(d,0x3f,sizeof(d))
*/ 
