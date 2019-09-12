#include <cstdio>
#include <queue>
#include <algorithm>
const int N = 1e4 + 10;
struct J{int t, w;
	bool operator<(const J& b)const {return t > b.t;}
};
int n, l, r, mid, mx;
std::vector<J> a[20010];
inline bool check() {
	std::priority_queue<J> q;
	for (int i = 1; i <= mx; i++) {
		for (int j = 0; j < a[i].size(); j++) q.push(a[i][j]);
		for (int w = mid; w && !q.empty();) {
			J x = q.top();q.pop();
			if (i >= x.t) return 0;
			int d = std::min(w, x.w);
			x.w -= d;
			w -= d;
			if (x.w) q.push(x);
		}	
	}
	return q.empty();
}
int main() {
	freopen("input", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		mx = 0;
		for (int i = 1; i <= n; i++) {
			int s, t, w;
			scanf("%d%d%d", &s, &t, &w);
			a[s].push_back((J){t, w});
			mx = std::max(t, mx);	
		}
		l = 1, r = 10100;
		while (l < r) {
			mid = l + r >> 1;
			if (check()) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
		for (int i = 1; i <= mx; i++) a[i].clear();
	}
}
