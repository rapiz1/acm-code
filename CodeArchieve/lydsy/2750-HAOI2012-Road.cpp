#include <cstdio>
#include <queue>
#include <cstring>
#define fore(u) for (int e = hed[u], v; (v = st[e].v); e = nxt[e])
typedef long long ll;
const int V = 1510, E = 5011, M = 1000000007;
int n, m,  ans[E], dis[V], beg[V], end[V], S;
std::queue<int> q;
bool inq[V];
struct Graph {
	int hed[V], nxt[E], sz;
	struct Edge{int u, v, w;}st[E];
	void add(int u, int v, int w) {
		st[++sz] = (Edge){u, v, w};
		nxt[sz] = hed[u], hed[u] = sz;
	}
	void spfa(int u) {
		memset(dis, 0x3f, sizeof dis);
		q.push(u);
		dis[u] = 0;
		inq[u] = 1;
		while (!q.empty()) {
			int u = q.front();q.pop();
			inq[u] = 0;
			fore(u) 	if (dis[v] > dis[u] + st[e].w) {
				dis[v] = dis[u] + st[e].w;
				if (!inq[v]) inq[v] = 1, q.push(v);
			}
		}
	}
	void build();
	bool vis[V];
	int bb(int u) {
		if (vis[u]) return beg[u];
		vis[u] = 1;
		beg[u] = 1;
		fore(u) beg[u] += bb(v);
		return beg[u];
	}
	int ee(int u) {
		if (vis[u]) return end[u];
		vis[u] = 1;
		if (u == S) end[u] = 1;
		fore(u) end[u] += ee(v);
		return end[u];
	}
	inline void clear() {
		for(;sz;sz--)st[sz]=(Edge){0};
		memset(hed, 0, sizeof hed);
		memset(vis, 0, sizeof vis);
	}
	void calc();
}g, g1, g2;
void Graph::build() {
	for (int e = 1; e <= sz; e++) 
		if (dis[st[e].v] == dis[st[e].u] + st[e].w)
		 	g1.add(st[e].u, st[e].v, e), g2.add(st[e].v, st[e].u, e);
}
inline void Graph::calc() {
	for (int i = 1; i <= n; i++) {
		spfa(S = i);
		g1.clear(), g2.clear();
		build();
		memset(beg, 0, sizeof beg), memset(end, 0, sizeof end);
		for (int j = 1; j <= n; j++) g1.bb(j), g2.ee(j);
		for (int j = 1; j <= sz; j++) 
			if (dis[st[j].v] == dis[st[j].u] + st[j].w)
			 	ans[j] = (ans[j] + (ll)end[st[j].u]*beg[st[j].v])%M;
	}
}
int main() {
//	freopen("roadsw.in", "r", stdin);
//	freopen("roadsw.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1,u,v,w; i <=m; i++) scanf("%d%d%d", &u, &v, &w), g.add(u,v,w);
	g.calc();
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
