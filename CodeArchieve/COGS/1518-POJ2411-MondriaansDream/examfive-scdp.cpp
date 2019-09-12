#include <cstdio>
#include <cstring>
#define file(x) "examfive." #x
const int N = 12, V = 1 << 11 | 1;
typedef long long ll;
int n, m;
ll f[N][V], fr;
inline int set(int x, int p, int v) {
	if (v) return x | (1 << p - 1);
	else return x & ~(1 << p - 1);
}
inline int get(int x, int p) {return x >>(p - 1)&1;}
void print(int x) {for (int i = 1; i <= m;i++, x>>=1) printf("%d", x&1);}
void dfs(int r, int c, int s0, int s1) {
//	print(s0), putchar('\t'), print(s1), putchar('\n');
	if (c > m) {
		f[r + 1][s1] += fr;
		return;
	}
	if (get(s0, c) && get(s0, c + 1)) dfs(r, c + 2, s0, set(set(s1, c, 1), c + 1, 1));
	if (!get(s0, c)) dfs(r, c + 1, set(s0, c, 1), set(s1, c, 1));
	else dfs(r, c + 1, s0, s1);
}
void init(int c, int s) {
	if (c > m) f[1][s] = 1;
	else {
		if (c + 1 <= m) init(c + 2, set(set(s, c, 1), c + 1, 1));
		init(c + 1, s);
	}
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	while (scanf("%d%d", &n, &m)){
		if (n == 0 && m == 0) break;
		memset(f, 0, sizeof(f));
		init(1, 0);
		for (int i = 1; i < n; i++) 
			for (int j = 0; j < 1 << m; j++)
				if (f[i][j]) fr = f[i][j], dfs(i, 1, j, 0);
		printf("%lld\n", f[n][(1 << m) - 1]);
	}
}
