#include <cstdio>
#include <cstring>
#include <algorithm>
const int M = 8010;
long long m;
int prt;
long long qpow(long long x, int r) {
	if (!x) return 0;
	long long y = 1;
	for(int i = 0; r; i++, x=x*x%m, r>>=1) if (r&1) y=y*x%m;
	return y;
}
int main() {
//	scanf("%d%d%d%d", &n, &m, &x, &s);
	scanf("%lld", &m);
	for (int i = 2; i < m;i++) {
		int x = m - 1;
		bool flag = 1;
		for (int j = 2; j <= x; j++) if (x%j == 0) {
			if (qpow(i, (m-1)/j) == 1) {flag=0;break;}
			for(;x%j==0;x/=j);
		}
		if (flag) {
			prt=i;
			break;
		}
	}
	printf("%d\n", prt);
}
