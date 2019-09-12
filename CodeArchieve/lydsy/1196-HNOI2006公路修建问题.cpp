#include <cstdio>
#include <algorithm>
const int N = 10010, M = 20010;
int n, m, k, p[N];
struct Edge{int u, v, c1, c2;}st[M];
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
bool check(int now) {
	int cc = 0;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i =1; i < m; i++) {
		int x = find(st[i].u), y = find(st[i].v);
		if (x == y) continue;
		if (st[i].c1 <= now) {cc++;p[x] = y;}
	}
	for (int i =1; i < m; i++) {
		int x = find(st[i].u), y = find(st[i].v);
		if (x == y) continue;
		if (st[i].c2 <= now) p[x] = y;
	}
	int x = 0, y = find(1);
	for (int i = 1; i <= n; i++) x += find(i) == y;
	return cc >= k && x == n;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d%d", &n, &k, &m);
	int l = 0, r = 0;
	for (int i = 1; i < m; i++) {
		scanf("%d%d%d%d", &st[i].u, &st[i].v, &st[i].c1, &st[i].c2);
		r = std::max(r, std::max(st[i].c1, st[i].c2));
	}
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid))  r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
