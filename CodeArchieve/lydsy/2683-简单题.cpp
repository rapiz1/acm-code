#include <cstdio>
#include <cctype>
#include <cstring>
#include <stack>
const int N = 2e6 + 10;
namespace I{
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
struct Q{int x, y, t, i;}qu[N], mg[N];
int n, a[N], ans[N];
inline int lowbit(int x){return x&-x;}
inline void add(int p, int v) {
	while (p < N) a[p] += v, p += lowbit(p);
}
inline int pre(int p) {
	int s = 0;
	while (p) s += a[p], p -= lowbit(p);
	return s;
}
std::stack<int> rec;
void solve(int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1;
	solve(l, mid), solve(mid + 1, r);
	int i = l, j = mid + 1, sz = 0;
	while (i <= mid || j <= r) {
		if (i > mid || (j <= r && qu[j].x < qu[i].x)) {
			int f = qu[j].i > 0 ? 1 : -1;
			if (qu[j].t == 2) ans[f*qu[j].i] += f*pre(qu[j].y);
			mg[sz++] = qu[j++];
		}
		else {
			if (qu[i].t == 1) add(qu[i].y, qu[i].i), rec.push(i);
			mg[sz++] = qu[i++];
		}
	}
	while (!rec.empty()) {
		int x = rec.top(); rec.pop();
		add(qu[x].y, -qu[x].i);
	}
	memcpy(qu + l, mg, sizeof(Q)*sz);
}
int main() {
//	freopen("input", "r", stdin);
	int sz = 0, tot = 0;
	n = gi();
	while (1) {
		++sz;
		if ((qu[sz].t=gi()) == 1) {
			qu[sz].x = gi(), qu[sz].y = gi(), qu[sz].i = gi();
		}
		else {
			if (qu[sz].t == 3) {
				sz--;
				break;
			}
			int x1 = gi(), y1 = gi(), x2 = gi(), y2 = gi();
			qu[sz].i = ++tot;
			qu[sz].x = x1 - 1, qu[sz].y = y1 - 1;
			qu[sz + 1].x = x1 - 1, qu[sz + 1].y = y2, qu[sz + 1].i = -tot, qu[sz + 1].t = 2;
			qu[sz + 2].x = x2, qu[sz + 2].y = y1 - 1, qu[sz + 2].i = -tot, qu[sz + 2].t = 2;
			qu[sz + 3].x = x2, qu[sz + 3].y = y2, qu[sz + 3].i = tot, qu[sz + 3].t = 2;
			sz += 3;
		}
	}
	solve(1, sz);
	for (int i = 1; i <= tot; i++) printf("%d\n", ans[i]);
}
