#include <cstdio>
#include <cctype>
#include <algorithm>
#include <complex>
#include <cstring>
typedef std::complex<double> num;
const int N = 1 << 18;
const double PI = acos(-1);
int n, nn;
char s[N];
num a[N], b[N], e[N][2];
void fft(int n, num* x, bool rev = 0) {
	for (int i = 0, j = 0; i < n; i++) {
		if (i > j) std::swap(x[i], x[j]);
		for (int l = n>>1; (j^=l) < l; l>>=1);
	}
	for (int i = 2; i <= n; i <<= 1)
		for (int m = i>>1, j = 0; j < n; j += i)
			for (int k = 0; k < m; k++) {
				num z = x[j + k + m]*e[n/i*k][rev];
				x[j + k + m] = x[j + k] - z;
				x[j + k] += z;
			}
	if (rev) for (int i = 0; i < n; i++) x[i] /= n;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%s", &n, s + 1);
	for (int i = n; i; i--) a[n - i] = s[i] - '0';
	scanf("%s", s + 1);
	for (int i = n; i; i--) b[n - i] = s[i] - '0';
	for (nn = 1; nn < 2*n; nn <<= 1);
	for (int i = 0; i < nn; i++) e[i][0] = num(cos(PI*2*i/nn), sin(PI*2*i/nn)), e[i][1] = std::conj(e[i][0]);
	fft(nn, a), fft(nn, b);
	for (int i = 0; i < nn; i++) a[i]*=b[i];
	fft(nn, a, 1);
	memset(s, 0, sizeof s);
	for (int i = 0, g = 0; i <= 2*n + 1; i++) {
		g += int(a[i].real() + 0.5);
		s[i] = g%10 + '0';
		g/=10;
	}
	int ss = 2*n + 1;
	for (;s[ss] == '0'; ss--);
	for (;~ss;putchar(s[ss--]));
}
