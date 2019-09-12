#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long ll;
const int M = 8010, K = 3, MOD = 1004535809, L = 1e5;
int n, m, s, x, prt, idx[M], nn;
inline int add(int x, int y, int mod=MOD) {
	return x + y > mod ? x + y - mod : x + y;
}
inline int sub(int x, int y, int mod=MOD) {
	return x > y ? x - y : x - y + mod;
}
int p[L], q[L];
int qpow(int x, int r, int mod) {
	x%=mod;
	if (!x) return 0;
	int y = 1;
	for(; r; x=(ll)x*x%mod, r>>=1) if (r&1) y=(ll)y*x%mod;
	return y;
}
void fft(int* x, int n, bool rev) {
	for (int i = 0, j = 0; i < n; i++) {
		if (i < j) std::swap(x[i], x[j]);
		for(int l = n>>1; (j^=l) < l; l>>=1);
	}
	for (int i = 2; i <= n; i<<=1) {
		int m = i >> 1, wn = qpow(K, rev  ? MOD - 1 - (MOD-1)/i : (MOD-1)/i, MOD);
		for (int j = 0; j < n; j+=i) 
			for (int k = 0, w = 1; k < m; k++) {
				int z = (ll)x[j + k + m]*w%MOD;
				x[j + k + m] = sub(x[j + k], z);
				x[j + k] = add(x[j + k], z);
				w=(ll)w*wn%MOD;
			}
	}
	if (rev) for (int i = 0, inv = qpow(n, MOD - 2, MOD); i < n; i++) x[i] = (ll)x[i]*inv%MOD;
}
void mul(int p[L], int q[L]) {
	fft(p, nn, 0);
	if (q != p) fft(q, nn, 0);
	for (int i = 0; i < nn; i++) p[i] = (ll)p[i]*q[i]%MOD;
	fft(p, nn, 1);
	if  (q != p) fft(q, nn, 1);
	for (int i = m-1; i < nn; i++) p[i-m+1] = add(p[i-m+1], p[i]), p[i]=0;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &x, &s);
	for (int i = 2; i < m;i++) {
		int x = m - 1;
		bool flag = 1;
		for (int j = 2; j <= x; j++) if (x%j == 0) {
			if (qpow(i, (m-1)/j, m) == 1) {flag=0;break;}
			for(;x%j==0;x/=j);
		}
		if (flag) {
			prt=i;
			break;
		}
	}
	for (int i = 0, x = 1; i < m-1; i++, x=(ll)x*prt%m) idx[x]=i;
	for (int i = 1; i <= s; i++) {
		int a;
		scanf("%d", &a);
		if (a) p[idx[a]]++;
	}
	for(nn=1;nn<2*m;nn<<=1);
	q[0]=1;
	for(;n;n>>=1, mul(p, p)) if (n&1) mul(q, p);
	printf("%d\n", q[idx[x]]);
}
