#include <cstdio>
#include <cstring>
typedef long long ll;
struct M{
	int a[4][4], n, m;
}f, r, tmp, now;
ll n;
int m;
void mul(M& a, M& b) {
	static M c;
	memset(&c, 0, sizeof(c));
	c.n = a.n, c.m = b.m;
	for (int i = 1; i <= a.n; i++) for (int j = 1; j <= b.m; j++) for (int k = 1; k <= a.m; k++)
		c.a[i][j] = (c.a[i][j] + 1ll*a.a[i][k]*b.a[k][j])%m;
	memcpy(&a, &c, sizeof(c));
}
void qpow(ll x) {
	tmp = r;
	now.n = now.m = 3;
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) now.a[i][j] = i == j;	
	while (x) {
		if (x&1) mul(now, tmp);
		x >>= 1, mul(tmp, tmp);
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%lld%d", &n, &m);
	f.n = 1, f.m = 3, f.a[1][1] = 0, f.a[1][2] = 0, f.a[1][3] = 1;
	r.n = r.m = 3;
	r.a[2][1] = r.a[2][2] = r.a[3][1] = r.a[3][2] = r.a[3][3] = 1;
	for (ll k = 1; k <= n ;k*=10) {
		r.a[1][1] = k*10%m;
		if (k*10 <=n) qpow(k*9);
		else qpow(n - k + 1);
		mul(f, now);
	}
	printf("%d\n", f.a[1][1]);
}
