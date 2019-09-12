#include <cstdio>
#include <vector>
const int N = 2e4 + 10, E = N << 1;
int n, f[N][3], sz, nxt[E], hed[N], ch;
struct EDGE{int u, v, w;}st[E];
void add(int u, int v, int w) {
	st[++sz] = (EDGE){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
void dfs(int u, int fa){
	f[u][0] = 1;
	for (int e = hed[u], v; ( v = st[e].v); e = nxt[e]) if (v != fa) {
		dfs(v, u);
		for (int j = 0; j < 3; j++) ch += f[u][j]*f[v][(6 - j - st[e].w)%3]*2, f[u][j] += f[v][(j - st[e].w + 3)%3];
	}
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	ch = n;
	for (int i = 1, u, v, w; i < n; i++) scanf("%d%d%d", &u, &v, &w), w%=3, add(u, v, w), add(v, u, w);
	dfs(1, 0);
	int mo = n*n, d = gcd(mo, ch);
	printf("%d/%d\n", ch/d, mo/d);
}
