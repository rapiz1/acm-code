#include <cstdio>
#include <algorithm>
#define file(x) "cannon." #x
const int N = 61;
int n, m, f[101][N][N], num, s[N], ans, rm[101];
char buf[11];
inline int set(int s, int p, int v) {
	if (v) return s|(1 << p - 1);
	else return s & ~(1 << p - 1);
}
inline int get(int s, int p) {return (s<<p - 1)&1;}
void dfs(int c, int ss) {
	if (c > m) s[++num] = ss;
	else dfs(c + 1, ss), dfs(c + 3, set(ss, c, 1));
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", buf + 1);
		for (int j = 1; j <= m; j++) rm[i] = set(rm[i], j, buf[j] == 'H');
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		for (int s1 = 1; s1 <= num; s1++) if (!(s[s1]&rm[i]))
			for (int s2 = 1; s2 <= num; s2++) if (!(s[s2]&rm[i - 1]) && !(s[s1]&s[s2]))
				for (int s3 = 1; s3 <= num; s3++) if (!(s[s2]&s[s3]) && !(s[s1]&s[s3])) {
					if (i > 2 && (s[s3]&rm[i - 2])) continue; 
					int cc = __builtin_popcount(s[s1]);
					f[i][s1][s2] = std::max(f[i - 1][s2][s3] + cc, f[i][s1][s2]);
					ans = std::max(ans, f[i][s1][s2]);
				}
	}
	printf("%d\n", ans);
}
