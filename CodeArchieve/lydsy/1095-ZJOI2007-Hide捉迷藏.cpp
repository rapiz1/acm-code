#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
const int V = 1e5 + 10, K = 20;
int n, m, q[V], h, t, pre[V], sz[V], fa[V], anc[V][K],  dep[V], nc;
bool vis[V], off[V];
std::vector<int> to[V];//, ch[V];
struct Heap {
	typedef std::priority_queue<int> heap;
	heap hp, del;
	inline void clear() {
		while (!hp.empty() && !del.empty()) {
			if (hp.top() == del.top()) hp.pop(), del.pop();
			else break;
		}
	}
	inline int top() {
		int ret = -1;
		clear();
		if (!hp.empty()) ret = hp.top();
		return ret;
	}
	inline void pop() {
		clear();
		if (!hp.empty()) hp.pop();
	}
	inline void change(int v, bool rm) {(rm ? del : hp).push(v);}
	inline int mt() {
		int x = top();
		if (x == -1) return -1;
		pop();
		int y = top();
		change(x, 0);
		if (y == -1) return 0;
		return x + y;
	}
}hp[V], hp2[V], gl;
/*
namespace Splay {
	const int N = 2e6;
	int sz[N], top, ch[N][2], fa[N], st[N], bl[N];
	void up(int o) {sz[o] = sz[ch[o][0]] + sz[ch[o][1]] + 1;}
	inline int gd(int o) {return ch[fa[o]][1] == o;}
	inline void lk(int x, int y, int d) {
		if (x) fa[x] = y;
		if (y) ch[y][d] = x;
	}
	inline void rot(int o) {
		int d = gd(o), x = fa[o];
		lk(o, fa[x], gd(x));
		lk(ch[o][d^1], x, d);
		lk(x, o, d^1);
		up(x), up(o);
		if (bl[x]) rt[bl[x]] = o, bl[o] = bl[x], bl[x] = 0;
	}
	void splay(int o) {
		for (;fa[o]; rot(o)) 
			if (fa[fa[o]]) rot(gd(o) == gd(fa[o]) ? fa[o]: o);
	}
	int kth(int o, int k) {
		while (k) {
			if (k <= sz[ch[o][0]]) o = ch[o][0];
			else if (k == sz[ch[o][0]] + 1) return o;
			else k -= sz[ch[o][0]] + 1, o = ch[o][1];
		}
		return o;
	}
	void insert(int o, int v) {
		for (st[++top] = v; ch[o][v >= st[o]]; o = ch[o][v >= st[o]]);
		lk(top, o, v >= st[o]);
		splay(top);
	}
	void remove(int o, int v) {
		for (; st[o] != v; o = ch[o][v > st[o]]);
		splay(o);
		if (ch[o][1]) {
			int x = ch[o][1];
			fa[x] = 0;
			splay(kth(x, 1));
		}
	}
	inline int maxv(int o) {return kth(o, sz[o]);}
}
*/
//#define DBG
void build(int u, int p) {
	h = t = 0;
	pre[q[t++] = u] = 0;
	while (h < t) {
		int u = q[h++];
		sz[u] = 1;
		for (int i = 0, v; i < (int)to[u].size();i++) if (!vis[v = to[u][i]] && v != pre[u])
			pre[q[t++] = v] = u;
	}
	for (int i = t - 1; ~i; i--) sz[pre[q[i]]] += sz[q[i]];
	int size = sz[u];
	for (int flag = 1; flag; ) {
		flag = 0;
		for (int i = 0, v; i < (int)to[u].size(); i++) if (!vis[v = to[u][i]] && v != pre[u] && sz[v] > size/2) {
			u = v;
			flag = 1;
			break;
		}
	}
#ifdef DBG
	printf("%d: ", u);
	for (int i = 0; i < t; i++) printf("%d ", q[i]);
	putchar('\n');
#endif
	vis[u] = 1;
	fa[u] = p;
//	ch[fa[u]].push_back(u);
	for (int i = 0, v; i <(int)to[u].size(); i++) if (!vis[v = to[u][i]]) build(v, u);
}
void dfs(int u) {
	for (int i = 1; i < K; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for (int i = 0, v; i < (int)to[u].size(); i++) if ((v = to[u][i]) != anc[u][0]) {
		anc[v][0] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}
inline int lca(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u, v);
	for (int x = dep[u] - dep[v], i = 0; x; x>>=1, i++) if (x&1) u = anc[u][i];
	for (int i = K - 1; ~i; i--) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	return u == v ? u : anc[u][0]; 
}
inline int gdis(int u, int v) {return dep[u] + dep[v] - 2*dep[lca(u, v)];}
char cmd[100];
void print() {
#ifdef DBG
	for (int i = 1; i <= n; i++) {
		printf("%d : all nodes to parent : %d\t all nodes to itself %d --> %d\n", i, hp[i].top(), hp2[i].top(), hp2[i].mt());
	}
	printf("global: %d\n", gl.top());
	puts("");
#endif
}
void change(int u) {
	if (off[u]) nc--;
	else nc++;
	for (int x = u; fa[x]; x = fa[x]) {
		int bef = hp[x].top();
		hp[x].change(gdis(u, fa[x]), off[u]);
		int aft = hp[x].top();
		if (bef != aft) {
			int bef2 = hp2[fa[x]].mt();
			if (bef != -1) hp2[fa[x]].change(bef, 1);
			if (aft != -1) hp2[fa[x]].change(aft, 0);
			int aft2 = hp2[fa[x]].mt();
			if (bef2 != aft2) {
				if (bef2 != -1) gl.change(bef2, 1);
				if (aft2 != -1) gl.change(aft2, 0);
			}
		}
	}
	off[u] ^= 1;
}
int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i=1, u, v; i < n; i++) scanf("%d%d", &u, &v), to[u].push_back(v), to[v].push_back(u);
	build(1, 0);
	dfs(1);
#ifdef DBG
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) printf("%d - %d : %d\n", i, j, gdis(i, j));
#endif
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) change(i), print();
	print();
	while (m--) {
		scanf("%s", cmd);
		if (cmd[0] == 'C') {
			int u;scanf("%d", &u);
			change(u);
		}
		else {
			if (nc <= 1) printf("%d\n", nc == 1 ? 0 : -1);
			else printf("%d\n", gl.top());
		}
	}
}
