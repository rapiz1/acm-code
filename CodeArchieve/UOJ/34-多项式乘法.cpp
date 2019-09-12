#include <cstdio>
#include <complex>
#include <cmath>
#include <algorithm>
const int N = 3e5 + 10;
typedef std::complex<double> num;
const double PI = acos(-1);
int nn = 1;
num e[N][2], a[N], b[N], c[N];
double ans[N];
void fft(int n, num x[N], bool rev = 0) {
	for (int i = 0, j = 0; i != n; ++i) { 
		if (i > j) std::swap(x[i], x[j]);
		for (int l = n>>1; (j^=l) < l; l>>=1);
	}
	for (int i = 2; i <= n; i<<=1) {
		int m = i >> 1;
		for (int j = 0; j < n; j += i)
			for (int k = 0; k < m; k++) {
				num z = x[j + m + k]*e[n/i*k][rev];
				x[j + m + k] = x[j + k] - z;
				x[j + k] += z;
			}
	}
	if (rev) for (int i = 0; i < n; i++) x[i] /= n;
}
void mul() {
	fft(nn, a);
	fft(nn, b);
	for (int i = 0; i < nn; i++) c[i] = a[i]*b[i];
	fft(nn, c, 1);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (;nn <= n + m + 1; nn<<=1);
	for (int i = 0; i < nn; i++)  e[i][0] = num(cos(2*PI*i/nn), sin(2*PI*i/nn)),
																e[i][1] = std::conj(e[i][0]);
	for (int i = 0, x; i <= n; i++) scanf("%d", &x), a[i] = x;
	for (int i = 0, x; i <= m; i++) scanf("%d", &x), b[i] = x;
	mul();
	for (int i = 0; i <= n + m; i++) printf("%d ", int(c[i].real() + 0.5));
}
