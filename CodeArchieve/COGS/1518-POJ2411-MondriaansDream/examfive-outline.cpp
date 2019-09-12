#include <cstdio>
#include <cstring>
#define file(x) "examfive." #x
const int V = 1 << 11 | 1;
typedef long long ll;
int n, m, cur, mask;
ll f[2][V], fr;
inline int set(int x, int p, int v) {
	if (v) return x | (1 << p - 1);
	else return x & ~(1 << p - 1);
}
inline int get(int x, int p) {return x >>(p - 1)&1;}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	while (scanf("%d%d", &n, &m)){
		if (n == 0 && m == 0) break;
		mask = (1 << m) - 1;
		memset(f, 0, sizeof(f));
		cur = 0;
		f[0][mask] = 1;
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) {
				cur ^= 1;
				memset(f[cur], 0, sizeof(f[0]));
				for (int s = 0; s < 1 << m; s++) if (fr = f[cur^1][s]) {
					int ss = (s<<1)&mask;
					if (get(s, m)) f[cur][ss] += fr;
					else if (i != 1) f[cur][ss|1] += fr;
					if (j != 1 && get(s, m) && get(s, 1) == 0) f[cur][ss|3] += fr;
				}
			}
		printf("%lld\n", f[cur][mask]);
	}
}
