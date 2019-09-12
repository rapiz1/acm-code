#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
namespace I {
	const int L = 1 << 15 | 1;
	char *s, *t, buf[L];
	inline char gc() {
		if (s == t) t = (s = buf) + fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int ch = gc(), x = 0;
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch)) x = x*10 + ch -'0', ch = gc();
		return x;
	}
}using I::gi;
using std::max;
using std::min;
const int N = int(5e5 + 10) << 1;
const double fac = 0.7;
int n, m, D, mem, rt;
struct ND {
	int d[2], mn[2], mx[2], ch[2], sz;
	bool operator<(const ND& b)const {return d[D] < b.d[D];}
	inline void rd() {
		d[0] = gi(), d[1] = gi();
	}
}a[N];
inline void up(int o) {
	a[o].sz = 1;
	for (int i = 0; i < 2; i++) {
		a[o].mn[i] = a[o].mx[i] = a[o].d[i];
		for (int j = 0; j < 2; j++) if (a[o].ch[j]) {
			a[o].mn[i] = min(a[o].mn[i], a[a[o].ch[j]].mn[i]);
			a[o].mx[i] = max(a[o].mx[i], a[a[o].ch[j]].mx[i]);
			a[o].sz += a[a[o].ch[j]].sz;
		}
	}
}
int build(int l, int r, int t) {
	if (l > r) return 0;
	int mid = l + r >> 1;
	D = t;
	std::nth_element(a + l, a + mid, a + r + 1);
	a[mid].ch[0] = build(l, mid - 1, t^1);
	a[mid].ch[1] = build(mid + 1, r, t^1);
	up(mid);
	return mid;
}
void in(int& o, int p, int t) {
	if (!o) o = p;
	else in(a[o].ch[a[p].d[t] > a[o].d[t]], p, t^1);
	up(o);
	if (a[o].sz*fac < max(a[a.ch[0]].sz, a[a.ch[1]].sz)) rebulid(o, t);
}
int x, y, ans;
inline int val(int o) {
	return o ? max(max(a[o].mn[0] - x, x - a[o].mx[0]), 0) + max(max(a[o].mn[1] - y, y - a[o].mx[1]), 0): 1e9;
}
void query(int o) {
	if (!o) return;
	ans = min(abs(a[o].d[0] - x) + abs(a[o].d[1] - y), ans);
	int gd[2];
	gd[0] = val(a[o].ch[0]), gd[1] = val(a[o].ch[1]);
	int t = gd[1] < gd[0];
	if (gd[t] < ans) query(a[o].ch[t]);
	t^=1;
	if (gd[t] < ans) query(a[o].ch[t]);
}
int main() {
	n = gi(), m = gi();
	for (int i = 1; i <= n; i++) {
		a[++mem].rd();
		up(i);
	}
	rt = build(1, mem, 0);
	while (m--) {
		int t = gi();
		x = gi(), y = gi();
		if (t == 1) {
			++mem;
			a[mem].d[0] = x, a[mem].d[1] = y;
			up(mem);
			in(rt, mem, 0);
		}
		else if (t == 2) {
			ans = 1e9;
			query(rt);
			printf("%d\n", ans);
		}
	}
}
