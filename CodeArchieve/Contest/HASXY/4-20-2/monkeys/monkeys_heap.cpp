#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define fa (o>>1)
const int C = 25, N = 2e6 + 1, INF = 2e9;
int n, m, k, x[C], y[C], st[N], sz, pos[C], dep[N];
inline int extend(int i) {
	if (pos[i] + 1 > sz) return INF;
//	long long r = (long long)st[pos[i] + 1]*x[i];
	for (;pos[i] + 1 <= sz && st[pos[i] + 1]%(x[i] - 1); pos[i]++);
	return pos[i] + 1 <= sz ? st[pos[i] + 1]/(x[i] - 1)*x[i] + y[i] : INF;
}
int main() {
	freopen("monkeys.in", "r", stdin);
	freopen("monkeys.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i= 1; i <= m; i++) scanf("%d%d", x + i, y + i);
 	st[++sz] = 0;
	scanf("%d", &k);
	k++;
	for (; sz < k;) {
		int mn = 2e9, mp;
		for (int i = 1; i <= m; i++) {
			int x;
			if ((x = extend(i)) < mn) {
				mp = i;
				mn = x;
			}
		}
		if (mn == 2e9) break;
		else {
			if (st[sz] == mn) dep[sz] = std::min(dep[sz], dep[pos[mp] + 1] + 1);
			else if (dep[pos[mp] + 1] + 1 <= n) st[++sz] = mn, dep[sz] = dep[pos[mp] + 1] + 1;
			pos[mp]++;
		}
	}
	printf("%d\n", sz == k ? st[sz]: -1);
}
