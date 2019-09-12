#include <cstdio>
const int N = 1e5 + 10;
int n;
double a, m[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%lf", &n, &a);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", m + i);
		int k = i*a + 1e-8;
		if (k <= 500) {
			double ans = 0;
			for (int j = 1; j <= k; j++) ans += (m[j] - m[j - 1])*m[i]/(i - j);
			printf("%lf\n", ans);
		}
		else printf("%lf\n", m[i]*m[k]*2/(i - k + i - 1));
		m[i] += m[i - 1];
	}
}
