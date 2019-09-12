#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <stack>
namespace I {
	const int L = 1 << 15;
	char buf[L], *s, *t;
	inline char gc() {
		if (s == t) t = (s = buf) + fread(buf, 1, L, stdin);
		return *s++;
	}
	inline int gi() {
		int x = 0, ch = gc();
		while (!isdigit(ch)) ch = gc();
		while (isdigit(ch)) x = x*10 + ch - '0', ch = gc();
		return x;
	}
}using I::gi;
using std::max;
using std::min;
const int N = 1e6 + 10;
struct Q {int t, x, y, i;}qu[N], qq[N], meg[N];
int n, m, a[N], sz, ans[N], mxx, mxy;
inline int lowbit(int x){return x&-x;}
inline void add(int x, int v){
	while (x <= mxy) a[x] = max(a[x], v), x += lowbit(x);
}
inline int pre(int x) {
	int s = 0xc0c0c0c0;
	while (x) s = max(s, a[x]), x -= lowbit(x);
	return s;
}
inline void cl(int x) {
	while (x <= mxy) a[x] = 0xc0c0c0c0, x += lowbit(x);
}
std::stack<int> rec;
void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);
	int i = l, j = mid + 1, sz = 0;
	while (i <= mid || j <= r) {
		if (i > mid || (j <= r && qq[j].x < qq[i].x)) {
			if (qq[j].t == 2) ans[qq[j].i] = min(ans[qq[j].i], qq[j].x + qq[j].y - pre(qq[j].y));
			meg[sz++] = qq[j++];
		}
		else {
			if (qq[i].t == 1) add(qq[i].y, qq[i].x + qq[i].y), rec.push(i);
			meg[sz++] = qq[i++];
		}
	}
	while (!rec.empty()) {
		int x = rec.top();
		rec.pop();
		cl(qq[x].y);
	}
	memcpy(qq + l, meg, sz*sizeof(Q));
}
int main() {
//	freopen("input", "r", stdin);
//	freopen("output", "w", stdout);
	memset(ans, 0x3f, sizeof(ans));
	memset(a, 0xc0, sizeof(a));
	n = gi(), m = gi();
	int tot = 0;
	for (int i = 1; i <= n; i++) qu[i].x = gi(), qu[i].y = gi(), qu[i].t = 1, mxx = max(mxx, qu[i].x += 1), mxy = max(mxy, qu[i].y += 1);
	for (int i = n + 1; i <= n + m; i++) 
		qu[i].t = gi(), qu[i].x = gi(), qu[i].y = gi(), qu[i].i = qu[i].t == 1 ? 0 : ++tot, mxx = max(mxx, qu[i].x += 1), mxy = max(mxy, qu[i].y += 1);
	mxx++, mxy++;
	memcpy(qq, qu, sizeof(qu));
	n += m;
	solve(1, n);
	//TODO: roate
	for (int i = 1; i <= n; i++) qq[i] = qu[i], qq[i].x = mxx - qu[i].x, qq[i].y = mxy - qu[i].y;
	solve(1, n);
	for (int i = 1; i <= n; i++) qq[i] = qu[i], qq[i].x = qu[i].x, qq[i].y = mxy - qu[i].y;
	solve(1, n);
	for (int i = 1; i <= n; i++) qq[i] = qu[i], qq[i].x = mxx - qu[i].x, qq[i].y = qu[i].y;
	solve(1, n);
	for (int i = 1; i <= tot; i++) printf("%d\n", ans[i]);
}
