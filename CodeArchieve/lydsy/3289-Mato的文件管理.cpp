#include <cstdio>
#include <algorithm>
#include <cmath>
const int N = 50010;
int n, q, a[N], th[N], v[N], bk, ans[N];
struct Q {int l, r, i;}st[N];
bool cmp(int x, int y) {return a[x] < a[y];}
bool cmp2(const Q& x, const Q& y) {return x.l/bk < y.l/bk || (x.l/bk == y.l/bk && x.r < y.r);}
inline int lowbit(int x) {return x&-x;}
inline void add(int p, int x) {
	while (p <= n + 1) v[p] += x, p += lowbit(p);
}
inline int pre(int p) {
	int s = 0;
	while (p) s += v[p], p -= lowbit(p);
	return s;
}
inline int sum(int l, int r) {return pre(r) - pre(l - 1);} int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	bk = pow(n, 2.0/3);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), th[i] = i;
	std::sort(th + 1, th + 1 + n, cmp);
	for (int i = 1, j = 0; i <= n; i++) {
		int s = i;
		while (i + 1 <= n && a[th[i]] == a[th[i + 1]])  i++;
		++j;
		while (s <= i) a[th[s++]] = j;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) scanf("%d%d", &st[i].l, &st[i].r), st[i].i = i;
	std::sort(st + 1, st + 1 + q, cmp2);
	int l = 1, r = 1, c = 0;
	add(a[1], 1);
	for (int i = 1; i <= q; i++) {
		int ll = st[i].l, rr = st[i].r;
		while (l > ll) --l, c += pre(a[l] - 1), add(a[l], 1);
		while (r < rr) ++r, c += sum(a[r] + 1, n + 1), add(a[r], 1); 
		while (l < ll) c -= pre(a[l] - 1), add(a[l++], -1);
		while (r > rr) c -= sum(a[r] + 1, n + 1), add(a[r--], -1);
		ans[st[i].i] = c;
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}
