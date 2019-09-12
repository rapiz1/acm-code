#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
const int N = 110;
int n;
struct dec{
	static const int BASE = 1e4;
	int n, a[30];
	dec(int s = 0) {
		memset(this, 0, sizeof *this);
		for (;s;s/=BASE) a[++n] = s%BASE;
	}
	dec operator*(int b)const {
		dec ret(0);
		ret.n = n;
		int g = 0;
		for (int i = 1; i <= n; i++) {
			g += a[i]*b;
			ret.a[i] = g%BASE;
			g/=BASE;
		}
		for (;g;g/=BASE) ret.a[++ret.n] = g%BASE;
		return ret;
	}
	dec operator-(const dec& b)const {
		dec ret(0);
		ret.n = n;
		int g = 0;
		for (int i = 1; i <= n; i++) {
			ret.a[i] = a[i] - b.a[i] - g;
			if (ret.a[i] < 0) ret.a[i] += BASE, g = 1;
			else g = 0;
		}
		return ret;
	}
	dec operator+(const dec& b)const {
		dec ret(0);
		ret.n = std::max(n, b.n);
		int g = 0;
		for (int i = 1; i <= ret.n; i++) {
			g += a[i] + b.a[i];
			ret.a[i] = g%BASE;
			g/=BASE;
		}
		for(;g;g/=BASE) ret.a[++ret.n] = g%BASE;
		return ret;
	}
	void print() {
		printf("%d", a[n]);
		for (int i = n - 1; i; i--) printf("%04d", a[i]);
	}
}f[N];
int main() {
	f[1] = 1, f[2] = 5;
	for (int i = 3; i <= 100; i++) f[i] = f[i - 1]*3 - f[i - 2] + 2;
	scanf("%d", &n);
	f[n].print();
}
