#include <cstdio>
typedef long long ll;
const int M = 1e6 + 3;
int rev[M], fac[M];
inline int comb(int n, int m) {
	if (n < m) return 0;
	if (n < M && m < M) return (ll)fac[n]*rev[n - m]*rev[m]%M;
	else return (ll)comb(n/M, m/M)*comb(n%M, m%M)%M;
}
int main() {
//	freopen("input", "r", stdin);
	int t; scanf("%d", &t);
	rev[0] = fac[0] = fac[1] = rev[1] = 1;
	for (int i = 2; i < M; i++) rev[i] = M - (M/i)*(long long)rev[M%i]%M;
	for (int i = 2; i < M; i++) fac[i] = (ll)i*fac[i - 1]%M, rev[i] = (ll)rev[i - 1]*rev[i]%M;
	while (t--) {
		int n, l, r;
		scanf("%d%d%d", &n, &l, &r);
		int m = r - l;
		printf("%d\n", (comb(m + n + 1, n) - 1 + M)%M);
	}
}
