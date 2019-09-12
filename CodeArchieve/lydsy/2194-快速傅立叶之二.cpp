#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <complex>
const int N = 1 << 19;
const double PI = acos(-1);
typedef std::complex<double> num;
int n, nn;
num a[N], b[N], e[N][2];
void fft(int n, num* x, bool rev = 0) {
	for (int i = 0, j = 0; i < n; i++) {
		if (i > j) std::swap(x[i], x[j]);
		for (int l = n>>1; (j^=l) < l; l>>=1);
	}	
	for (int i = 2; i <= n; i<<=1)
		for (int j = 0, m = i>>1; j < n; j+=i)
			for (int k = 0; k < m; k++) {
				num z = x[j + k + m]*e[n/i*k][rev];
				x[j + k + m] = x[j + k] - z;
				x[j + k] += z;
			}
	if (rev) for (int i = 0; i < n; i++) x[i] /= n;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for(nn=1;nn<3*n;nn<<=1);
	for (int i = 0; i < nn; i++) e[i][0] = num(cos(2*PI/nn*i), sin(2*PI/nn*i)), e[i][1] = std::conj(e[i][0]);
	for (int i= 0, x, y; i < n; i++) scanf("%d%d", &x, &y), a[i] = x, b[n - i] = y;
	fft(nn, a), fft(nn, b);
	for (int i = 0; i < nn; i++) a[i]*=b[i];
	fft(nn, a, 1);
	for (int i = 0; i < n; i++) printf("%d\n", int(a[n + i].real() + 0.5));
}
