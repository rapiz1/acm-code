#include <cstdio>
#include <utility>
#include <algorithm>
#define lch (o<<1)
#define rch ((o<<1)|1)
#define mid ((l + r)>>1)
const int W = 6e4 + 10, DEL = 3e4, N = 15e3 + 10;
typedef std::pair<int, int> pa;
int n, w, h, ans, mx[W << 2], adv[W << 2];
pa st[N];
inline void mkad(int o, int v) {if (o) mx[o] += v, adv[o] += v;}
void down(int o) {
	if (o) mkad(lch, adv[o]), mkad(rch, adv[o]), adv[o] = 0;
}
void add(int o, int l, int r, int q1, int q2, int q3) {
	if (q1 <= l && r <= q2) mkad(o, q3), ans = std::max(ans, mx[o]);
	else {
		down(o);
		if (q1 <= mid) add(lch, l, mid, q1, q2, q3);
		if (mid < q2) add(rch, mid + 1, r, q1, q2, q3);
		mx[o] = std::max(mx[lch], mx[rch]);
		ans = std::max(ans, mx[o]);
	}
}
int main() {
	scanf("%d%d%d", &w, &h, &n);
	for (int i = 1, x, y; i <= n; i++) scanf("%d%d", &x, &y), st[i] = std::make_pair(x + DEL, y + DEL);
	std::sort(st + 1, st + 1 + n);
	for (int i = 1, j = 0; i <= n; i++) {
		while (j + 1 <= n && st[j + 1].first < st[i].first - w) ++j, add(1, 0, DEL<<1, st[j].second, st[j].second + h, -1);
		add(1, 0, DEL<<1, st[i].second, st[i].second + h, 1);
	}
	printf("%d\n", ans);
}
