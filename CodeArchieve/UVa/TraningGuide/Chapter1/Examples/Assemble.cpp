#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using std::max;
using std::min;
const int N = 1e4 + 10;
struct P {int c, w;};
std::vector<P> p[N];
std::map<std::string, int> mm;
int n, T, b, l, r, mid, ct;
char ty[30];
inline bool check() {
	int s = 0;
	for (int i = 1; i <= ct; i++) {
		int mn = 1e6 + 1;
		for (int j = 0; j < p[i].size(); j++)
		  if (p[i][j].w >= mid) mn = min(p[i][j].c, mn);
		if (mn == 1e6 + 1) return 0;
		s += mn;
	}
	return s <= b;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		l = r = ct = 0;
		scanf("%d%d", &n, &b);
		for (int i = 1; i <= n; i++) {
			int c, w;
			scanf("%s%*s%d%d", ty, &c, &w);
			if (!mm.count(ty)) mm[ty] = ++ct;
			p[mm[ty]].push_back((P){c, w});
			r = max(r, w);
		}
		while (l < r) {
			mid = l + r + 1>> 1;
			if (check()) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
		for (int i = 1; i <= ct; i++) p[i].clear();
		ct = 0;
		mm.clear();
	}
}
