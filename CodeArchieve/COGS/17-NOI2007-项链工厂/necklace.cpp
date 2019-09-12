#include <cstdio>
#include <algorithm>
#include <cstring>
#define file "necklace."
#define mid ((l+r)>>1)
#define lch (o<<1)
#define rch (o<<1|1)
const int N = 5e5 + 10, V = N << 2;
int n, q, c, co[V], s, r = 1;
struct Node {int c[2], s;
	Node operator+(const Node& rhs)const {
		Node x = *this;
		x.c[1] = rhs.c[1];
		x.s += rhs.s - (this->c[1] == rhs.c[0]);
		return x;
	}
}st[V];
char cmd[10];
inline void mkco(int o, int x) {
	if (!o) return;
	co[o] = x;
	st[o].c[0] = st[o].c[1] = x;
	st[o].s = 1;
}
inline void up(int o) {st[o] = st[lch] + st[rch];}
inline void down(int o) {
	if (co[o] <= c) mkco(lch, co[o]), mkco(rch, co[o]), co[o] = c+ 1;
}
void build(int o, int l, int r) {
	co[o] = c + 1;
	if (l == r) {
		int x;
		scanf("%d", &x);
		st[o].c[0] = st[o].c[1] = x;
		st[o].s = 1;
		return;
	}
	build(lch, l, mid);
	build(rch, mid+1, r);
	up(o);
}
Node query(int o, int l, int r, int q1, int q2) {
	if (q1 <= l && r <= q2) {
		return st[o];
	}
	down(o);
	Node ret;
	bool ex=0;
	if (q1 <= mid) ret = query(lch, l, mid, q1, q2), ex=1;
	if (mid < q2) {
		if (ex) ret = ret + query(rch, mid+1, r, q1, q2);
		else ret = query(rch, mid + 1, r, q1, q2);
	}
	return ret;
}
void change(int o, int l, int r, int q1, int q2, int q3) {
	if (q1 <= l && r <= q2) mkco(o, q3);
	else {
		down(o);
		if (q1 <= mid) change(lch, l, mid, q1, q2, q3);
		if (mid < q2) change(rch, mid+1, r, q1, q2, q3);
		up(o);
	}
}
inline int fix(long long x) {return (s + x*(n+r))%n;}
int main() {
//	freopen(file"in", "r", stdin);
//	freopen(file"out", "w", stdout);
	scanf("%d%d", &n, &c);
	build(1, 0, n-1);
	scanf("%d", &q);
	for (int t = 1; t <= q; t++) {
		scanf("%s", cmd);
		if (cmd[0] == 'R') {
			int x; scanf("%d", &x);
			s = fix(n-x);
		}
		else if (cmd[0] == 'F') r *= -1;
		else if (cmd[0] == 'S') {
			int i, j;scanf("%d%d", &i, &j);
			i=fix(i-1), j=fix(j-1);	
			Node x = query(1, 0, n-1, i, i), y = query(1, 0, n-1, j, j);
			change(1, 0, n-1, i, i, y.c[0]), change(1, 0, n-1, j, j, x.c[1]);
		}
		else if (cmd[0] == 'P') {
			int i, j, k; scanf("%d%d%d", &i, &j, &k);
			i=fix(i-1), j=fix(j-1);	
			if (r == -1) std::swap(i, j);
			if (i <= j) change(1, 0, n-1, i, j, k);
			else change(1, 0, n-1, i, n-1, k), change(1, 0, n-1, 0, j, k);
		}
		else if (cmd[0] == 'C' && cmd[1] != 'S') printf("%d\n", std::max(st[1].s - (st[1].c[0] == st[1].c[1]), 1));
		else {
			int i, j;scanf("%d%d", &i, &j);
			i=fix(i-1), j=fix(j-1);	
			Node x;
			if (r == -1) std::swap(i, j);
			if (i <= j) x = query(1, 0, n-1, i, j);
			else {
				x = query(1, 0, n-1, i, n-1);
				x = x + query(1, 0, n-1, 0, j);
			}
			printf("%d\n", x.s);
		}
	}
}
