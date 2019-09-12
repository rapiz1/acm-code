#include <cstdio>
#include <algorithm>
const int N = 1e3 + 10;
typedef long long ll;
int n, m, k;
ll f[N];
struct Pack {
	int s, v;
	bool operator<(const Pack& rhs)const {return v > rhs.v;}
}a[N];
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].s, &a[i].v);
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = m; j; j--) if (j >= a[i].s)
			f[j] = std::max(f[j], f[j - a[i].s] + a[i].v);
		if (f[m] >= k) {
			printf("%d\n", a[i].v);
			return 0;
		}
	}
	puts("-1");
}
