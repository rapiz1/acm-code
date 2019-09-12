#include <cstdio>
#include <algorithm>
#define file(x) "examtwo." #x
typedef long long ll;
int c[300], cc[300], num, n, m, k;
ll f[80][300][25];
void dfs(int p, int cnt, int s) {
	if (p > m) {
		c[++num] = s;
		cc[num] = cnt;
		return;
	}
	if (cnt > k) return;
	if (p > 1 && s&(1 << p - 2));
	else dfs(p + 1, cnt + 1, s|(1 << p - 1));
	dfs(p + 1, cnt, s);
}
ll comb(int y, int x) {
	ll r = 1;
	for (int k = 1; k <= x; k++) r *= y - k + 1;
	for (int i = 1; i <= x; i++) r /= i;
	return r;
}
ll gcd(ll x, ll y) {return y ? gcd(y, x%y) : x;}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	if (m > n) std::swap(n, m);
	dfs(1, 0, 0);
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1, s; j <= num; j++) {
			s = c[j];
			for (int h = cc[j]; h <= k; h++) {
				for (int g = 1, ss; g <= num; g++) if (!((ss = c[g])&s)) f[i][s][h] += f[i-1][ss][h - cc[j]];
			}
		}
	}
	ll par = comb(n*m, k), chi = 0;
	for (int i = 0; i < 300; i++) chi += f[n][i][k];
	ll d = gcd(par, chi);
	printf("%lld/%lld\n", par/d, chi/d);
}
