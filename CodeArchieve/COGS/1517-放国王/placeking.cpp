#include <cstdio>
#define file(x) "placeking." #x
const int S = 2048;
typedef long long ll;
int n, k, num, ws[S], wc[S];
ll f[11][100][S];
inline int get (int s, int p) {return s >> (p - 1)&1;}
inline int set(int s, int p, int v) {
	if (v) return s | (1 << p - 1);
	else return s & ~(1 << p - 1);
}
void dfs(int p, int c, int s) {
	if (p > n) {
		ws[++num] = s;
		wc[num] = c;
	}
	else {
		dfs(p + 1, c, s);
		dfs(p + 2, c + 1, set(s, p, 1));
	}
}
inline bool check(int f, int s) {
	for (int i = 1; i <= n; i++) if (get(f, i)) {
		if (i > 1 && get(s, i - 1)) return 0;
		if (i + 1 <= n && get(s, i + 1)) return 0;
		if (get(s, i)) return 0;
	} 
	return 1;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d",&n, &k);
	dfs(1, 0, 0);
	f[0][0][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
		for (int s = 1; s <= num; s++)
			for (int ss = 1; ss <= num; ss++)
				if (check(ws[s], ws[ss]) && wc[ss] <= j) 
					f[i][j][ss] += f[i - 1][j - wc[ss]][s];
	ll ans = 0;
	for (int s = 1; s <= num; s++) ans += f[n][k][s];
	printf("%lld", ans);
}
