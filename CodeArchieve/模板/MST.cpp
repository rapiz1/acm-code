#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct MST{//并查集
	static const int SZ=10000;
	int p[SZ];
	MST(){memset(this,0,sizeof(*this));};
	inline int find(int x){return p[x]==x?x:p[x]=find(p[x]);}//0 -> 不在森林中
	inline bool insert(int x) {
		if((p[x]!=0)||(x==0)) return false;//已存在，插入失败;禁止插入0 
		else return p[x]=x;
	}
	inline bool Union(int x,int y){
		int a=find(x),b=find(y);
		if(x*y==0) return false;//有一个不在森林中 
		else return p[a]=b;
	}
	inline void show(){//显示所有集合 
		int head[SZ],nxt[SZ];
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		for(int i=1;i<=SZ;i++) {//路径压缩 
			int x=find(i);
			if(x!=0) nxt[i]=head[x],head[x]=i;
		}
		for(int i=1;i<=SZ;i++) if(head[i]){
			for(int x=head[i];x;x=nxt[x]) printf("%d ",x);
			printf("\n");
		}
	}
}mst;
int main(){
	mst.insert(1);
	mst.insert(2);
	mst.Union(1,2);
	mst.insert(5);
	mst.show();
	mst.insert(6);
	mst.Union(5,1);
	mst.show();
	mst.Union(2,6);
	mst.show();
}
