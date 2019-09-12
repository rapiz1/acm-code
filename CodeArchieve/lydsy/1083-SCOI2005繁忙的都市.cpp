#include <cstdio>
#include <algorithm>
const int N = 310;
int n, m, p[N], mx, cn;
struct Edge{int u, v, w;}st[int(1e5)];
bool cmp(const Edge& a, const Edge& b) {return a.w < b.w;}
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &st[i].u, &st[i].v, &st[i].w);
	std::sort(st + 1, st + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		if (find(st[i].u) != find(st[i].v)) {
			p[find(st[i].u)] = find(st[i].v);
			mx = std::max(mx, st[i].w);
			cn++;
		}
	}
	printf("%d %d\n", cn, mx);
}
