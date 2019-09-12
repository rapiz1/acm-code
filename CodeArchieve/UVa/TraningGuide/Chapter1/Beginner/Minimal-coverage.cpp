#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 1e5 + 10;
struct L{int l, r;
	bool operator<(const L& b)const {return l < b.l;}
}a[N];
int n, m;
std::vector<L> sol;
int main() {
//	freopen("input", "r", stdin);
	int T;scanf("%d", &T);
	while (T--) {
		sol.clear();
		scanf("%d", &m);
		n = 0;
		while (scanf("%d%d", &a[n + 1].l, &a[n + 1].r)) 
			if (a[n + 1].l == 0 && a[n + 1].r == 0) break;
			else if (a[n + 1].r < 0) ;
			else ++n;
		bool f = 1;
		std::sort(a + 1, a + 1 + n);
		if (a[1].l > 0) f = 0;
		int ans = 0, l = 0, i = 1;
		while (i <= n && l < m) {
			L now;
			int r = l;
			while (i <= n && a[i].l <= l) {
				if (a[i].r > r)  now = a[i];
				r = std::max(r, a[i++].r);
			}
			if (l == r) {
				f = 0;
				break;
			}
			l = r;
			sol.push_back(now);
			++ans;
		}
		if (l < m) f = 0;
		printf("%d\n", f ? ans : 0);
		if (f) for (int i = 0; i < sol.size(); i++) printf("%d %d\n", sol[i].l, sol[i].r);
	}
}
