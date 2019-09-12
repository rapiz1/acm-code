#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstirng>
#include <complex>
const int N = 1 << 19, L = 1e5 + 10;
const double PI = acos(-1);
typedef std::complex<double> num;
int n, nn, f[L];
char s[L];
num a[N], e[N][2];
void fft(int n, num* x) {
	for (int i = 0, j = 0; i < n; i++) {
		if (i > j )std::swap(x[i], x[j]);
		for (int l = n>>1;(j^=l) < l; l>>=1);
	}
	for (int i = 2; i <= n; i += 2) 
		for (int m = i>>1, j = 0; j < n; j += i)
			for (int k = 0; k < m; k++) {
				num z = a[j + k + m]*e[n/i*j][rev];
				a[j + k + m] = a[j + k] - z;
				a[j + k] -= z;
			}
	if (rev) for (int i = 0; i < n; i++) a[i] /= n;
}
int main() {
	scanf("%s", s);
	n = strlen(s);
	for (nn = 1; nn < n*2; nn<<=1);
	for (int i = 0; i < nn; i++) e[i][0] = num(cos(2*PI/nn*i), sin(2*PI/nn*i)), e[i][1] = std::conj(e[i][0]);
	for (int i = 0; i < n; i++) a[i] = s[i] == 'a';
	fft(nn, a);
	for (int i = 0; i < nn; i++) a[i]*=a[i];
	fft(nn, a, 1);
	for (int i = 0; i < nn; i++) f[i] += int(a[i].real() + 0.5) + 1 >> 1;
	for (int i = 0; i < n; i++) a[i] = s[i] == 'b';
	fft(nn, a);
	for (int i = 0; i < nn; i++) a[i]*=a[i];
	fft(nn, a, 1);
	for (int i = 0; i < nn; i++) f[i] += int(a[i].real() + 0.5) + 1 >> 1;
	
}
