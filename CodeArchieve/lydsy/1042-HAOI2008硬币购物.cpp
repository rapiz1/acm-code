#include <cstdio>
typedef long long ll;
const int S = 1e5 + 10;
int c[4], d[4], s;
ll f[S];
int main() {
//	freopen("input", "r", stdin);
	f[0] = 1;
	for (int i = 0; i < 4; i++) {
		scanf("%d", c + i);
		for (int j = 1; j < S; j++) if (j >= c[i]) f[j] += f[j - c[i]];
	}
	int tot;scanf("%d", &tot);
	while (tot--) {
		for (int j = 0; j < 4; j++) scanf("%d", d + j);
		scanf("%d", &s);
		ll ans = 0;
		for (int k = 0; k < 1 << 4; k++) {
			int cc = 0, ocp = 0;
			for (int p = 0; p < 4; p++) if (k>>p&1) {
				cc++;
				ocp += (d[p] + 1)*c[p];
			}
			if (ocp <= s) ans += (cc&1?-1:1)*f[s - ocp];
		}
		printf("%lld\n", ans);
	}
}
