#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
const int M = 10;
int n, per[M];
double r[M], ans, pos[M];
bool pk[M];
void dfs(int p) {
	if (p > n) {
		for (int i = 2; i <= n; i++) {
			pos[i] = 0;
			for (int j = 1; j < i; j++) pos[i] = std::max(pos[i], pos[j] + 2*sqrt(r[per[i]]*r[per[j]]));
		}
		double ll = 0, rr = 0;
		for (int i = 1; i <= n; i++) ll = std::min(ll, pos[i] - r[per[i]]), rr = std::max(pos[i] + r[per[i]], rr);
		ans = std::min(ans, rr - ll);
	}
	else for (int i = 1; i <= n; i++) if (!pk[i]) pk[i]=1, per[p]=i, dfs(p + 1), pk[i] = 0;
}
int main() {
	int T;scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans = 1e200;
		for (int i = 1; i <= n; i++) scanf("%lf", &r[i]);
		dfs(1);
		printf("%.3lf\n", ans);
	}
}
