#include <cstdio>
int n, k;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
double x;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", a + i);
	 	a[i] += a[i - 1];
		if (i >= k) x += a[i] - a[i - k];
	}
	printf("%.11lf", x/(n - k + 1));
}
