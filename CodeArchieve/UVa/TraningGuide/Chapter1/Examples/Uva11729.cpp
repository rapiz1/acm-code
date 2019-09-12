#include <cstdio>
#include <algorithm>
const int N = 1e3 + 10;
struct J{int a, b;
bool operator<(const J& r)const {return b > r.b;}
}a[N];
int n, ks;
int main() {
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].a, &a[i].b);
		std::sort(a + 1, a + 1 + n);
		int ans = 0, p = 0;
		for (int i = 1; i <= n; i++) p += a[i].a, ans = std::max(ans, p + a[i].b);
		printf("Case %d: %d\n", ++ks, ans);
	}
}
