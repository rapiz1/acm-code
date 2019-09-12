#include <cstdio>
#include <algorithm>
#include <assert.h>
#define file(x) "Load_Balancing." #x
const int N = 1e5 + 10, W = 1e6 + 10;
struct P{int x,y;
	bool operator<(const P& b)const {return x < b.x;}
}st[N];
int n, ans, mxy;
struct BIT {
	int a[W];
	inline int lowbit(int x) {return x&-x;}
	inline void add(int p, int x) {
		while (p <= mxy) a[p] += x, p += lowbit(p);
	}
	inline int pre(int p) {
		int s = 0;
		while (p) s += a[p], p -= lowbit(p);
		return s;
	}
}le, ri;
inline int get(int mid) {
	int	lu = le.pre(mid), ru = ri.pre(mid),
					ld = le.pre(mxy) - lu,
					rd = ri.pre(mxy) - ru;
	int s = std::max(std::max(ld, rd), std::max(lu, ru));
	ans = std::min(ans, s);
	return s;
}

int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	ans = n;
	for (int i = 1; i <= n; i++) scanf("%d%d", &st[i].x, &st[i].y), mxy = std::max(mxy, st[i].y + 1);
	for (int i = 1; i <= n; i++) ri.add(st[i].y, 1);
	std::sort(st + 1, st + 1 + n);
	for (int k = 0; k <= n;) {
		if (k) {
			int j = k;
			while (j + 1 <= n && st[j + 1].x == st[k].x) j++;
			while (k <= j) le.add(st[k].y, 1), ri.add(st[k++].y, -1);
		}
		else k++;
		int l = 0, r = mxy + 1;
		while (l < r) {
			int	mid = l + r >> 1, ld = le.pre(mid), rd = ri.pre(mid),
					lu = le.pre(mxy) - ld,
					ru = ri.pre(mxy) - rd,
					up = std::max(lu, ru),
					down = std::max(ld, rd);
			get(l), get(mid), get(r);
			if (up > down) l = mid + 1;
			else r = mid;
		}
		l = 0, r = mxy + 1;
		while (l < r) {
			int	mid = l + r >> 1, ld = le.pre(mid), rd = ri.pre(mid),
					lu = le.pre(mxy) - ld,
					ru = ri.pre(mxy) - rd,
					up = std::max(lu, ru),
					down = std::max(ld, rd);
			get(l), get(mid), get(r);
			if (up < down) l = mid + 1;
			else r = mid;
		}
	}
	printf("%d", ans);
}
