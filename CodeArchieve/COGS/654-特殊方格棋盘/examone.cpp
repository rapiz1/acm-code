#include <cstdio>
#define file(x) "examone." #x
const int N = 25, L = 1 << 20 | 1;
typedef long long ll;
int n, m, a[N];
ll f[L];
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n ,&m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x] |= 1 << y - 1;
	}
	int l = 1 << n;
	f[0] = 1;
	for (int k = 1; k <= n; k++) {
		for (int s = l - 1; s; s--) {
			for (int x = s&~a[k]; x; x -= x&-x) 
				f[s] += f[s&~(x&-x)];
		}
	}
	printf("%lld\n", f[l - 1]);
}
