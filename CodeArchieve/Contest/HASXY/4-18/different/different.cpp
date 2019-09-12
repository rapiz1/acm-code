#include <cstdio>
#include <algorithm>
const int N = 210, E = 5010;
int n, m, p[N];
struct Edge{int u, v, w;
	bool operator<(const Edge& b)const {return w < b.w;}
}st[E];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
void solve() {
	int ans = 1e9;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &st[i].u, &st[i].v, &st[i].w);
	std::sort(st + 1, st + 1 + m);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) p[j] = j;
		int na = st[i].w;
		for (int j = i; j <= m; j++) {
			int x = find(st[j].u), y = find(st[j].v);
			if (x != y) na = std::max(na, st[j].w);
			p[x] = y;
		}
		int cc = 0;
		for (int i = 1; i <= n; i++) cc += p[i] == i;
		if (cc == 1) ans = std::min(ans, na - st[i].w);
	}
	printf("%d\n", ans);
}
int main() {
	freopen("different.in", "r", stdin);
	freopen("different.out", "w", stdout);
	int c; scanf("%d", &c);
	while (c--) solve();
}
