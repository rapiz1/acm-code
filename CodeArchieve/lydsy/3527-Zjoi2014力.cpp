#include <cstdio>
#include <complex>
#include <cmath>
#include <algorithm>
const int N = 3e5 + 10;
typedef std::complex<double> num;
const double PI = acos(-1);
int n, nn = 1;
num e[N][2], a[N], b[N], c[N];
double ans[N], q[N];
void fft(int n, num x[N], bool rev = 0) {
	for (int i = 0, j = 0; i < n; ++i) { 
		if (i > j) std::swap(x[i], x[j]);
		for (int l = n>>1; (j^=l) < l; l>>=1);
	}
	for (int i = 2; i <= n; i<<=1) {
		int m = i >> 1;
		for (int j = 0; j < n; j += i)
			for (int k = 0; k < m; k++) {
				num z =  x[j + k + m]*e[n/i*k][rev];
				x[j + k + m] = x[j + k] - z; 
				x[j + k] += z;
			}
	}
	if (rev) for (int i = 0; i < n; i++) x[i]/=n;
}
void mul() {
	fft(nn, a);
	fft(nn, b);
	for (int i = 0; i < nn; i++) c[i] = a[i]*b[i];
	fft(nn, c, 1);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (;nn < 2*n; nn<<=1);
	for (int i = 0; i < nn; i++)  e[i][0] = num(cos(2*PI*i/nn), sin(2*PI*i/nn)),
																e[i][1] = std::conj(e[i][0]);
	for (int i = 0; i < n; i++) scanf("%lf", q + i), a[i] = q[i];
	for (int i = 1; i < n; i++) b[i] = 1.0/i/i;
	mul();
	for (int i = 0; i < nn; i++) a[i] = b[i] = 0;
	for (int i = 0; i < n; i++) ans[i] += c[i].real(), a[i] = q[n - 1 - i];
	for (int i = 1; i < n; i++) b[i] = 1.0/i/i;
//#define DBG
#ifdef  DBG
	for (int i = 0; i < n; i++) {
		double baoli  = 0;
		for (int j = 0; j < i; j++) baoli += q[j]/(i - j)/(i - j);
		printf("ans[i] : %lf\t baoli[i] = %lf\n", ans[i], baoli);
	}
#endif
	mul();
	for (int i = 0; i < n; i++) ans[i] -= c[n - 1 - i].real(); 
	for (int i = 0; i < n; i++) printf("%lf\n", ans[i]);
}
