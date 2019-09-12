#include <cstdio>
#include <algorithm>
#include <utility>
#define lch (o<<1)
#define rch (o<<1|1)
const int N = 5e4 + 10, MOD = 1e9 + 7;
int n, f[N], a[N], th[N], w, b[N];
int cmp(int i, int j) {return a[i] < a[j];}
typedef std::pair<int, int> pa;
pa st[N << 2];
pa merge(pa x, pa y) {
	if (x.first > y.first) ;
	else if (x.first < y.first) x = y;
	else (x.second += y.second)%=MOD;
	return x;
}
pa query(int o, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) return st[o];
	int mid = (l + r) >> 1;
	pa ret;
	if (ll <= mid) ret = merge(ret, query(lch, l, mid, ll, rr));
	if (mid < rr) ret = merge(ret, query(rch, mid + 1, r, ll, rr));
	return ret;
}
void change(int o, int l, int r, int p, const pa& x) {
	if (l == r) st[o] = merge(st[o], x);
	else {
		int mid = (l + r) >> 1;
		if (p <= mid) change(lch, l, mid, p, x);
		else change(rch, mid + 1, r, p, x);
		st[o] = merge(st[lch], st[rch]);
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) th[i] = i, scanf("%d", a + i);
	std::sort(th +  1, th + 1 + n, cmp);
	for (int i =  1, j; i <= n;) {
		for (j = i; j <= n && a[th[i]] == a[th[j]]; j++) ;
		++w;
		for (;i<j;i++) a[th[i]] = w;
	}
	change(1, 0, w, 0, pa(1, 1));
	for (int i = 1; i <= n; i++) {
		pa x = query(1, 0, w, 0, a[i] - 1);
		x.first++;
		change(1, 0, w, a[i], x);
	}
	printf("%d\n", st[1].second);
}
