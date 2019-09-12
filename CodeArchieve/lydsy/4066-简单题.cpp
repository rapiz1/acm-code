#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
const double fac = 0.7;
int n, m, D, ans, sz;
struct ND{
	int d[2], l[2], r[2], sz, w, s;
	ND* ch[2];
	ND(int x, int y, int v) {d[0] = x, d[1] = y, w = v;up();}
	inline void up() {
		l[0] = r[0] = d[0];
		l[1] = r[1] = d[1];
		s = w;	
		sz = 1;
		for (int j = 0; j < 2; j++) if (ch[j]) {
			s += ch[j]->s;
			sz += ch[j]->sz;
			for (int i = 0; i < 2; i++)
				l[i] = std::min(l[i], ch[j]->l[i]),
				r[i] = std::max(r[i], ch[j]->r[i]);
		}
	}
}*rt;
bool cmp(ND* a, ND* b) {
	return a->d[D] < b->d[D];
}
ND* po[int(5e5 + 1) << 2];
ND* build(int l, int r, int d) {
	if (l > r) return 0;
	D = d;
	int mid = l + r >> 1;
	std::nth_element(po + l, po + mid, po + r + 1, cmp);
	ND* p = po[mid];
	p->ch[0] = build(l, mid - 1, d^1);
	p->ch[1] = build(mid + 1, r, d^1);
	p->up();
	return p;
}
void dfs(ND* u) {
	if (!u) return;
	dfs(u->ch[0]);
	po[++sz] = u;
	dfs(u->ch[1]);
}
void rebuild(ND*& u, int d) {
	sz = 0;
	dfs(u);
	u = build(1, sz, d);
}
void in(ND*& o, ND* p, int d) {
	if (!o) o = p;
	else in(o->ch[p->d[d] >= o->d[d]], p, d^1);
	o->up();
	int s = 0;
	for (int i = 0; i < 2; i++) if (o->ch[i]) s = std::max(s, o->ch[i]->sz);
	if (s > o->sz*fac) rebuild(o, d);
}
int x0, x1, y0, y1;
int query(ND* o) {
	if (!o || o->l[0] > x1 || o->r[0] < x0 || o->l[1] > y1 || o->r[1] < y0) return 0;
	if (x0 <= o->l[0] && o->r[0] <= x1 &&
			y0 <= o->l[1] && o->r[1] <= y1) return o->s;
	int s = 0;
	if (x0 <= o->d[0] && o->d[0] <= x1 &&
			y0 <= o->d[1] && o->d[1] <= y1) s += o->w;
	return s + query(o->ch[0]) + query(o->ch[1]);
}
int main() {
//	freopen("input", "r", stdin);
	freopen("bzoj_4066.in", "r", stdin);
	freopen("bzoj_4066.out", "w", stdout);
	scanf("%d", &n);
	while (1) {
		int t; 
		scanf("%d", &t);
		if (t == 1) {
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			x^=ans, y^=ans, w^=ans;
			ND* p = new ND(x, y, w);
			in(rt, p, 0);
		}
		else if (t == 2) {
			scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
			x0 ^= ans, x1^=ans, y0^=ans,y1^=ans;
			printf("%d\n", ans = query(rt));
		}
		else break;
	}
}
