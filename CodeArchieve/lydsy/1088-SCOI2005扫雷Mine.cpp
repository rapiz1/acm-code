#include <cstdio>
#include <cstring>
const int N = 1e4 + 10;
int n, a[N], b[N], ans;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int k = 0; k <= 1; k++) {
		b[1] = k;
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			b[i + 1] = a[i] - b[i] - b[i - 1];
			if (b[i + 1] > 1 || b[i + 1] < 0) {flag=0;break;}
		}
		if (b[n + 1]) flag=0;
		ans += flag;
	}
	printf("%d\n", ans);
}
