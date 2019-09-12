#include <cstdio>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>
const int N = 55;
int n, m, hv[N], mxl, ans;
namespace Dense {
int ned[130];
void dfs(int p, int q, int na) {
	if (clock()*10/CLOCKS_PER_SEC > 9) {
		printf("%d\n", ans);
		exit(0);
	}
	if (p > mxl) {
		ans = std::max(ans, na);
		return;
	}
	if (q > n || !ned[p]) {
		int opt = na, sum = 0;
		for (int i = 1; i <= n; i++) sum += hv[i];
		for (int i = p + 1; i <= mxl && sum; i++) {
			int x = std::min(ned[i], sum/i);
			sum -= x*i;
			opt += x;
		}
		if (opt <= ans) return;
		dfs(p + 1, 1, na);
		return; 
	}
	for (int i = std::min(hv[q]/p, ned[p]); ~i; i--) {
		hv[q] -= i*p;
		ned[p] -= i;
		dfs(p, q + 1, na + i);
		ned[p] += i;
		hv[q] += i*p;
	}
}
}
namespace Sparse {
int ned[1030];
void dfs(int p, int na) {
	if (clock()*10/CLOCKS_PER_SEC > 9) {
		printf("%d\n", ans);
		exit(0);
	}
	if (p > m) {
		ans = std::max(ans, na);
		return;
	}
	int lf = 0, opt = na;
	for (int i = 1; i <= n; i++) lf += hv[i];
	for (int i = p; i <= m; i++) if (lf >= ned[i]) lf -= ned[i], opt++;
	else break;
	if (opt <= ans) return;
	for (int i = 1, la = -1; i <= n; i++) if (hv[i] >= ned[p]) {
		if (la == hv[i]) continue;
		hv[i] -= ned[p];
		dfs(p + 1, na + 1);
		hv[i] += ned[p];
		la = hv[i];
	}
	dfs(p + 1, na);
}
}
int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", hv + i);
	scanf("%d", &m);
	for (int i = 1, x; i <= m; i++) {
		scanf("%d", &x);
		Sparse::ned[i] = x;
		Dense::ned[x]++;
	 	mxl = x > mxl ? x : mxl;
	}
	double mmm = 0;
	for (int i = 1; i <= 128; i++) mmm += (bool)Dense::ned[i];
	if (mmm/m > 2) {
//		puts("Dense");
		Dense::dfs(1, 1, 0);
	}
	else {
//		puts("Sparse");
		std::sort(hv + 1, hv + 1 + n, std::greater<int>());
		std::sort(Sparse::ned + 1, Sparse::ned + 1 + m);
		Sparse::dfs(1, 0);
	}
	printf("%d\n", ans);
}
