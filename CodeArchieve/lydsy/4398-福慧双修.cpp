#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <ctime>
const int N = 4e4 + 10, E = 2e5 + 10;
int n, m, hed[N], nxt[E], sz, ans = 0x3f3f3f3f, a[N], dis[N], tot;
struct Edge{int u, v, w;}st[E];
void add(int u, int v, int w) {
	st[++sz] = (Edge){u, v, w};
	nxt[sz] = hed[u], hed[u] = sz;
}
bool del[N], inq[N];
std::queue<int> q;
void solve() {
	std::random_shuffle(a + 1, a + 1 + tot);
	memset(del, 0, sizeof del);
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= (tot+1)/2; i++) del[a[i]] = 1;
	q.push(1);
	dis[1] = 0;
	inq[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = 0;
		for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) {
			if ((del[u] && v == 1) || (del[v] && u == 1)) continue;
			if (dis[v] > dis[u] + st[e].w) {
				dis[v] = dis[u] + st[e].w;
				if (!inq[v]) inq[v] = 1, q.push(v);
			}
		}
	}
	for (int i = 1; i <= (tot+1)/2; i++) {
		int u = a[i];
		for (int e = hed[u], v; (v = st[e].v); e = nxt[e]) if (v == 1) 
			ans = std::min(ans,dis[u] + st[e].w);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w1, w2;
		scanf("%d%d%d%d", &u, &v, &w1, &w2);
		add(u, v, w1);
		add(v, u, w2);
	}
	for (int e = hed[1], v; (v = st[e].v); e = nxt[e]) a[++tot] = v;
	int T = 30;
	while (T--) solve();
	printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
}
