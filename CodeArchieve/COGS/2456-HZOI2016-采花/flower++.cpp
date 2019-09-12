#include <cstdio>
#include <cstring>
#define file(x) "flower++." #x
const int N = 2e5 + 10, LG = 38;
int n, m, c, pre[N], hed[N], rt[N << 1], tt[N], tot, ans, s[N*LG], ch[N*LG][2], sz;
void add(int& o, int p, int l, int r, int x, int d) {
	o = ++sz;
	s[o] = s[p];
	memcpy(ch[o], ch[p], sizeof(ch[p]));
	if (l == r) s[o] += d;
	else {
		int mid = (l + r) >> 1;
		if (x <= mid) add(ch[o][0], ch[p][0], l, mid, x, d);
		else add(ch[o][1], ch[p][1], mid + 1, r, x, d);
		s[o] = s[ch[o][0]] + s[ch[o][1]];
	}
}
int query(int o, int l, int r, int ll) {
	if (!o) return 0;
	if (l >= ll) return s[o];
	int mid = (l + r) >> 1, f = query(ch[o][1], mid + 1, r, ll) ; 
	if (ll <= mid) f += query(ch[o][0], l, mid, ll);
	return f;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d%d", &n, &c, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		pre[i] = hed[x];
		hed[x] = i;
		if (pre[i]) {
			++tot, add(rt[tot], rt[tot-1], 1, n, pre[i], 1);
		 	if (pre[pre[i]]) ++tot, add(rt[tot], rt[tot - 1], 1, n, pre[pre[i]], -1);
		}
		tt[i] = rt[tot];
	}
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l^=ans, r^=ans;
		printf("%d\n", ans = query(tt[r], 1, n, l));
	}
}
