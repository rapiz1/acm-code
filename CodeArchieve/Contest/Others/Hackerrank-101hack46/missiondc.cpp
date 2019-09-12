#include <cstdio>
#include <algorithm>
#include <cstring>
#define lch (o << 1)
#define rch (o << 1 | 1)
using std::max;
const int N = 2e5 + 10, V = N << 2;
int n, dx, dy, rt, mxw;
long long ans = -1e9, mx[V];
struct C{
	int x, y, h, p;
	long long f;
	bool operator<(const C& b) {return h < b.h;}
	void rd() {
		scanf("%d%d%d%d", &x, &y,&h, &p);
		mxw = max(mxw, max(x, y));
		f = p;
	}
}ci[N], mg[N];
bool cmpx(const C& a, const C& b) {return a.x < b.x;}
int q1;
long long q2;
void change(int o, int l, int r) {
	if (l == r) mx[o] = q2;
	else {
		int mid = l + r >> 1;
		if (q1 <= mid) change(lch, l, mid);
		else change(rch, mid + 1, r);
		mx[o] = max(mx[rch], mx[lch]);
	}
}
long long query(int o, int l, int r) {
	if (q1 <= l && r <= q2) return mx[o];
	int mid = l + r >> 1;
	long long s = -1e9;
	if (q1 <= mid) s = max(s, query(lch, l, mid));
	if (q2 > mid) s = max(s, query(rch, mid + 1, r));
	return s;
}
void solve(int l, int r) {
	if (l == r) ci[l].f = max((long long)ci[l].p, ci[l].f);
	else {
		int mid = l + r >> 1;
		solve(l, mid);
		std::sort(ci + l, ci + mid + 1, cmpx);
		std::sort(ci + mid + 1, ci + r + 1, cmpx);
		int i, ll, rr;
		for (i = mid + 1, ll = l, rr = ll - 1; i <= r; i++) {
			while (rr + 1 <= mid && ci[rr + 1].x <= ci[i].x + dx) {
				++rr;
				q1 = ci[rr].y, q2 = ci[rr].f;
				change(1, 1, mxw);
			}
			while (ll <= mid && ci[ll].x < ci[i].x - dx) {
				q1 = ci[ll].y, q2 = -1e9;
				change(1, 1, mxw);
				++ll;
			}
			q1 = ci[i].y - dy, q2 = ci[i].y + dy;
			ci[i].f = max(ci[i].f, query(1, 1, mxw) + ci[i].p);
		}
		while (ll <= rr) q1 = ci[ll].y, q2 = -1e9, change(1, 1, mxw), ll++;
		std::sort(ci + mid + 1, ci + r + 1);
		solve(mid + 1, r);
	}
}
int main() {
	freopen("input", "r", stdin);
	scanf("%d%d%d", &n, &dx, &dy);
	memset(mx, 0xc0, sizeof(mx));
	for (int i = 1; i <= n; i++) ci[i].rd();
	std::sort(ci + 1, ci + 1 + n);
	for (int i = 1; i <= n; i++) ci[i].h = i;
	solve(1, n);
	for (int i = 1; i <= n; i++) ans = max(ans, ci[i].f);
	printf("%lld", ans);
}
