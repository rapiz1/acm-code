#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define fore for (int e = hed[u], v; (v = st[e].v) ; e = nxt[e])
const int V = 3e4 + 10, E = 60010 << 1;
int n, m, k, q[V], h, t, dis[V], ecn[V], sz[V], pre[V], f[V][2], len, way;
bool inq[V], vis[V];
struct Graph {
	int hed[V], nxt[E], esz;
	struct EDGE{int u, v, w;
		bool operator<(const EDGE& b)const {return v < b.v;}
	}st[E];
	inline void add(int u, int v, int w) {
		st[++esz] = (EDGE){u, v, w};
		nxt[esz] = hed[u], hed[u] = esz;
	}
	void dfs(int u, int fa, Graph& dest) {
		inq[u] = 1;
		std::vector<EDGE> to;
		fore if (!inq[v] && dis[v] == dis[u] + st[e].w) to.push_back(st[e]);
		std::sort(to.begin(), to.end());
		for (int i = 0; i < (int)to.size(); i++) if (!inq[to[i].v]) {
			dest.add(to[i].v, to[i].u, to[i].w), dest.add(to[i].u, to[i].v, to[i].w);
			dfs(to[i].v, to[i].u, dest);
		}
	}
	void build(Graph& dest) {
		memset(dis, 0x3f, sizeof dis);
		typedef std::pair<int, int> pa;
		std::priority_queue<pa, std::vector<pa>, std::greater<pa> > q;
		dis[1] = 0;
		q.push(std::make_pair(0, 1));
		while (!q.empty()) {
			pa f = q.top();
			q.pop();
			int u = f.second;
			if (inq[u]) continue;
			inq[u] = 1;
			fore if (dis[v] > dis[u] + st[e].w)
				q.push(std::make_pair(dis[v] = dis[u] + st[e].w, v));
		}
		memset(inq, 0, sizeof inq);
		dfs(1, 0, dest);
	}
	void solve(int u) {
		h = t = 0;
		pre[q[t++] = u] = 0;
		while (h < t) {
			int u = q[h++];
			sz[u] = 1;
			fore if (!vis[u] && v != pre[u]) pre[q[t++] = v] = u;
		}
		for (int i = t - 1; ~i; i--) sz[pre[q[i]]] += sz[q[i]];
		int size = sz[u];
		for (int flag = 1; flag; ) {
			flag = 0;
			fore if (!vis[v] && v != pre[u] && sz[v] > size/2) {
				flag = 1;
				u = v;
				break;
			}
		}
		vis[u] = 1;
		static int msz, modi[V];
		msz = 0;
		modi[msz++] = 0;
		f[0][1] = 1;
		fore if (!vis[v]) {
			pre[v] = u;
			dis[v] = st[e].w, ecn[v] = 1;
			h = t = 0;
			q[t++] = v;
			while (h < t) {
				int u = q[h++];
				if (ecn[u] + 1 <= k) {
					int l = dis[u] + f[k - ecn[u] - 1][0]; 
					if (l > len) len = l, way = f[k - ecn[u] - 1][1];
					else if (l == len) way += f[k - ecn[u] - 1][1];
				} 
				fore if (!vis[v] && pre[u] != v) {
					pre[q[t++] = v] = u;
					dis[v] = dis[u] + st[e].w;
					ecn[v] = ecn[u] + 1;
				}
			}
			for (int i = 0; i < t; i++) {
				if (f[ecn[q[i]]][0] < dis[q[i]]) f[ecn[q[i]]][0] = dis[q[i]], f[ecn[q[i]]][1] = 1;
				else if (f[ecn[q[i]]][0] == dis[q[i]]) f[ecn[q[i]]][1]++;
				modi[msz++] = ecn[q[i]];
			}
		}
		for (int i = 0; i < msz; i++) f[modi[i]][0] = f[modi[i]][1] = 0;
		fore if (!vis[v]) solve(v);
	}
}g1, g2;
int main() {
//	freopen("input", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v, w; i <= m; i++) scanf("%d%d%d", &u, &v, &w), g1.add(u, v, w), g1.add(v, u, w);
	g1.build(g2);
	g2.solve(1);
	printf("%d %d\n", len, way);
}
