#include<cstdio>
#include<iostream>
#include<time.h>
#include<algorithm>
#define maxn 100050
using namespace std;
int n;
class treap {
private:
	struct node {
		int r, l, fa;
		int v, fix;
		node () { r = 0; l = 0; v = 0; fa = 0; }
	} ns[maxn];
	int tot;
	int delqueue[maxn], top;
public:
	treap () { tot = 1; top = 0; }
	int get_root () {
		return ns[0].r;
	}
	int new_node () {
		if (top) return delqueue[--top + 1];
		return ++tot;
	}
	void del_node (int tar) {
		top++;
		delqueue[top] = tar;
	}
	void zig (int tar) {
		int tmp = ns[tar].fa;
		if (ns[ ns[tmp].fa ].r == tmp) ns[ ns[tmp].fa ].r = tar;
		else ns[ ns[tmp].fa ].l = tar;
		ns[tar].fa = ns[tmp].fa;
		ns[tmp].l = ns[tar].r;
		if (ns[tar].r) ns[ ns[tar].r ].fa = tmp;
		ns[tar].r = tmp, ns[tmp].fa = tar;
	}
	void zag (int tar) {
		int tmp = ns[tar].fa;
		if (ns[ ns[tmp].fa ].r == tmp) ns[ ns[tmp].fa ].r = tar;
		else ns[ ns[tmp].fa ].l = tar;
		ns[tar].fa = ns[tmp].fa;
		ns[tmp].r = ns[tar].l;
		if (ns[tar].l) ns[ ns[tar].l ].fa = tmp;
		ns[tar].l = tmp, ns[tmp].fa = tar; 
	} 
	void rebalanced (int tar) {
		int ne = ns[tar].fa;
		while (ns[tar].fix < ns[ne].fix && ne) {
			if(ns[ne].l == tar) zig (tar);
			else zag (tar);
			ne = ns[tar].fa;
		}
	}
	void set_root (int tar) {
		ns[0].r = 1;
		ns[1].v = tar;
		ns[1].fix = rand ();
	}
	void insert (int tar) {
		if (!get_root () ) { set_root (tar); return ;}
		int now = get_root ();
		int tmp;
		while (1) {
			if (tar < ns[now].v) {
				if(!ns[now].l) {
					tmp = new_node ();
					ns[now].l = tmp;
					ns[tmp].fa = now;
					ns[tmp].v = tar;
					ns[tmp].fix = rand ();
					rebalanced (tmp);
					return;
				}
				else now = ns[now].l;
			}else {
				if (!ns[now].r) {
					tmp = new_node ();
					ns[now].r = tmp;
					ns[tmp].fa = now;
					ns[tmp].v = tar;
					ns[tmp].fix = rand ();
					rebalanced (tmp);
					return;
				}
				else now = ns[now].r;
			}
		}
	}
	void output (int now) {
		if (ns[now].l) output (ns[now].l);
		printf ("%d ", ns[now].v);
		if (ns[now].r) output (ns[now].r);
		return;
	}
} tp; 
int main() {
	srand ( (unsigned)time (NULL) );
	scanf ("%d", &n);
	int tmp;
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &tmp);
		tp.insert (tmp);
	}
	tp.output ( tp.get_root () );
	return 0;
}
