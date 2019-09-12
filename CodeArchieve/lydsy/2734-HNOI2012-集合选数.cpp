#include <cstdio>
#include <cstring>
typedef long long ll;
const int M = 1e9 + 1;
int u;
int f[2][int(1<<11)], ans = 1;
bool vis[int(1e5) + 10];
inline void calc(int d) {
	memset(f, 0, sizeof(f));
	int i, j, pj, x;
	f[0][0] = 1;
	for (i = 1, pj = 0; d <= u; i++, d*=2, pj = j) {
		for (j = 1, x = d; x <= u; j++, x*=3) vis[x] = 1;
		j--;
		for (int s = 0; s < 1 << j; s++)
			if ((s&(s>>1)) == 0)
			for (int ss = 0; ss < 1 << pj; ss++)
				if ((s&ss) == 0) f[i&1][s] = (f[i&1][s] + f[(i&1)^1][ss])%M;
		for (int s = 0; s < 1 << pj; s++) f[(i&1)^1][s] = 0;
	}
	i--;
	int c = 0;
	for (int s = 0; s < 1 << pj; s++) c = (c + f[i&1][s])%M;
	ans = 1ll*ans*c%M;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &u);
	for (int i = 1; i <= u; i++) if (!vis[i]) calc(i);
	printf("%d", ans);
}
