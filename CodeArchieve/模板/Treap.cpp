#include<cstdio>
#include<ctime>
#include<cstdlib>
struct TP{//treap
	struct NODE{
		int a,s,w;NODE* ch[2];
		NODE(NODE* t=NULL){
			a=0,s=1,w=rand();
			ch[0]=ch[1]=t;
		}
		int cmp(int x){
			if(x==a) return -1;
			else return x<a?0:1;
		}
	};//0×ó1ÓÒ
	NODE* root,*null;
	inline void fix(NODE* o){
		o->s=o->ch[0]->s+o->ch[1]->s+1;
	}
	inline void rot(NODE*& o,int d){
		NODE* t=o->ch[d^1];
		o->ch[d^1]=t->ch[d];
		t->ch[d]=o;
		fix(o);
		fix(t);
		o=t;
	}
	void in(NODE*& o,int x){
		if(o==null) o=new NODE(null),o->a=x;
		else{
			int d=o->cmp(x);
			in(o->ch[d],x);
			if(o->w<o->ch[d]->w) rot(o,d^1);
		}
		fix(o);
	}
	void re(NODE*& o,int x){
		if(o==null) return;
		int d=o->cmp(x);
		if(d==-1){
			if(o->ch[0]==null) o=o->ch[1];
			else if(o->ch[1]==null) o=o->ch[0];
			else{
				int d2=o->ch[0]->w>o->ch[1]->w?1:0;
				rot(o,d2),re(o->ch[d2],x);
			}
		}
		else re(o->ch[d],x);
		if(o!=null) fix(o);
	}
	int kth(NODE*& o,int th){
		if(th>o->ch[0]->s+1) return kth(o->ch[1],th-(o->ch[0]->s+1));
		else if(th<o->ch[0]->s+1) return kth(o->ch[0],th);
		else return o->a;
	}
	int getnxt(int& th){
		if(root==null) return -1;
		else {
			while(th>root->s) th-=root->s;
			int res=kth(root,th);
			re(root,res);
			return res;
		}
	}
	void lmr(NODE* o,int dep=0){
		if(o==null) return;
		for(int i=1;i<=dep;i++) printf(" ");
		printf("a:%d w:%d sz:%d \n",o->a,o->w,o->s);
		lmr(o->ch[0],dep+1);
		lmr(o->ch[1],dep+1);
	}
	TP(){
		srand(time(NULL));
		null=new NODE();
		null->s=0;
		root=null;
	}
}tp;
int n,m,ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) tp.in(tp.root,i);
	//tp.lmr(tp.root);
	for(int i=m;(ans=tp.getnxt(i))!=-1;i+=m-1) printf("%d ",ans);
	
}
