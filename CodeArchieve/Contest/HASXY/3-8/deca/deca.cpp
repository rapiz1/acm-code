#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define file(x) "deca." #x
const int N = 22; 
int n, m, w[N][N], f[N][1 << 20|1], th[1 << 20|1];
struct SC{int p, a;};
std::vector<SC> st[N];
inline int lowbit(int x) {return x&-x;}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	memset(f, 0xc0, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int k, p, a;
		scanf("%d%d%d", &k, &p, &a);
		st[k].push_back((SC){p, a});
	}
	for (int i = 0; i < 20; i++) th[1 << i] = i + 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &w[i][j]);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) for (int s = 0; s < 1 << n; s++)
		for (int x = s; x; x -= lowbit(x)) {
			int p = th[lowbit(x)], nn = f[i - 1][s&~lowbit(x)] + w[p][i];
			if (nn < 0) continue;
			for (int j = 0; j < st[i].size(); j++) if (nn >= st[i][j].p) nn += st[i][j].a;
			f[i][s] = std::max(f[i][s], nn);
		}
	printf("%d\n", f[n][(1 << n) - 1]);
}
