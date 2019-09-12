#include<iostream>
const int MAXV=1000,MAXE=MAXV;//ÎÞ¸ùÊ÷ 
int head[MAXV],next[MAXE],sz,p[MAXV];
struct EDGE{
	int u,v,w;
}st[MAXE];
void add(int u,int v,int w){
	st[sz++].u=u;
	st[sz].v=v;
	st[sz].w=w;
	next[sz]=head[u];
	head[u]=sz;
}
void add_edge(int u,int v,int w){
	add(u,v,w);
	add(v,u,w);
}
void dfs(int u,int fa){
	for(int e=head[u];e;e=next[e]) if(st[e].v!=fa) p[st[e].v]=u,dfs(st[e].v,fa);
}
int main(){
}
