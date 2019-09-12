#include <cstdio>
#include <cstring>
typedef long long ll;
const int K = 60;
int n, q;
ll r[K + 1], nest[K + 1];
void solve() {
	memset(r, 0, sizeof r);
	memset(nest, 0, sizeof nest);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll x;scanf("%lld", &x);
		for (int j = K; ~j; j--) if (x>>j&1) {
			if (r[j]) x ^= r[j];
			else {r[j] = x;break;}
		}
	}	
	for (int i = 0; i <= K; i++) if (r[i])
		for (int j = i - 1; ~j; j--) if (r[i]>>j&1) r[i] ^= r[j];
//		for (int j = i + 1; j <= K; j++) if (r[j]>>i&1) r[j] ^= r[i];
	int cnt = 0;
	for (int i = 0; i <= K; i++) if (r[i]) nest[cnt++] = r[i];
	bool zero = cnt != n;
	scanf("%d", &q);
	while (q--) {
		ll k, ret = 0;scanf("%lld", &k);
		if (zero) k--;
		if (k < (1ll << cnt)) for (int i = 0; i <= K; i++) if (k>>i&1) ret^=nest[i];else;
		else ret = -1;
		printf("%lld\n", ret);
	}
}
int main() {
//	freopen("input", "r", stdin);
	int ks;scanf("%d", &ks);
	for (int i = 1;  i<= ks; i++) printf("Case #%d:\n", i), solve();
}

