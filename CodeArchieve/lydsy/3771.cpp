#include <cstdio>
#include <cmath>
#include <complex>
const double PI = acos(-1);
typedef std::complex<double> num;
const int W = 4e5;
typedef long long ll;
int n, mx;
num p[W], q[W], w[W][2];
ll a[W], b[W], c[W];
void fft(num*p, int n, bool rev) {
	for(int i = 0, j = 0; i != n; i++) {
		if (i < j) std::swap(p[i], p[j]);
		for (int l = n >> 1; (j^=l) < l; l>>=1); 
	}
	for (int i = 2; i <= n; i<<=1) {
		int m = i >> 1;
		for (int j = 0; j < n; j += i) {
			for (int k = 0; k < m; k++) {
				num z = p[j + k + m]*w[n/i*k][rev];
				p[j + k + m] = p[j + k] - z;
				p[j + k] += z;
			}
		}
	}
	if (rev) for (int i = 0; i < n; i++) p[i]/=n;
}
int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), a[x]++, mx =std::max(mx, x);
	mx++;
	for (int i = 0; i < mx; i++) b[3*i] += 2*a[i], p[i].real(a[i]), p[i].imag(0);
	int n = 1;
	while (n < mx*3) n<<=1;
	for (int i = 0; i < n; i++) {
		w[i][0] = num(cos(2*PI*i/n), sin(2*PI*i/n));
		w[i][1] = std::conj(w[i][0]);
	}
	fft(p, n, 0);
	for (int i = 0; i < n; i++) p[i] = p[i]*p[i]*p[i];
	fft(p, n, 1);
	for (int i = 0; i < n; i++) b[i] += p[i].real() + 0.5;
	for (int i = 0; i < n; i++) q[2*i].real(a[i]), p[i].real(a[i]), p[i].imag(0);
	fft(p, n, 0), fft(q, n, 0);
	for (int i = 0; i < n; i++) p[i]*=q[i];
	fft(p, n, 1);
	for (int i = 0; i < n; i++) {
		long long x = p[i].real() + 0.5;
		b[i] = (b[i] - 3*x)/6;
	}
	for (int i = 0; i < n; i++) p[i].real(a[i]), p[i].imag(0);
	fft(p, n, 0);
	for (int i = 0; i < n; i++) p[i]*=p[i];
	fft(p, n, 1);
	for (int i = 0; i < n; i++) c[i] += p[i].real() + 0.5, c[2*i] -= a[i];
	for (int i = 0; i < n; i++) c[i]/=2;
	for (int i = 0; i < n; i++) if (a[i] + b[i] + c[i]) printf("%d %lld\n", i, a[i]+b[i]+c[i]);
}
