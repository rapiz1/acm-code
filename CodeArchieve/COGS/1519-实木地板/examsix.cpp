#include <cstdio>
#include <cassert>
#define file(x) "examsix." #x
const int N = 1 << 10;
typedef long long ll;
int n, m;
ll f[10][N];
inline int set(int x, int p, int v) {
	if (v) return x | (1 << p - 1);
	else return x & ~(1 << p - 1);
}
inline int get(int x, int p){return x >> (p - 1)&1;}
void init(int c, int s) {
	if (c > m) f[1][s] = 1;
	else {
		if (c + 1 <= m) init(c + 2, set(set(s, c, 1), c + 1, 1));
		init(c + 1, s);
	}
}
ll fr;
void dfs(int r, int c, int s0, int s1) {
	if (c - 2 >= 1 && !get(s0, c - 2)) return;
	if (c > m) {
		if (s0 == (1 << m) - 1) f[r + 1][s1] += fr;
	}
	else {
		if (c + 1 <= m) {
			if (!get(s0, c))  dfs(r, c + 2, set(s0, c, 1), set(set(s1, c, 1), c + 1, 1));
			if (get(s0, c) && !get(s0, c + 1)) dfs(r, c + 2, set(s0, c + 1, 1), set(set(s1, c, 1), c + 1, 1));
			if (get(s0, c)) dfs(r, c + 2, s0, set(set(s1, c, 1), c + 1, 1));
			if (!get(s0, c) && !get(s0, c + 1)) dfs(r, c + 1, set(set(s0, c, 1), c + 1, 1), set(s1, c, 1));
		}
		if (c - 1 >= 1 && !get(s0 ,c) && !get(s0, c - 1)) dfs(r, c + 1, set(set(s0, c, 1), c - 1, 1), set(s1, c, 1));
		if (!get(s0, c)) dfs(r, c + 1, set(s0, c, 1), set(s1, c, 1));
		dfs(r, c + 1, s0, s1);
	}
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	init(1, 0);
	for (int i = 1; i < n; i++)
		for (int s = 0; s < 1 << m; s++) if (fr = f[i][s])
		 	dfs(i, 1, s, 0);
	printf("%lld\n", f[n][(1 << m) - 1]);
}

