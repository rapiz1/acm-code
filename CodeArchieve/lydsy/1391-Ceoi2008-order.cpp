#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
const int V = 2410, E = (1210*1210 + V)*2;
int n, m, s, t, hed[V], nxt[E], sz = 1, now[V], ans, lv[V];
inline int zip(int i, int j) {return (i - 1)*m + j;}
inline bool check(int i, int j) {return 1 <= i && i <= n && 1 <= j && j <= m;}
struct EDGE{int u, v, c, f;}st[E];
inline void _add(int u, int v, int c) {
    st[++sz] = (EDGE){u,v,c,0};
    nxt[sz] = hed[u], hed[u] = sz; 
}
inline void add(int u, int v, int c) {_add(u, v, c), _add(v, u, 0);}
inline void biadd(int u, int v, int c) {_add(u, v, c), _add(v, u, c);}
std::queue<int> q;
inline bool bfs() {
    memset(lv, 0, sizeof(lv));
    lv[s] = 1, q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int e = hed[u],v;v=st[e].v; e=nxt[e]) if (st[e].c > st[e].f && !lv[v]) {
            lv[v] = lv[u] + 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= t; i++) now[i] = hed[i];
    return lv[t];
}
int dfs(int u, int a) {
    if (u == t) return a;
    int flow = 0, f;
    for (int& e = now[u]; e;e = nxt[e]) if (st[e].c > st[e].f) {
        int v = st[e].v;
        if (lv[v] == lv[u] + 1 && (f = dfs(v, std::min(a, st[e].c - st[e].f)))) {
            flow += f, a-= f;
            st[e].f += f, st[e^1].f -= f;
            if (!a) break;
        }
    }
    return flow;
}
int main() {
//  freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	s = n + m + 1, t = s + 1;
	for (int i = 1; i <= n; i++) {
		int w, k;scanf("%d%d", &w, &k);
		ans += w;
		add(s, i, w);
		for (int j = 1, x, y; j <= k; j++) scanf("%d%d", &x, &y), add(i, n + x, y);
	}
	for (int i = 1, x; i <= m; i++) scanf("%d", &x), add(i + n, t, x);
	while (bfs()) ans -= dfs(s, 1e9);	
	printf("%d\n", ans);
}
