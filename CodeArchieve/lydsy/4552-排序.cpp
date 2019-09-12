#include <cstdio>
#define lch (o<<1)
#define rch (o<<1|1)
#define mid ((l+r)>>1)
const int V = int(1e5 + 10) << 2, N = 1e5 + 10;
int n, m, sz, s[V], cov[V], a[N], ans, q;
struct Op {int t, l, r;}st[N];
void mkcov(int o, int l, int r, int v) {
	if (o) {
		cov[o] = v;
		s[o] = (r - l + 1)*v;
	}
}
inline void down(int o, int l, int r) {
	if (cov[o] != -1) mkcov(lch, l, mid, cov[o]), mkcov(rch,mid+1, r, cov[o]), cov[o]=-1;
}
inline void up(int o) {
	s[o] = s[lch] + s[rch];
}
void build(int o, int l, int r) {
	cov[o] = -1;
	if (l == r) {
		s[o] = a[l] >= ans;
	}
	else {
		build(lch, l, mid);
		build(rch, mid+1, r);
		up(o);
	}
}
int query(int o, int l, int r, int q1, int q2) {
	if (q1 <= l && r <= q2)
		return s[o];
	down(o, l, r);
	int ret = 0;
	if (q1 <= mid) ret += query(lch, l, mid, q1, q2);
	if (mid < q2) ret += query(rch, mid+1, r, q1, q2);
	return ret;
}
void change(int o, int l, int r, int q1, int q2, int q3) {
	if (q1 > q2) return;
	if (q1 <= l && r <= q2) {
		mkcov(o, l, r, q3);
		return;
	}
	down(o, l, r);
	if (q1 <= mid) change(lch, l, mid, q1, q2, q3);
	if (mid < q2) change(rch, mid+1, r, q1, q2, q3);
	up(o);
}

void show(int o, int l, int r) {
	if (l == r) printf("%d ", s[o]);
	else down(o, l, r), show(lch, l, mid), show(rch, mid+1, r);
}
void pt() {
	show(1, 1, n);
	puts("");
}
inline bool check(int x) {
	ans = x;
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int s = query(1, 1, n, st[i].l, st[i].r);
		if (st[i].t == 0) {
			change(1, 1, n, st[i].l, st[i].r - s, 0);
			change(1, 1, n, st[i].r - s + 1, st[i].r, 1);
		}
		else {
			change(1, 1, n, st[i].l, st[i].l + s - 1, 1);
			change(1, 1, n, st[i].l + s, st[i].r, 0);
		}
	}
	return query(1, 1, n, q, q) == 1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &st[i].t, &st[i].l, &st[i].r);
	}
	scanf("%d", &q);
	int l = 1, r = n;
	while (l < r) {
		int mm = (l + r + 1) >> 1;
		if (check(mm)) l = mm;
		else r = mm - 1;
	}
	printf("%d\n", l);
}
