#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#define nxd ((d + 1)%k)
using std::min;
using std::max;
const int N = 5e4 + 10, K = 5, M = 15, INF = 2e9 + 1;
int n, D, k, m, ans[M];
struct P{
	int d[K], mn[K], mx[K], ch[2];
	bool operator<(const P& b)const {return d[D] < b.d[D];}
	inline void rd() {
		for (int i = 0; i < k; i++) scanf("%d", &d[i]);
	}
}a[N];
inline void up(int o) {
	for (int i = 0; i < k; i++) a[o].mn[i] = a[o].mx[i] = a[o].d[i];
	for (int i = 0; i < 2; i++) if (a[o].ch[i])
		for (int j = 0; j < k; j++) a[o].mn[j] = min(a[o].mn[j], a[a[o].ch[i]].mn[j]), a[o].mx[j] = max(a[o].mx[j], a[a[o].ch[i]].mx[j]);
}
inline int sq(int x) {return x*x;}
inline int dis(int x, int y) {
	if (!x || !y) return INF;
	int s = 0;
	for (int i = 0; i < k; i++) s += sq(a[x].d[i] - a[y].d[i]);
	return s;
}
int build(int l, int r, int d) {
	if (l > r) return 0;
	int mid = l + r >> 1;
	D = d;
	std::nth_element(a + l, a + mid, a + r + 1);
	a[mid].ch[0] = build(l, mid - 1, nxd);
	a[mid].ch[1] = build(mid + 1, r, nxd);
	up(mid);
	return mid;
}
int acnt;
inline void addans(int o) {
	int dd = dis(o, n + 1);
	for (int i = 1; i <= min(acnt + 1, m); i++) if (dd < dis(ans[i], n + 1)) {
		for (int j = acnt; j > i; j--) ans[j] = ans[j - 1];
		ans[i] = o;
		acnt = min(acnt + 1, m);
		break;
	}
//	for (int i = 1; i < acnt; i++) assert(dis(ans[i], n + 1) < dis(ans[i + 1], n + 1));
}
inline int val(int o) {
	if (o) {
		int s = 0;
		for (int i = 0, c = n + 1; i < k; i++) s += sq(max(max(a[o].mn[i] - a[c].d[i], a[c].d[i] - a[o].mx[i]), 0));
		return s;
	}
	else return INF;
}
void query(int o) {
	if (!o) return;
	addans(o);
	int gd[2];
	gd[0] = val(a[o].ch[0]), gd[1] = val(a[o].ch[1]);
	int t = gd[1] < gd[0], dd = dis(ans[m], n + 1);
	if (dd >= gd[t]) query(a[o].ch[t]);
	t ^= 1;
	dd = dis(ans[m], n + 1);
	if (dd >= gd[t]) query(a[o].ch[t]);
}
int rt;
void solve() {
	for (int i = 1; i <= n; i++) a[i].rd(), up(i);
	rt = build(1, n, 0);
	int q;
	scanf("%d", &q);
	while (q--) {
		for (int i = 0; i < k; i++) scanf("%d", &a[n + 1].d[i]);
		scanf("%d", &m);
		memset(ans, 0, sizeof(ans));
		acnt = 0;
		query(rt);
		printf("the closest %d points are:\n", m);
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < k; j++) printf("%d", a[ans[i]].d[j]), j == k - 1 ? 0: putchar(' ');
			putchar('\n');
		}
	}
}
int main() {
	//freopen("input", "r", stdin);
	while (scanf("%d%d", &n, &k) == 2) solve();
}
