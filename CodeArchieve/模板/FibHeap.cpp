//Fib Heap
#include<cstdio>
#include<vector>
#include<cstring>
using std::vector<int>;
struct FIBHP{
	static const int MAXN=1e8;
	struct NODE{
		int a,p,r,l;//data,parent,right,left 
		bool m;//mark
		vector<int> ch;//children
		NODE(){
			memset(this,0,sizeof(*this));
			ch.clear();
		}
	};
	vector<int> rl;//root list
	int st[MAXN],minx,sz;
	FIBHP(){
		memset(this,0,sizeof(*this));
		rl.clear();
	}
	void insert(int x){
		rl.push_back(++sz);
		if(st[sz]=x<st[minx]) minx=sz;
	}
	void Union
};
