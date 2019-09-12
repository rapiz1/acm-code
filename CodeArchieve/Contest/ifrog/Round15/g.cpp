#include <cstdio>
#include <algorithm>
const int N = 1e5 + 10;
int n, a[N], b[N], sk[N], top;
long long ans[N];
bool cmp(int i, int j) {return i > j;}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1 ;i <= n; i++) scanf("%d", a + i);
	for (int i = 1 ;i <= n; i++) scanf("%d", b + i);
	for (int i = 1 ;i <= n; i++) {
		while (top && a[sk[top]] > a[i]) top--;
		sk[++top] = i;
		int p = std::lower_bound(sk + 1, sk + 1 + top, i - b[i] + 1) - sk;
		ans[i] = a[sk[p]];
	}
	top = 0;
	for (int i = 1 ;i <= n; i++) {
		while (top && a[sk[top]] < a[i]) top--;
		sk[++top] = i;
		int p = std::lower_bound(sk + 1, sk + 1 + top, i - b[i] + 1) - sk;
		ans[i] *= a[sk[p]];
	}
	for  (int i = 1; i <= n; i++) {
		printf("%lld\n", ans[i]);
	}
}
