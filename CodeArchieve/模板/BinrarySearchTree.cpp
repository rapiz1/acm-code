#include<cstdio>
#define lch (o<<1)
#define rch ((o<<1)+1)
using namespace std;
const int MAXN=1e4+1;
struct BT{//约定不插入0 
	struct NODE{
		int v,cnt;
		NODE*ch[2];
		NODE(int _v=0){v=_v,ch[0]=ch[1]=0,cnt=0;}
	};
	NODE* rt;
	void rot(NODE* &o,int d){
		NODE* k=o->ch[d^1];o->ch[d^1]=k->ch[d];k->ch[d]=o;o=k;
	}
	void in(NODE* &o,int x){
		if(o==NULL) {
			o=new NODE(x);
		}
		else{
			if(x<o->v) in(o->ch[0],x);
			else if(x>o->v) in(o->ch[1],x);
			else o->cnt++;
		}
	}
	void re(NODE* &o,int x){
		if(o==0) return;//没找到 
		else if(o->v>x) re(o->ch[1],x);
		else if(o->v<x) re(o->ch[0],x);
		else{
			if(!o->ch[0]) o=o->ch[1];
			else if(!o->ch[1]) o=o->ch[0];
			else{
				rot(o,0);//无所谓
				re(o->ch[0],x);
			}
		}
	}
	void lmr(NODE* o){
		if(o){
			lmr(o->ch[0]);
			printf("%d ",o->v);
			lmr(o->ch[1]);
		}
	}
}bt;
int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&m),bt.in(bt.rt,m);
	bt.lmr(bt.rt);
}
