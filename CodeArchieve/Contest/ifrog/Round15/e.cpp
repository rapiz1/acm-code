#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
const int N = 1e5 + 10, E = 1e6 + 10;
typedef long long ll;
int n, m, sz, s, t, p[N];
struct Edge{int u, v, w;}st[E];
void add(int u, int v, int w) {
	st[++sz] = (Edge){u, v, w};
}
int find(int i) {return i == p[i] ? i : p[i] = find(p[i]);}
bool check(int up) {
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= sz; i++) if (st[i].w <= up) {
		p[find(st[i].u)] = find(st[i].v);
	}
	return find(s) == find(t);
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, w; i <= m; i++) scanf("%d%d%d", &u, &v, &w), add(u, v, w);
	scanf("%d%d", &s, &t);
	int l = 0, r = 1e9 + 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l > 1e9 ? -1: l);
}
