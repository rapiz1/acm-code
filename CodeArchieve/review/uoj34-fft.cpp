#include <cstdio>
#include <cmath>
#include <complex>
typedef std::complex<double> num;
const int N = 1 << 20 | 1;
const double PI = acos(-1);
int n = 1;
num a[N], b[N], e[N][2];
void fft(num* x, bool rev = 0) {
	for (int i = 0, j = 0; i != n; ++i) {
		if (i > j) std::swap(x[i], x[j]);
		for (int l = n>>1; (j^=l) < l; l>>=1);
	}
	for (int i = 2; i <= n; i<<=1) {// enum length of merge calcution
		int m = i >> 1;// length of half of the operation block
		for (int j = 0; j < n; j += i) {// enum the start position
			for (int k = 0; k < m; k++) {
				num z = x[j + m + k]*e[n/i*k][rev];
				x[j + m + k] = x[j + k] - z;
				x[j + k] += z;
			}
		}
	}
	if (rev) for (int i = 0; i < n; i++) x[i]/=n;
}
int main() {
//	freopen("input", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	while (n + m + 1 >= ::n) ::n<<=1;
	for (int i = 0; i <= ::n; i++) e[i][0] = num(cos(2*PI*i/::n), sin(2*PI*i/::n)), e[i][1] = std::conj(e[i][0]);
	for (int i = 0, x; i <= n; i++) scanf("%d", &x), a[i].real(x);
	for (int i = 0, x; i <= m; i++) scanf("%d", &x), b[i].real(x);
	fft(a), fft(b);
	for (int i = 0; i <= ::n; i++) a[i]*=b[i];
	fft(a, 1);
	for (int i = 0; i <= n + m; i++) printf("%d ", int(a[i].real() + 0.5));
}
