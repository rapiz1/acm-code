#include <cstdio>
const int N = 50010;
int n, m, a[N], t[N];
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	while (m--) {
		int l, r, k;scanf("%d%d%d", &l, &r, &k);
		for (int i = l; i <= r; i++) t[a[i]]++;
		int ans = 0;
		for (int i = l; i <= r; i++) if (t[a[i]]) {
			ans += gcd(t[a[i]], k) == 1;
			t[a[i]] = 0;
		}
		printf("%d\n", ans);
	}
}
