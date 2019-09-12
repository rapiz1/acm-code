#include <cstdio>
#include <algorithm>
const int N = 1e5 + 10, F = 1e4 + 10, L = 1e9;
struct ST{
	int x, r, f;
	inline void rd() {scanf("%d%d%d", &x, &r, &f);}
	bool operator<(const ST& b)const {return r > b.r;}
}st[N];
struct ND{
	ND* ch[2];
	int s;
	ND(int _s = 0):s(_s){ch[0]=ch[1]=0;}
	inline void up() {
		s = 0;
		if (ch[0]) s += ch[0]->s;
		if (ch[1]) s += ch[1]->s;
	}
}*seg[F];
int q1, q2;
void add(ND*& o, int l, int r) {
	if (!o) o = new ND();
	if (l == r) {
		o->s += q2;
		return;
	}
	int mid = l + r >> 1;
	if (q1 <= mid) add(o->ch[0], l, mid);
	else add(o->ch[1], mid + 1, r);
	o->up();
}
int query(ND* o, int l, int r) {
	if (!o) return 0;
	if (q1 <= l && r <= q2) return o->s;
	int mid = l + r >> 1, x = 0;
	if (q1 <= mid) x += query(o->ch[0], l, mid);
	if (q2 > mid) x += query(o->ch[1], mid + 1, r);
	return x;
}
int n, k;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) st[i].rd();
	std::sort(st + 1, st + 1 + n);
	long long s = 0;
	for (int i = 1; i <= n; i++) {
		q1 = std::max(1, st[i].x - st[i].r), q2 = std::min(L, st[i].x + st[i].r);
		for (int j = std::max(1, st[i].f - k); j <= std::min(st[i].f + k, int(1e4)); j++) 
				s += query(seg[j], 1, L);
		q1 = st[i].x, q2 = 1;
		add(seg[st[i].f], 1, L);
	}
	printf("%I64d", s);
}
