#include <cstdio>
#include <cstring>
const int N = 18, MOD = 1000000007;
int n, k, a[N], f[2][1 << N], gd[N][N], st[1 << N], sz;
bool vis[1 << N];
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	int tot = 1 << n, ans = 0;
	f[0][0] = 1;
	for (int i = 1, t = 0; i <= n; i++) {
		t^=1;
		memset(f[t], 0, sizeof f[0]);
		/*
		for (int s = 1; s < tot; s++) {
			for (int l = 0; l < n; l++) if (s>>l&1) {
				int ss = s, d = 0;
				for (int r = l; r < n; r++) if (s>>r&1) {
					d = gcd(d, a[r]);
					ss &= ~(1<<r);
					if (d >= k) {
						(f[t][s] += f[t^1][ss])%=MOD;
						//if (f[i][s] > MOD) f[i][s] -= MOD;
//						f[i][s] = f[i][s] + f[i - 1][ss] < MOD ? f[i][s] + f[i - 1][ss] : f[i][s] + f[i - 1][ss] - MOD;
					}
					else break;
				}
			}
			}
			*/
			for (int s = 0; s < tot; s++) if (f[t^1][s]) {
				while (sz) vis[st[sz--]] = 0;
				for (int l = 0; l < n; l++) {
					int ss = s, d = 0;
					for (int r = l; r < n; r++) {
						if (s>>r&1) ;
						else {
							d = gcd(d, a[r]);
						 	ss |= 1<<r;
							if (d >= k) if (!vis[ss]) vis[ss] = 1, st[++sz] = ss, (f[t][ss] += f[t^1][s])%=MOD;else;
							else break;
							//if (f[i][s] > MOD) f[i][s] -= MOD;
	//						f[i][s] = f[i][s] + f[i - 1][ss] < MOD ? f[i][s] + f[i - 1][ss] : f[i][s] + f[i - 1][ss] - MOD;
						}
					}
				}
			}
		(ans += (long long)f[t][tot - 1]*i%MOD)%=MOD;
	}
	printf("%d\n", ans);
}
