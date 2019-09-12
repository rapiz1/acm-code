#include <cstdio>
#include <cassert>
const int MOD = 10086;
int r[32], n, q, nest[32], cnt;
int qpow(int x, int r) {
	int ret = 1;
	x %= MOD;
	while (r) {
		if (r&1) ret = ret*x%MOD;
		r>>=1, x = x*x%MOD;
	}
	return ret;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		for (int j = 31; ~j; j--) if (x>>j&1)
			if(r[j]) x ^= r[j];
			else {r[j] = x;break;}
	}
	for (int i = 0; i <= 31; i++)
		for (int j = i - 1; ~j; j--) 
			if (r[i]>>j&1) r[i] ^= r[j];
	scanf("%d", &q);
	for (int i = 0; i <= 31; i++) if (r[i]) nest[cnt++] = i;
	int ss = 0;
	for (int i = 0; i < cnt; i++) if (q>>nest[i]&1)
		ss += 1 << i;
	printf("%d\n", (ss%MOD*qpow(2, n - cnt)%MOD + 1)%MOD);
}
