#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#define file(x) "mokia." #x
const int QU = 160000*4 + 10010, W = 2e6 + 10;
struct Q{int x, y, i, f, t;
	bool operator<(const Q& b)const {return x < b.x;}
}q[QU], mg[QU];
inline int lowbit(int x){return x&-x;}
int n, sz, a[W], ans[QU], s;
inline void add(int p, int v) {
	while (p <= n) a[p] += v, p += lowbit(p);
}
inline int pre(int p) {
	int s = 0;
	while (p) s += a[p], p -= lowbit(p);
	return s;
}
inline void mk(const Q& x) {
	if (x.t == 1) add(x.y, x.f);
	else ans[x.i] += pre(x.y)*x.f;
}
std::stack<int> rec;
void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);
	int i = l, j = mid + 1, dd = 0;
	while (i <= mid || j <= r) {
		if (i > mid || (j <= r && q[j].x < q[i].x)) {
			if (q[j].t == 2) mk(q[j]);
			mg[dd++] = q[j++];
		}
		else {
			if (q[i].t == 1) mk(q[i]), rec.push(i);
			mg[dd++] = q[i++];
		}
	}
	while (!rec.empty()) {
		int x = rec.top();rec.pop();
		add(q[x].y, -q[x].f);
	}
	memcpy(q + l, mg, dd*sizeof(Q));
}
int main() {
//	freopen("input", "r", stdin);
//	freopen(file(in), "r", stdin);
//	freopen(file(out), "w", stdout);
	scanf("%d%d", &s, &n);
	for (int i = 1; i <= n; i++) add(i, s);
	int qq = 0;
	while (scanf("%d", &q[sz + 1].t) && q[sz + 1].t != 3) {
		++sz;
		if (q[sz].t == 1) {
			scanf("%d%d%d", &q[sz].x, &q[sz].y, &q[sz].f);
		}
		else {
			++qq;
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			q[sz] = (Q){x1 - 1, y1 - 1, qq, 1, 2};
			q[sz + 1] = (Q){x2, y2, qq, 1, 2};
			q[sz + 2] = (Q){x1 - 1, y2,  qq, -1, 2};
			q[sz + 3] = (Q){x2, y1 - 1, qq, -1, 2};
			sz += 3;
		}
	}
	solve(1, sz);
	for (int i = 1; i <= qq; i++) printf("%d\n", ans[i]); 
}
