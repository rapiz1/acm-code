#include <cstdio>
#include <cassert>
const int N = 1e7 + 10, SZ = 7e5;
typedef long long ll;
int sz, m, pri[SZ], fac[N], fph[N];
bool vis[N], ip[N];
int qpow(int x, int r) {
	if (!x) return 0;
	x%=m;
	int ret = 1;
	while (r) {
		if (r&1) ret = (ll)ret*x%m;
		r>>=1, x=(ll)x*x%m;
	}
	return ret;
}
int main() {
//	freopen("input", "r", stdin);
	int T;
	scanf("%d%d", &T, &m);
	for (int i = 2; i < N; i++) {
		if (!vis[i]) pri[++sz] = i, vis[i] = 1;
		for (int j = 1; j <= sz; j++) {
			ll k = (ll)i*pri[j];
			if (k > N) break;
			vis[k] = 1;
			if (i%pri[j] == 0) break;
		}
	}
	for (int i = 1; i <= sz; i++) ip[pri[i]] = 1;
	fac[1] = fph[1] = 1;
	for (int i = 2; i < N; i++) {
		fac[i] = (ll)fac[i - 1]*i%m;
		fph[i] = fph[i - 1];
		if (ip[i]) fph[i] = (ll)fph[i]*(i - 1)%m*qpow(i, m - 2)%m;
	}
	while (T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", int((ll)fph[b]*fac[a]%m));
	}
}
