#include <cstdio>
#include <cmath>
#include <algorithm>
using std::max;
const double PI = acos(-1);
const int N = 1e5 + 10;
struct L {double l, r;
	bool operator<(const L& b)const {return l < b.l;}
} a[N];
int n, l, w;
int main() {
//	freopen("input", "r", stdin);
	while (scanf("%d%d%d", &n, &l, &w) != EOF) {
		for (int i= 1 ; i <= n; i++) {
			int pos, rad;
			scanf("%d%d", &pos, &rad);
			double dd = 1.0*rad*rad - (w/2.0)*(w/2.0);
			if (dd >= 0) dd = sqrt(dd);
			else a[i].l = a[i].r = l + 10;
			a[i].l = pos - dd;
			a[i].r = pos + dd;
		}
		std::sort(a + 1, a + 1 + n);
		int i = 1, s = 0;
		double r = 0;
		while (i <= n && r < l) {
			double rr = r;
			bool f = 1;
			for (; i <= n; i++) if (a[i].l <= r) rr = max(rr, a[i].r), f = 0; 
			else break;
			if (f) break;
			r = rr;
			++s;
		}
		printf("%d\n", r >= l ? s : -1);
	}
}
