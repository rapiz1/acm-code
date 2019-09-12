#include <cstdio>
#include <cmath>
#include <algorithm>
const int N = 2e5 + 10, SQN = 500;
int a[N], n, m, b[N], c[N], bk;
inline void build(int th) {
	int s = th*bk, t = std::min(n - 1, s + bk - 1);
	for (int i = t; i >= s; i--) {
		if (i + a[i] <= t) b[i] = b[i + a[i]] + 1, c[i] = c[i + a[i]];
		else b[i] = 1, c[i] = i + a[i];
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	bk = sqrt(n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i <= (n - 1)/bk; i++) build(i);
	scanf("%d", &m);
	while (m--) {
		int t, x, y;scanf("%d%d", &t, &x);
		if (t == 1) {
			int s = 0;
			while (x < n)
			 	s += b[x], x = c[x]; 
			printf("%d\n", s);
		}
		else {
			scanf("%d", &y);
			a[x] = y;
			build(x/bk);
		}
	}
}
