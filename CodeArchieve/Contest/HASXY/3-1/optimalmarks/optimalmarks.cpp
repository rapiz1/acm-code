#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define file(x) "optimalmarks." #x
const int N = 511, M = 3010;
int n, m, k, val[N];
long long ans;
std::vector<int> to[N];
std::queue<int> q;
struct DINIC{
	static const int V = N, E = V*V << 2;
	int s, t, hed[V], nxt[E], sz, lv[V];
	struct EDGE{int u, v, c, f;} st[E];
	inline void init() {
		memset(this, 0, sizeof(*this));
		sz = 1;
		s = n + 1, t = n + 2;
	}
	inline void _add(int u, int v, int c) {
		st[++sz] = (EDGE){u, v, c};
		nxt[sz] = hed[u], hed[u] = sz;
	}
	inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
	inline bool bfs() {
		memset(lv, 0, sizeof(lv));
		lv[s] = 1;
		q.push(s);
		while (!q.empty()) {
			int u = q.front();
		 	q.pop();
			for (int e = hed[u], v; v = st[e].v; e = nxt[e]) if (st[e].c > st[e].f && !lv[v])
				lv[v] = lv[u] + 1, q.push(v);
		}
		return lv[t];
	}
	int dfs(int u, int a) {
		if (u == t) return a;
		int flow = 0, f;
		for (int e = hed[u], v; v = st[e].v; e = nxt[e]) 
			if (lv[v] == lv[u] + 1 && st[e].c > st[e].f && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
				flow += f, a -= f;
				st[e].f += f, st[e^1].f -= f;
				if (!a) return flow;
			}
		return flow;
	}
	inline long long calc() {
		long long flow = 0;
		while (bfs()) flow += dfs(s, 1e7);
		return flow;
	}
}sol;
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	memset(val, -1, sizeof(val));
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), to[u].push_back(v), to[v].push_back(u);
	scanf("%d", &k);
	for (int i = 1, x, y; i <= k; i++) scanf("%d%d", &x, &y), val[x] = y;
	for (int i = 0; i < 31; i++) {
		sol.init();
		for (int j = 1; j <= n; j++) {
			int c0 = 0, c1 = 0;
			if (val[j] == -1) {
				for (int k = 0, v; k < (int)to[j].size(); k++) if (val[v = to[j][k]] != -1) {
					if ((val[v]>>i)&1) c1++;
					else c0++;
				}
				else sol.add(j, to[j][k], 1);
				sol.add(sol.s, j, c0);
				sol.add(j, sol.t, c1);
			}
		}
		ans += sol.calc()*(1ll<<i);
	}
	
	long long aa = 0;
	for (int i = 1; i <= n; i++) if (val[i] != -1)
		for (int j = 0; j < to[i].size(); j++) if (val[to[i][j]] != -1) 
			aa += val[i]^val[to[i][j]];
	printf("%lld\n", ans + aa/2);
}
