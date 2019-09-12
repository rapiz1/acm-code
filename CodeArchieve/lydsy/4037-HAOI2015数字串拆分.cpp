#include <cstdio>
#include <cstring>
//#define DBG
typedef long long ll;
const int N = 600;
const ll MOD = 998244353;
struct Matrix{
	static const int L = 7;
	int n, m;
	ll a[L][L];
	Matrix() {memset(a, 0, sizeof a);}
	void operator*=(const Matrix& b) {
		Matrix c;
		c.n = n, c.m = b.m;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= b.m; j++) for (int k = 1; k <= m; k++)
			c.a[i][j] = (c.a[i][j] + a[i][k]*b.a[k][j])%MOD;
		*this = c;
	}
	void operator+=(const Matrix& b) {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = (a[i][j] + b.a[i][j])%MOD;
	}
#ifdef DBG
	void print() {
		for (int i = 1; i <= n; i++,putchar('\n')) for (int j = 1; j <= m; j++) printf("%lld ", a[i][j]);
	}
#endif
	void unit(int x) {
		n = m = x;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = i == j;
	}
}f[N], ee[600][11], s, tmp, tmp2;
Matrix qpow(Matrix a, int r) {
	Matrix ret;
	ret.unit(a.n);
	while (r) {
		if (r&1) ret *= a;
		r>>=1, a*=a;
	}
	return ret;
}
int n, m;
char str[N];
#ifdef DBG
void ptf(int n) {
//	n--;
	Matrix c = qpow(ee[0][0], n);
	c *= s;
	printf("%d: %lld\n", n, c.a[1][1]);
}
#endif
int main() {
	freopen("haoi2015_str.in", "r", stdin);
	freopen("haoi2015_str.out", "w", stdout);
	scanf("%s%d", str + 1, &m);
	n = strlen(str + 1);
	ee[0][1].n = ee[0][1].m = m;
	s.n = m, s.m = 1;
	s.a[1][1] = 1;
	ee[0][0].unit(m);
	for (int i = 1; i <= m; i++) ee[0][1].a[1][i] = ee[0][1].a[i + 1][i] = 1;
	for (int j = 2; j <= 9; j++) ee[0][j] = ee[0][j - 1], ee[0][j] *= ee[0][1];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 9; j++) ee[i][j] = qpow(ee[i - 1][j], 10);
	f[0].unit(m);
	for (int i = 1; i <= n; i++) f[i].n = f[i].m = m;
	for (int i = 1; i <= n; i++) {
		tmp.unit(m);
		for (int j = i - 1; ~j; j--) {
			tmp2 = ee[i - (j + 2) + 1][str[j + 1] - '0'];
			tmp *= tmp2;
			tmp2 = f[j];
#ifdef DBG
			int cc = 0;
			for (int k = j + 1; k <= i; k++) cc = cc*10 + str[k] - '0';
			printf("%d\n", cc);
			Matrix x = qpow(ee[0][0], cc);
			puts("cc");
			x.print();
			puts("tmp");
			tmp.print();
#endif
			tmp2 *= tmp;
			f[i] += tmp2;
		}
	}
	f[n] *= s;
	printf("%lld\n", f[n].a[1][1]);
}
